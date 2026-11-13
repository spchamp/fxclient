#pragma once

#include <boost/parameter/aux_/use_default.hpp>
#include <boost/parameter/optional.hpp>
#include <boost/parameter/required.hpp>

#include <coapp/lib/LText.hpp>
#include <coapp/lib/param/parameter.hpp>
#include <coapp/lib/param/param_traits.hpp>
#include <fxsupport/MemberField.hpp>

#include <rfl/Field.hpp>

#include <coapp/lib/tparam/tparameter.hpp>

#include <fxsupport/SerialTransform.hpp>

namespace fxsupport {

using namespace coapp::lib;
using coapp::lib::param::parameter;
using coapp::lib::param::argument_pack;
using coapp::lib::param::param_unspecified;


template <typename T, LText Name, typename Cls, typename... Param>
    requires (detail::transformable_from_params<T, Param...>)
struct NamedField : MemberField<Cls, T, Param...> {
    using base_type         = MemberField<Cls, T, Param...>;
    using member_type       = typename base_type::member_type;  // mem_fn
    using text_type         = decltype(Name);
    using class_type        = typename base_type::class_type;

    /// @brief type sequence denoting all provided `Param...`
    using field_param_types = typename mpl::vector<Param...>::type;

    template <typename P, typename Default>
    using optional_param_t =
          typename tparam::tparameter_optional<P, Default, Param...>::type;

    template <typename P>
    using required_param_t =
          typename tparam::tparameter_required<P, Param...>::type;

    template<typename U>
    static constexpr bool param_present = tparam::tparameter_present_v<U, Param...>;

    /// @brief valuegenerally equivalent to the type `T`
    using value_type  = typename base_type::value_type;
    /// the type of values stored for this field, within instances
    /// of the `class_type`
    using stored_type = std::optional<value_type>;

    /// @brief serialized value type
    ///
    /// This type is resolved using template parameter constructs from
    /// from boost parameter.
    //
    /// When a template type `field_param::serial_type::assign<T>` is
    /// present in the types `Param...`, then this type will be equivalent to
    /// the type `T` provided in that `serial_type::assign` parameter template.
    /// For purposes of serialization, this should generally be acompanied
    /// with with definition of a partial specialization of the
    /// `SerialTransform` type, generally compatible with  a type
    /// signature `SerialTransform<value_type, T>. This partial specialization
    /// will be denoted here as `U`. This type `U` should provide static
    /// methods of a form `U::to_stored(T) -> value_type` and
    /// `U::to_serial(value_type) -> T`. (These methods may be implemented
    /// with overloads for rvalue references and/or const lvalue references
    /// onto the arg, respectively of general type `T` or `value_type`, and
    /// should generally be defined as 'noexcept`)
    ///
    /// By default, this type will be equivalent to `value_type`
    ///
    /// @see the `transform_type` member type

    using serial_value_type =
          typename tparam::tparameter_optional<field_param::serial_type, value_type,
                                               Param...>::type;

    /// @brief std::optional wrapper type for the `serialilzed_value_type`
    /// FIXME provide a "flag" type `no_optional` for Param... to specify
    /// that this type would be equivalent to serial_value_type,
    /// (and similar for stored_value_type) w/ no nullopt values in that case
    using serial_stored_type = std::optional<serial_value_type>;

    /// @brief type for the reflect-cpp serialized form of this field
    ///
    /// The `serial_field_type` will be used for purposes of intermediate
    /// value storage, mainly during operations for serialization and
    /// deserialization of values of this field, within some containing
    /// structured type. This generalized field type will be applied
    /// within each format-specific reader/writer in reflect-cpp.
    using serial_field_type  = rfl::Field<Name.data, serial_stored_type>;

    /// @brief utility type for transformation between the `value_type`
    /// and the `serial_value_type`, for any non-nullopt field value
    ///
    using transform_type     = SerialTransform<value_type, serial_value_type>;

    /// @brief the field's provided `Name`
    static constexpr text_type const name = Name;


    /// @brief constructor
    ///
    /// @param member_type mb This object should generally be valid as an
    /// argument to `std::mem_fn`, as denoting a non-static data member
    /// of the `class_type`.
    ///
    /// If the corresponding data member is declared  as `const` then this
    /// field is effectively "read only".
    ///
    /// Known limitation: If the corresponding field is declared as `const`,
    /// then deserialization through the `Fields` interface would fail for
    /// the corresponding `class_type` ... short of any parameter-based construction
    /// mechanism for a SerialObject, such that each parameter could be selected
    /// and provided with a corresponding deserialized value, at runtime.
    constexpr NamedField(member_type mb) noexcept
        : base_type(mb) {}

    /// @brief callback for the SerialObject parser
    ///
    /// rvalue overload, for the case of equivalent _stored_ and _serial_
    /// value types
    ///
    /// This function moves the `optional` object from the provided `field`
    void emplace_serialized(class_type&         self,
                            serial_field_type&& field) const noexcept
        requires (std::is_same_v<stored_type, serial_stored_type>) {
        return this->set(self, std::move(field).value());
    }

    /// @brief callback for the SerialObject parser
    ///
    /// const lvalue overload, for the case of equivalent _stored_ and _serial_
    /// value types
    //
    /// This function copies the `optional` object from the provided `field`
    void emplace_serialized(class_type&              self,
                            serial_field_type const& field) const noexcept
        requires (std::is_same_v<stored_type, serial_stored_type>) {
        return this->set(self, field.value());
    }

    /// @brief callback for the SerialObject parser
    ///
    /// rvalue overload for the case of non-equivalent _stored_ and _serial_
    /// value types
    ///
    /// This overload will use the `transform_type` internally, to produce a
    /// `stored_type` value from any non-nullopt `serial_type` value within the
    /// provided (rvalue) `field`. This transformation will be provided mainly via
    /// a static `to_stored` function in the `transform_type`. The resulting
    /// stored-type value will then be emplaced within the corresponding field data
    /// member for the instance `self`.
    ///
    /// Alternately, if there is no stored value for the `field`, then any value
    /// within the corresponding field data member will be cleared/reset.
    void emplace_serialized(class_type&         self,
                            serial_field_type&& field) const /* noexcept */
        requires (!std::is_same_v<stored_type, serial_stored_type>) {
        serial_stored_type fv = std::move(field).value();
        if (fv.has_value()) {
            this->emplace(self, transform_type::to_stored(std::move(fv).value()));
        } else {
            this->clear(self);
        }
    }

    /// @brief callback for the SerialObject parser
    ///
    /// const lvalue overload for the case of non-equivalent _stored_ and
    /// _serial_ value types.
    ///
    /// This overload will use the `transform_type` internally, to produce a
    /// `stored_type` value from any non-nullopt `serial_type` value within the
    /// provided (const lvalue) `field`. This transformation will be provided mainly
    /// via a static `to_stored` function in the `transform_type`. The resulting
    /// stored-type value will then be emplaced within the corresponding field data
    /// member for the instance `self`.
    ///
    /// Alternately, if there is no stored value for the `field`, then any value
    /// within the corresponding field data member will be cleared/reset.
    void emplace_serialized(class_type&              self,
                            serial_field_type const& field) const /* noexcept */
        requires (!std::is_same_v<stored_type, serial_stored_type>) {
        serial_stored_type const& fv = field.value();
        if (fv.has_value()) {
            this->emplace(self, transform_type::to_stored(fv.value()));
        } else {
            this->clear(self);
        }
    }
    
    // FIXME used at least under the "alt reflection" impl
    auto serial_value(class_type const& self) const noexcept -> serial_stored_type {

        stored_type const& fv = this->get(self);
        if (fv.has_value()) {
            /// initially
            // return fv.value();
            //// try
            return transform_type::to_serial(fv.value());
        }
        return std::nullopt;
    }
};

template <typename T>
concept is_named_field =
      requires (T that) {
          []<typename U, LText Name, typename Cls, typename... Param>(
                NamedField<U, Name, Cls, Param...>) {
          }(that);
      };

}  // namespace fxsupport
