/**
 * FxUserInfo.h
 *
 * A representation of user information, as provided to the user themself.
 *
 **/

#ifndef FxUserInfo_H_
#define FxUserInfo_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
namespace fxmodel {

SERIAL_CLASS(FxUserInfo, ("UserInfo"), //
    (username, std::string, "username"),
    (userID, std::uint32_t, "userID"),
    (country, std::string, "country"),
    (emailAddress, std::string, "emailAddress")
);

} // namespace fxmodel

#endif /* FxUserInfo_H_ */
