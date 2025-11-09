#include "../abstractions/AOutput.h"

class OutputStub : public AOutput {
public:
	OutputStub( ALogger* logger = nullptr ) : AOutput( logger ) {}
	~OutputStub() override = default;
	void cli_out( const std::string& message, text_color color, bg_color bg ) override;
	void cli_endl();
	bool file_out( const std::string& message, const std::string& path, text_color color, bg_color bg ) override;
	bool file_endl( const std::string& path ) override;
};
