#include "../abstractions/AOutput.h"

class AOutputStub : public AOutput {
public:
	void cli_out( const std::string& message, text_color color, bg_color bg ) override;
	void cli_endl();
	bool file_out( const std::string& message, const std::string& path, text_color color, bg_color bg ) override;
	bool file_endl( const std::string& path ) override;
};
