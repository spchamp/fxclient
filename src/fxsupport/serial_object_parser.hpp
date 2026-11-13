// primary serialization support for SerialObject types

#pragma once

#include <exception>
#include <boost/mpl/at.hpp>
#include <fxsupport/SerialObject.hpp>

#include <rfl/Result.hpp>
#include <rfl/get.hpp>
#include <rfl/parsing/Parser.hpp>
#include <rfl/parsing/AreReaderAndWriter.hpp>
#include <tuple>

/// @brief custom parser for SerialObject subclasses
//
// This partial specialization of the reflect-cpp Parser type
// will serve to provide some functional shortcuts for
// serialization and derialization of SerialObject subclasses
//
// Internally, this uses an rfl::NamedTuple type specific to the
// SerialObject subclass. An object of this type will be created
// for the duration of each successful read() or write() call under
// this parser specialization.
//
template <class Rdr, class Wrt, class Impl, class ProcessorsType>
    requires (rfl::parsing::AreReaderAndWriter<Rdr, Wrt, Impl>
              && fxsupport::serial_object<Impl>)
struct rfl::parsing::Parser<Rdr, Wrt, Impl, ProcessorsType> {

    using serial_type      = typename Impl::_serial_fields_type;

    using class_type       = Impl;

    // Result type for read()
    //
    // This type should be generally compatible with most format-specific parsers
    // in reflect-cpp.
    using read_result_type = rfl::Result<class_type>;

    // Type of the intermediate named tuple parser used in read()
    using serial_reader_type =
          rfl::parsing::Parser<Rdr, Wrt, serial_type, ProcessorsType>;

    // The serial_result_type is returned from the intermediate serial_reader_type
    // within read().
    //
    // Values of this type will be consumed immediately, using the function
    // to_read_result()
    //
    using serial_result_type = rfl::Result<serial_type>;

    static constexpr auto field_index =
          std::make_index_sequence<Impl::_field_count>();

    // in the interest of caching, this uses a series of static functor objects

    template <std::size_t Index>
    struct inner_read_functor {
        // using field_t = typename boost::mpl::at_c<typename
        // decltype(Impl::_fields)::field_types, Index>::type;

        using field_t =
              std::tuple_element_t<Index,
                                   typename decltype(Impl::_fields)::field_types>;

        static constexpr field_t field = std::get<Index>(Impl::_fields.fields);

        void operator()(class_type& that, serial_type&& serial) const
        /* noexcept */ {
            auto& optv = rfl::get<Index>(std::forward<serial_type>(serial));
            if (optv.has_value()) {
                field.emplace_serialized(that, std::move(optv).value());
            }
        }
    };

    struct outer_read_functor {
        static constexpr auto functor_cache =
              []<std::size_t... N>(std::index_sequence<N...> const&) noexcept {
                  return std::make_tuple(inner_read_functor<N>{}...);
              }(field_index);

        void operator()(class_type& that, serial_type&& serial) const
        /* noexcept */ {
            static constexpr auto fn =
                  []<std::size_t... N>(class_type& that, serial_type&& serial,
                                       std::index_sequence<N...> const&) noexcept {
                      (std::get<N>(functor_cache)(
                             that, std::forward<serial_type>(serial)),
                       ...);
                  };
            fn(that, std::forward<serial_type>(serial), field_index);
        }
    };

    static read_result_type
          to_read_result(serial_result_type&& tmp) /* noexcept */ {
        static constexpr outer_read_functor functor{};

        if (std::forward<serial_result_type>(tmp).has_value()) {
            Impl that{};
            functor(that, std::move(tmp).value());
            return that;
        }
        return rfl::Unexpected(std::move(tmp).error());
    }

    /// @brief construct a temporary rfl::NamedTuple from the deserialialized
    /// temporary object sv, then initialize an instance of the Impl class using
    /// the named tuple.
    ///
    /// This overload will be applied for a format-specific parser type, such that
    /// would support an RValue reference to the reader's intermediate InputVarType
    /// for this parsing operation.
    ///
    /// This is believed to be generally supported with the JSON parser, and may be
    /// supported with other formats as well.
    ///
    static read_result_type read(Rdr const&                   rdr,
                                 typename Rdr::InputVarType&& sv) noexcept {
        try {
            // The read() may throw.
            //
            // If it does not throw, then this assumnes that the return value
            // from read() can be transformed without exception.
            return to_read_result(serial_reader_type::read(rdr, std::move(sv)));
        } catch (std::exception const& ex) {
            std::string msg{"When parsing "};
            msg = msg.append(Impl::get_type_name()).append(": ").append(ex.what());
            return rfl::error(std::move(msg));
        }
    }

    /// @brief construct a temporary rfl::NamedTuple from the deserialialized
    /// temporary object sv, then initialize an instance of the Impl class using
    /// the named tuple.
    ///
    /// This overload will be applied for any format-specific parser, such that
    /// would not support an RValue reference to the reader's intermediate
    /// InputVarType for this parsing operation.
    ///
    static read_result_type read(Rdr const&                        rdr,
                                 typename Rdr::InputVarType const& sv) noexcept {
        try {
            // the read() may throw
            return to_read_result(serial_reader_type::read(rdr, sv));
        } catch (std::exception const& ex) {
            std::string msg{"When parsing "};
            msg = msg.append(Impl::get_type_name()).append(": ").append(ex.what());
            return rfl::error(std::move(msg));
        }
    }

    /// @brief generate an rfl::NamedTuple for the object 'self', then write the
    /// named tuple with a corresponding parser
    ///
    /// This uses Impl::named_tuple_view(), such that should provide any calls
    // to ModelProcessor::deserialize for each corresponding field ...
    template <typename WriteProc>
    static void write(Wrt const& wrt, Impl const& self, WriteProc const& proc) {
        using serial_writer =
              rfl::parsing::Parser<Rdr, Wrt, serial_type, WriteProc>;

        // the write() may throw.
        //
        // Any exception from here would need to be caught at the entry point
        // to the write() tree, then handled there.
        //
        // FIXME "wrapped exceptions" ? may be theoretically ideal for debugging ...
        serial_writer::write(wrt, self.named_tuple_view(), proc);
    }
};
