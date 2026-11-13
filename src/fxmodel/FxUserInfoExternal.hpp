/**
 * FxUserInfoExternal.h
 *
 * A representation of user information, as available to external (3rd party) clients.
 *
 **/

#ifndef FxUserInfoExternal_H_
#define FxUserInfoExternal_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
namespace fxmodel {

SERIAL_CLASS(FxUserInfoExternal, ("UserInfoExternal"), //
    (userID, std::uint32_t, "userID"),
    (country, std::string, "country"),
    (FIFO, bool, "FIFO")
);

} // namespace fxmodel

#endif /* FxUserInfoExternal_H_ */
