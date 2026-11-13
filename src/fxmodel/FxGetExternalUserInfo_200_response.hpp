/**
 * FxGetExternalUserInfo_200_response.h
 *
 **/

#ifndef FxGetExternalUserInfo_200_response_H_
#define FxGetExternalUserInfo_200_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxUserInfoExternal.hpp>

namespace fxmodel {

SERIAL_CLASS(FxGetExternalUserInfo_200_response, ("GetExternalUserInfo_200_response"), //
    (userInfo, fxmodel::FxUserInfoExternal, "userInfo")
);

} // namespace fxmodel

#endif /* FxGetExternalUserInfo_200_response_H_ */
