#include "../../include/blink_api/stubs/AInputStub.h"
#include "../../include/blink_api/abstractions/ALogger.h"

std::string AInputStub::get_input( const std::string& message = ": " ) {
    if ( m_logger ) {
        m_logger->log( "AInputStub::get_input was called", LOG_LEVEL::DEBUG );
    }
	std::string hendle_input = "";

    if ( m_logger ) {
        m_logger->log( "AInputStub::get_input called with message: " + message, LOG_LEVEL::TRACE );
    }
	std::cin >> hendle_input;

    if ( m_logger ) {
        m_logger->log( "AInputStub::get_input hendle_input is: " + hendle_input, LOG_LEVEL::TRACE );
    }
	return hendle_input;
}
