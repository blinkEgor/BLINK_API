#include "../../include/blink_api/stubs/ScriptEngineStub.h"
#include "../../include/blink_api/abstractions/ALogger.h"
#include <iostream>

void ScriptEngineStub::init() {
    if ( m_logger ) {
        m_logger->log( "ScriptEngineStub::init() called (no script engine connected)", LOG_LEVEL::DEBUG );
    }
}

void ScriptEngineStub::update() {
    if ( m_logger ) {
        m_logger->log( "ScriptEngineStub::update() called (no script logic)", LOG_LEVEL::TRACE );
    }
}

void ScriptEngineStub::exit() {
    if ( m_logger ) {
        m_logger->log( "ScriptEngineStub::exit() called (no cleanup required)", LOG_LEVEL::DEBUG );
    }
}
