/**
 * FxCalculatedTradeState.h
 *
 * The dynamic (calculated) state of an open Trade
 *
 **/

#ifndef FxCalculatedTradeState_H_
#define FxCalculatedTradeState_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
namespace fxmodel {

SERIAL_CLASS(FxCalculatedTradeState, ("CalculatedTradeState"), //
    (id, std::string, "id"),
    (unrealizedPL, std::string, "unrealizedPL"),
    (marginUsed, std::string, "marginUsed")
);

} // namespace fxmodel

#endif /* FxCalculatedTradeState_H_ */
