#include "../../include/blink_api/stubs/ALoggerStub.h"
#include <iostream>

bool ALoggerStub::init() {
	if ( !configure( "configs/api_plagins/default_plagin.conf" ) ) {
		return false;
	}
	std::cout << "ALoggerStub is working" << std::endl;
	return true;
}

void ALoggerStub::log( const std::string& message = "", LOG_LEVEL level = LOG_LEVEL::INFO ) {
	std::string level_str;

	switch( level ) {
		case LOG_LEVEL::INFO: level_str = "\033[32m[INFO]\033[0m "; break;
		case LOG_LEVEL::WARNING: level_str = "\033[33m[WARNING]\033[0m "; break;
		case LOG_LEVEL::ERROR: level_str = "\033[31m[ERROR]\033[0m "; break;
		case LOG_LEVEL::FATAL: level_str = "\033[91m[FATAL]\033[0m "; break;
		case LOG_LEVEL::DEBUG: level_str = "\033[35m[DEBUG]\033[0m "; break;
		case LOG_LEVEL::TRACE: level_str = "\033[36m[TRACE]\033[0m "; break;
		default: level_str = "\033[90m[UNKNOWN]\033[0m "; break;
	}

	std::cerr << "[ALoggerStub]" << level_str << message << std::endl;
}

void ALoggerStub::cleanup_logs( int max_logs = 7 ) {
	std::cout << "ALoggerStub cleanup logs..." << std::endl;
}

std::string ALoggerStub::get_current_time() {
	return "2025-01-01 00:00:00";
}

bool ALoggerStub::configure( std::string path = "configs/api_plagins/default_plagin.conf" ) {
	std::cout << "Config path is \033[33m" + path + "\033[0m" << std::endl;
	return true;
}
