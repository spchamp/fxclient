#pragma once

#include <functional>
#include <optional>

#include <boost/asio/any_completion_handler.hpp>
#include <boost/asio/any_io_executor.hpp>
#include <boost/asio/async_result.hpp>
#include <boost/mpl/vector.hpp>

namespace fxsupport {

namespace asio = boost::asio;
namespace mpl  = boost::mpl;

template <typename Cls, typename T, typename... Param>
struct MemberField {

    using class_type  = Cls;
    using value_type  = T;
    using result_type = std::optional<T>;
    using param_type  = typename mpl::vector<Param...>::type;

    using member_type = result_type class_type::*;
    using memfn_type  = decltype(std::mem_fn(std::declval<member_type>()));

protected:
    memfn_type mfn;

public:
    constexpr MemberField(member_type mb) noexcept
        : mfn(std::mem_fn(mb)) {};

    bool has_value(class_type const& s) const noexcept {
        return mfn(s).has_value();
    }

    bool has_value(class_type const* s) const noexcept {
        return mfn(s).has_value();
    }

    // generally for a smart pointer to class_type
    template <typename Self>
        requires (requires (memfn_type fn, Self& s) { fn(s); })
    bool has_value(Self const& s) const noexcept {
        return mfn(s).has_value();
    }

    result_type&       get(class_type& s) const noexcept { return mfn(s); }

    result_type const& get(class_type const& s) const noexcept { return mfn(s); }

    result_type&       get(class_type* s) const noexcept { return mfn(s); }

    result_type const& get(class_type const* s) const noexcept { return mfn(s); }

    // generally for a smart pointer to class_type
    template <typename Self>
        requires (requires (memfn_type fn, Self& s) { fn(s); })
    result_type& get(Self& s) const noexcept {
        return mfn(s);
    }

    template <typename U>
        requires (requires (memfn_type fn, class_type& s, U&& v) { fn(s) = v; })
    void set(class_type& s, U&& value) const
          noexcept(std::is_nothrow_assignable_v<result_type&, U&&>) {
        mfn(s) = std::forward<U>(value);
    }

    template <typename U>
        requires (requires (memfn_type fn, class_type* s, U&& v) { fn(s) = v; })
    void set(class_type* s, U&& value) const
          noexcept(std::is_nothrow_assignable_v<result_type&, U&&>) {
        mfn(s) = std::forward<U>(value);
    }

    template <typename U>
        requires (requires (memfn_type fn, class_type& s, U const& v) {
                      fn(s) = v;
                  })
    void set(class_type& s, std::optional<U> const& value) const
          noexcept(std::is_nothrow_assignable_v<result_type&, U const&>) {
        mfn(s) = value;
    }

    template <typename Self, typename U>
        requires (requires (memfn_type fn, Self& s, U&& v) { fn(s) = v; })
    void set(Self& s, U&& value) const
          noexcept(std::is_nothrow_assignable_v<result_type&, U&&>) {
        mfn(s) = std::forward<U>(value);
    }

    template <typename Self, typename U>
        requires (requires (memfn_type fn, Self& s, U const& v) { fn(s) = v; })
    void set(Self& s, U const& value) const
          noexcept(std::is_nothrow_assignable_v<result_type&, U const&>) {
        mfn(s) = std::forward<U>(value);
    }

    template <typename... Arg>
        requires (requires (memfn_type fn, class_type& s, Arg&&... arg) {
                      fn(s).emplace(std::forward<Arg>(arg)...);
                  })
    void emplace(class_type& s, Arg&&... arg) const
          noexcept(std::is_nothrow_constructible_v<value_type, Arg&&...>) {
        mfn(s).emplace(std::forward<Arg>(arg)...);
    }

    template <typename... Arg>
        requires (requires (memfn_type fn, class_type* s, Arg&&... arg) {
                      fn(s).emplace(std::forward<Arg>(arg)...);
                  })
    void emplace(class_type* s, Arg&&... arg) const
          noexcept(std::is_nothrow_constructible_v<value_type, Arg&&...>) {
        mfn(s).emplace(std::forward<Arg>(arg)...);
    }

    template <typename... Arg>
        requires (requires (memfn_type fn, class_type& s, Arg const&... arg) {
                      fn(s).emplace(arg...);
                  })
    void emplace(class_type& s, Arg const&... arg) const
          noexcept(std::is_nothrow_constructible_v<value_type, Arg const&...>) {
        mfn(s).emplace(arg...);
    }

    template <typename Self, typename... Arg>
        requires (requires (memfn_type fn, Self& s, Arg&&... arg) {
                      fn(s).emplace(std::forward<Arg>(arg)...);
                  })
    void emplace(Self& s, Arg&&... arg) const
          noexcept(std::is_nothrow_constructible_v<value_type, Arg&&...>) {
        mfn(s).emplace(std::forward<Arg>(arg)...);
    }

    template <typename Self, typename... Arg>
        requires (requires (memfn_type fn, Self& s, Arg const&... arg) {
                      fn(s).emplace(arg...);
                  })
    void emplace(Self& s, Arg const&... arg) const
          noexcept(std::is_nothrow_constructible_v<value_type, Arg const&...>) {
        mfn(s).emplace(arg...);
    }

    void clear(class_type& s) const noexcept { mfn(s).reset(); }

    void clear(class_type* s) const noexcept { mfn(s).reset(); }

    /// implementation note: these Self functions are generally for
    /// accepting a smart pointer to the class_type

    template <typename Self>
        requires (requires (memfn_type fn, Self& s) { fn(s).reset(); })
    void clear(Self& s) const noexcept {
        mfn(s).reset();
    }

    /// visit() support ... for individual fields (prototype)
    /// in a style of an async function
    ///
    /// this does not require an executor and will always complete
    /// immediately
protected:
    // FIXME specialize also for some Self*
    template <typename Self>
    static inline void visit_impl(
          asio::any_completion_handler<void(value_type*, bool)>&& handler,
          Self inst, MemberField const* field) noexcept {
        result_type optv = field->mfn(inst);
        if (optv.has_value()) {
            std::move(handler)(&optv.value(), true);
        } else {
            std::move(handler)(nullptr, false);
        }
    }

public:
    template <typename CompletionToken>
    auto visit(class_type& inst, CompletionToken&& token) noexcept
          -> decltype(asio::async_initiate<CompletionToken,
                                           void(value_type*, bool)>(
                &visit_impl<class_type&>, token, inst, this)) {
        return asio::async_initiate<CompletionToken, void(value_type*, bool)>(
              &visit_impl<class_type&>, token, inst, this);
    }
};

template <typename Cls, typename T>
auto make_member_field(std::optional<T> Cls::* mb) -> MemberField<Cls, T> {
    return MemberField<Cls, T>{mb};
}

template <typename Cls, typename T, template <typename...> typename Tmpl,
          typename... Param>
auto make_member_field(std::optional<T> Cls::* mb, Tmpl<Param...>)
      -> MemberField<Cls, T, Param...> {
    return MemberField<Cls, T, Param...>{mb};
}


}  // namespace fxsupport
