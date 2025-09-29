#pragma once
#include "../abstractions/ALogger.h"	// <string> | LOG_LEVEL

class ALoggerFake : public ALogger {
public:
	~ALoggerFake() override;
	bool init() override;
	void log( const std::string& message, LOG_LEVEL level ) override;
	void cleanup_logs( int max_logs ) override;
	std::string get_current_time() override;
	bool configure( std::string path ) override;
};
