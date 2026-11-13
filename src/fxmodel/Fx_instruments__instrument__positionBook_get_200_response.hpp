/**
 * Fx_instruments__instrument__positionBook_get_200_response.h
 *
 **/

#ifndef Fx_instruments__instrument__positionBook_get_200_response_H_
#define Fx_instruments__instrument__positionBook_get_200_response_H_

#include <fxsupport/serial_class.hpp>
#include <fxsupport/Fields.hpp>
#include <fxsupport/NamedField.hpp>
#include <fxsupport/SerialObject.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxmodel/FxPositionBook.hpp>

namespace fxmodel {

SERIAL_CLASS(Fx_instruments__instrument__positionBook_get_200_response, ("_instruments__instrument__positionBook_get_200_response"), //
    (positionBook, fxmodel::FxPositionBook, "positionBook")
);

} // namespace fxmodel

#endif /* Fx_instruments__instrument__positionBook_get_200_response_H_ */
