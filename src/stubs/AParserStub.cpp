#include "../../include/blink_api/abstractions/AParser.h"

#include <iostream>

std::unordered_map<std::string, std::string> stub_map = { { "stub_key", "stub_value" } };

class AParserStub : public AParser {
public:
	bool load_from_file( const std::string& path = "" ) override {
		std::cerr << "[TRACE] [AParserStub] Passed part to load file is <" << path << ">" << std::endl;
		if ( path == "" ) { return false; }
		return true;
	}

	bool save_to_file( const std::string& path = "" ) const override {
		std::cerr << "[TRACE] [AParserStub] Passed part save to file is <" << path << ">" << std::endl;
		if ( path == "" ) { return false; }
                return true;
	}

	std::string get( const std::string& key = "", const std::string& fallback = "" ) const override {
		std::cerr << "[TRACE] [AParserStub] get key is <" << key << ">" << std::endl;
		std::cerr << "[TRACE] [AParserStub] get fallback is <" << fallback << ">" << std::endl;
		return ( key + " = " + fallback );
	}

	void set( const std::string& key = "", const std::string& value = "" ) override {
		std::cerr << "[TRACE] [AParserStub] set key is <" << key << ">" << std::endl;
                std::cerr << "[TRACE] [AParserStub] set value is <" << value << ">" << std::endl;
	}

	std::unordered_map<std::string, std::string> get_all() const override {
		std::cerr << "[TRACE] [AParserStub] Get all key=value from unordered_map" << std::endl;
		return stub_map;
	}
};
