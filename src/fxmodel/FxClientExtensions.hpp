/**
 * FxClientExtensions.h
 *
 * A ClientExtensions object allows a client to attach a clientID, tag and comment to Orders and Trades in their Account.  Do not set, modify, or delete this field if your account is associated with MT4.
 *
 **/

#ifndef FxClientExtensions_H_
#define FxClientExtensions_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
namespace fxmodel {

SERIAL_CLASS(FxClientExtensions, ("ClientExtensions"), //
    (id, std::string, "id"),
    (tag, std::string, "tag"),
    (comment, std::string, "comment")
);

} // namespace fxmodel

#endif /* FxClientExtensions_H_ */
