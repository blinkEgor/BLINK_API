#include "../../include/blink_api/fakes/AParserFake.h"	// <string> | <unordered_map>
#include "../../include/blink_api/abstractions/ALogger.h"
#include <iostream>
#include <fstream>	// для std::ifstream
#include <sstream>	// для std::istringstream

bool AParserFake::load_from_file( const std::string& path = "configs/api_plugins/default_plugin.conf" ) {
    if ( m_logger ) {
        m_logger->log( "Loading config from: " + path, LOG_LEVEL::DEBUG );
    }
	std::ifstream file( path );

	if ( !file.is_open() ) {
        if ( m_logger ) {
            m_logger->log( "Failed to open config: " + path, LOG_LEVEL::ERROR );
        }
		return false;
	}

	std::string current_key;
	std::string current_value;

	std::string line;
	while ( std::getline( file, line ) ) {
		if ( line.empty() || line[0] == '#' ) continue;

		if ( !current_key.empty() ) {
			config_map[ current_key ] = current_value;
            if ( m_logger ) {
                m_logger->log( "Parsed config [" + current_key + "] = " + current_value, LOG_LEVEL::DEBUG );
            }
			current_key = "";
			current_value = "";
		}

		std::istringstream iss( line );
		std::string key, eq, value;

		if ( !( iss >> key >> eq ) ) continue;

		std::getline( iss, value );

		value.erase( 0, value.find_first_not_of( " \t" ) );
		value.erase( value.find_last_not_of( " \t" ) + 1 );

		if ( eq != "=" ) continue;


        if ( m_logger ) {
            m_logger->log( "Found config key: " + key, LOG_LEVEL::DEBUG );
        }
		current_key = key;
		current_value = value;
	}

	if ( !current_key.empty() ) {
		config_map[ current_key ] = current_value;
        if ( m_logger ) {
            m_logger->log( "Parsed config [" + current_key + "] = " + current_value, LOG_LEVEL::DEBUG );
        }
		current_key = "";
		current_value = "";
	}

	return true;
}

std::string AParserFake::get( const std::string& key = "<empty>", const std::string& fallback = "<empty>" ) const {
	// Поиск ключа в карте. it -- это итерация, указатель на пару значений
	auto it = config_map.find( key );

	// Проверка, если нашелся нужный key на итерации. end -- это последний элемент итерации
	if ( it != config_map.end() ) {
		// second -- это value в моем случае, потомучто у меня хранятся пары key/value, на нужной итерации
        if ( m_logger ) {
            m_logger->log( "Get [" + key + "] = " + it->second, LOG_LEVEL::DEBUG );
        }
		return it->second;
	}

    if ( m_logger ) {
        m_logger->log( "Get fallback for [" + key + "] = " + fallback, LOG_LEVEL::DEBUG );
    }
	return fallback;
}

std::unordered_map<std::string, std::string> AParserFake::get_all() const {
    if ( m_logger ) {
        m_logger->log( "Get all config entries (count: " + std::to_string(config_map.size()) + ")", LOG_LEVEL::DEBUG );
    }
	// Возвращается коппия
	return config_map;
}

bool AParserFake::save_to_file( const std::string& path ) const {
    if ( m_logger ) {
        m_logger->log( "Save to file not supported in fake parser. Path: " + path, LOG_LEVEL::WARNING );
    }
	// Не сохраняет, потому что это -- Fake, а не полноценная реализация
	return false;
}

void AParserFake::set( const std::string& key, const std::string& value ) {
    if ( m_logger ) {
        m_logger->log( "Set operation not supported in fake parser. Key: " + key + ", Value: " + value, LOG_LEVEL::WARNING );
    }
	// Не изменяем config_map -- это Fake, а не полноценная реализация
}
