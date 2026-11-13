/**
 * FxGetUserInfo_200_response.h
 *
 **/

#ifndef FxGetUserInfo_200_response_H_
#define FxGetUserInfo_200_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxUserInfo.hpp>

namespace fxmodel {

SERIAL_CLASS(FxGetUserInfo_200_response, ("GetUserInfo_200_response"), //
    (userInfo, fxmodel::FxUserInfo, "userInfo")
);

} // namespace fxmodel

#endif /* FxGetUserInfo_200_response_H_ */
