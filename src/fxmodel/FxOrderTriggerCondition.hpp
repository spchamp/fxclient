/**
 * FxOrderTriggerCondition.h
 *
 * Specification of which price component should be used when determining if an Order should be triggered and filled. This allows Orders to be triggered based on the bid, ask, mid, default (ask for buy, bid for sell) or inverse (ask for sell, bid for buy) price depending on the desired behaviour. Orders are always filled using their default price component. This feature is only provided through the REST API. Clients who choose to specify a non-default trigger condition will not see it reflected in any of OANDA's proprietary or partner trading platforms, their transaction history or their account statements. OANDA platforms always assume that an Order's trigger condition is set to the default value when indicating the distance from an Order's trigger price, and will always provide the default trigger condition when creating or modifying an Order. A special restriction applies when creating a guaranteed Stop Loss Order. In this case the TriggerCondition value must either be \&quot;DEFAULT\&quot;, or the \&quot;natural\&quot; trigger side \&quot;DEFAULT\&quot; results in. So for a Stop Loss Order for a long trade valid values are \&quot;DEFAULT\&quot; and \&quot;BID\&quot;, and for short trades \&quot;DEFAULT\&quot; and \&quot;ASK\&quot; are valid.
 *
 **/

#ifndef FxOrderTriggerCondition_H_
#define FxOrderTriggerCondition_H_

#include <fxsupport/serial_enum.hpp>
#include <fxsupport/SerialEnum.hpp>
#include <cstdint>

namespace fxmodel {

SERIAL_ENUM(FxOrderTriggerCondition, (std::uint_fast8_t, "OrderTriggerCondition"), //
    (DEFAULT, static_cast<std::uint_fast8_t>(1)<<0, "DEFAULT"),
    (INVERSE, static_cast<std::uint_fast8_t>(1)<<1, "INVERSE"),
    (BID, static_cast<std::uint_fast8_t>(1)<<2, "BID"),
    (ASK, static_cast<std::uint_fast8_t>(1)<<3, "ASK"),
    (MID, static_cast<std::uint_fast8_t>(1)<<4, "MID")
);

} // namespace fxmodel
#endif /* FxOrderTriggerCondition_H_ */
