#include "../../include/blink_api/stubs/ParserStub.h"
#include "../../include/blink_api/abstractions/ALogger.h"
#include <iostream>

std::unordered_map<std::string, std::string> stub_map = { { "stub_key", "stub_value" } };

bool ParserStub::load_from_file( const std::string& path ) {
    if ( m_logger ) {
        m_logger->log( "Passed path to load file: " + path, LOG_LEVEL::DEBUG );
    }
    if ( path.empty() ) {
        if ( m_logger ) {
            m_logger->log( "Load from file failed - empty path", LOG_LEVEL::WARNING );
        }
        return false;
    }
    return true;
}

bool ParserStub::save_to_file( const std::string& path ) const {
    if ( m_logger ) {
        m_logger->log( "Passed path to save file: " + path, LOG_LEVEL::DEBUG );
    }
    if ( path.empty() ) {
        if ( m_logger ) {
            m_logger->log( "Save to file failed - empty path", LOG_LEVEL::WARNING );
        }
        return false;
    }
    return true;
}

std::string ParserStub::get( const std::string& key, const std::string& fallback ) const {
    if ( m_logger ) {
        m_logger->log( "Get key: " + key + ", fallback: " + fallback, LOG_LEVEL::DEBUG );
    }
    return ( key + " = " + fallback );
}

void ParserStub::set( const std::string& key, const std::string& value ) {
    if ( m_logger ) {
        m_logger->log( "Set key: " + key + ", value: " + value, LOG_LEVEL::DEBUG );
    }
}

std::unordered_map<std::string, std::string> ParserStub::get_all() const {
    if ( m_logger ) {
        m_logger->log( "Get all key=value pairs from unordered_map", LOG_LEVEL::DEBUG );
    }
    return stub_map;
}
