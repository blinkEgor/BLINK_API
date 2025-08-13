#include "../abstractions/AParser.h"

class AParserStub : public AParser {
public:
	bool load_from_file( const std::string& path ) override;
	bool save_to_file( const std::string& path ) const override;
	std::string get( const std::string& key, const std::string& fallback ) const override;
	void set( const std::string& key, const std::string& value ) override;
	std::unordered_map<std::string, std::string> get_all() const override;
};
