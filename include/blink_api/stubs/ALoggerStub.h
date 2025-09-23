#pragma once
#include "../abstractions/ALogger.h"	// <string> | LOG_LEVEL

class ALoggerStub : public ALogger {
public:
	~ALoggerStub() override = default;
	bool init() override;
	void log( const std::string& message, LOG_LEVEL level ) override;
	void cleanup_logs( int max_logs ) override;
	std::string get_current_time() override;
	bool configure( std::string path ) override;
};
