#include "../../include/blink_api/fakes/AParserFake.h"	// <string> | <unordered_map>
#include <iostream>
#include <fstream>	// для std::ifstream
#include <sstream>	// для std::istringstream
std::string stub = "[AParserFake -> std::cerr]";

bool AParserFake::load_from_file( const std::string& path = "configs/api_plugins/default_plugin.conf" ) {
	std::cerr << stub + "Loading config from: " + path << std::endl;
	std::ifstream file( path );

	if ( !file.is_open() ) {
		std::cerr << stub + "Failed to open config: " + path << std::endl;
		return false;
	}

	std::string current_key;
	std::string current_value;

	std::string line;
	while ( std::getline( file, line ) ) {
		if ( line.empty() || line[0] == '#' ) continue;

		if ( !current_key.empty() ) {
			config_map[ current_key ] = current_value;
			std::cerr << stub + "Parsed config [" + current_key + "] = " + current_value << std::endl;
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

		std::cerr << stub + "Found config key: " + key << std::endl;
		current_key = key;
		current_value = value;
	}

	if ( !current_key.empty() ) {
		config_map[ current_key ] = current_value;
		std::cerr << stub + "Parsed config [" + current_key + "] = " + current_value << std::endl;
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
		std::cerr << stub << "Get [" << key << "] = " << it->second << std::endl;
		return it->second;
	}

	std::cerr << stub << "Get fallback for [" << key << "] = " << fallback << std::endl;
	return fallback;
}

std::unordered_map<std::string, std::string> AParserFake::get_all() const {
	std::cerr << stub << "Get all config entries (count: " << config_map.size() << ")" << std::endl;
	// Возвращается коппия
	return config_map;
}

bool AParserFake::save_to_file( const std::string& path ) const {
	std::cerr << stub << "Save to file not supported in fake parser. Path: " << path << std::endl;
	// Не сохраняет, потому что это -- Fake, а не полноценная реализация
	return false;
}

void AParserFake::set( const std::string& key, const std::string& value ) {
	std::cerr << stub << "Set operation not supported in fake parser. Key: " << key << ", Value: " << value << std::endl;
	// Не изменяем config_map -- это Fake, а не полноценная реализация
}
