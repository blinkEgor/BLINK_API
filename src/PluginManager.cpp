#include "../include/blink_api/PluginManager.h"
#include "../include/blink_api/abstractions/ALogger.h"
#include <iostream>

void PluginManager::load_plugins() {
    if ( m_logger ) {
        m_logger->log( "PluginManager::load_plugins() called", LOG_LEVEL::TRACE );
    }
    else { std::cerr << "[TRACE] PluginManager::load_plugins() called" << std::endl; }
}

void PluginManager::unload_plugins() {
    if ( m_logger ) {
        m_logger->log( "PluginManager::unload_plugins() called", LOG_LEVEL::TRACE );
    }
    else { std::cerr << "[TRACE] PluginManager::unload_plugins() called" << std::endl; }
}
