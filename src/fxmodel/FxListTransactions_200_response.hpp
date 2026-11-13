/**
 * FxListTransactions_200_response.h
 *
 **/

#ifndef FxListTransactions_200_response_H_
#define FxListTransactions_200_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxTransactionType.hpp>

namespace fxmodel {

SERIAL_CLASS(FxListTransactions_200_response, ("ListTransactions_200_response"), //
    (from, std::string, "from"),
    (to, std::string, "to"),
    (pageSize, std::uint32_t, "pageSize"),
    (type, std::vector<fxmodel::FxTransactionType>, "type"),
    (count, std::uint32_t, "count"),
    (pages, std::vector<std::string>, "pages"),
    (lastTransactionID, std::string, "lastTransactionID")
);

} // namespace fxmodel

#endif /* FxListTransactions_200_response_H_ */
