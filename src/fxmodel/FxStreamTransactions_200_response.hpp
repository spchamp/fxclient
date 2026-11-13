/**
 * FxStreamTransactions_200_response.h
 *
 * The response body for the Transaction Stream uses chunked transfer encoding.  Each chunk contains Transaction and/or TransactionHeartbeat objects encoded as JSON.  Each JSON object is serialized into a single line of text, and multiple objects found in the same chunk are separated by newlines. TransactionHeartbeats are sent every 5 seconds.
 *
 **/

#ifndef FxStreamTransactions_200_response_H_
#define FxStreamTransactions_200_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxTransactionHeartbeat.hpp>
#include <fxmodel/FxTransaction.hpp>

namespace fxmodel {

SERIAL_CLASS(FxStreamTransactions_200_response, ("StreamTransactions_200_response"), //
    (transaction, fxmodel::FxTransaction, "transaction"),
    (heartbeat, fxmodel::FxTransactionHeartbeat, "heartbeat")
);

} // namespace fxmodel

#endif /* FxStreamTransactions_200_response_H_ */
