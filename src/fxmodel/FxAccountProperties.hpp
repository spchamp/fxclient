/**
 * FxAccountProperties.h
 *
 * Properties related to an Account.
 *
 **/

#ifndef FxAccountProperties_H_
#define FxAccountProperties_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
namespace fxmodel {

SERIAL_CLASS(FxAccountProperties, ("AccountProperties"), //
    (id, std::string, "id"),
    (mt4AccountID, std::uint32_t, "mt4AccountID"),
    (tags, std::vector<std::string>, "tags")
);

} // namespace fxmodel

#endif /* FxAccountProperties_H_ */
