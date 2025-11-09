#pragma once
#include "../abstractions/AParser.h"	// <string> | <unordered_map>

class ParserFake : public AParser {
public:
    ParserFake( ALogger* logger = nullptr ) : AParser( logger ) {}
	~ParserFake() override = default;	// Пока не знаю будет реализация или нет, поэтому default
	bool load_from_file( const std::string& path ) override;
	bool save_to_file( const std::string& path ) const override;
	std::string get( const std::string& key, const std::string& fallback ) const override;
	void set( const std::string& key, const std::string& value ) override;
	std::unordered_map<std::string, std::string> get_all() const override;
private:
	std::unordered_map< std::string, std::string > config_map;
};
