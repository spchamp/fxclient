/**
 * FxPositionFinancing.h
 *
 * OpenTradeFinancing is used to pay/collect daily financing charge for a Position within an Account
 *
 **/

#ifndef FxPositionFinancing_H_
#define FxPositionFinancing_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxOpenTradeFinancing.hpp>

namespace fxmodel {

SERIAL_CLASS(FxPositionFinancing, ("PositionFinancing"), //
    (instrument, std::string, "instrument"),
    (financing, std::string, "financing"),
    (openTradeFinancings, std::vector<fxmodel::FxOpenTradeFinancing>, "openTradeFinancings")
);

} // namespace fxmodel

#endif /* FxPositionFinancing_H_ */
