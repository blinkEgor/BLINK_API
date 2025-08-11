#include "../abstractions/ALogger.h"

class ALoggerStub : public ALogger {
public:
	bool init() override;
	void log( const std::string& message, LOG_LEVEL level ) override;
	void cleanup_logs( int max_logs ) override;
	std::string get_current_time() override;
	configure( std::string path ) override;
}
