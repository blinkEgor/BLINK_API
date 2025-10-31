#include "../../include/blink_api/stubs/AScriptEngineStub.h"
#include "../../include/blink_api/abstractions/ALogger.h"
#include <iostream>

void AScriptEngineStub::init() {
    if ( m_logger ) {
        m_logger->log( "AScriptEngineStub::init() called (no script engine connected)", LOG_LEVEL::DEBUG );
    }
}

void AScriptEngineStub::update() {
    if ( m_logger ) {
        m_logger->log( "AScriptEngineStub::update() called (no script logic)", LOG_LEVEL::TRACE );
    }
}

void AScriptEngineStub::exit() {
    if ( m_logger ) {
        m_logger->log( "AScriptEngineStub::exit() called (no cleanup required)", LOG_LEVEL::DEBUG );
    }
}
