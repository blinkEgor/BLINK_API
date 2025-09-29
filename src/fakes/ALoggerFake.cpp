#include "../../include/blink_api/fakes/ALoggerFake.h"	// <string> | LOG_LEVEL
#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include <vector>

std::string ALoggerFake::get_current_time() {
	auto now = std::chrono::system_clock::now();
	std::time_t now_time_t = std::chrono::system_clock::to_time_t( now );
	std::tm now_tm = *std::localtime( &now_time_t );
	std::stringstream ss;
	ss << std::put_time( &now_tm, "%Y-%m-%d %H:%M:%S" );
	return ss.str();
}

void ALoggerFake::log( const std::string& message = "", LOG_LEVEL level = LOG_LEVEL::INFO ) {
	std::string time_str = get_current_time();
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

	if ( !std::filesystem::exists( "logs" ) ) {
		std::filesystem::create_directory( "logs" );
	}

	// Только дату, чтобы дать имя файла лога -- сортировка по дням.
	std::string date_str = ALoggerFake::get_current_time().substr( 0, 10 );
	// Пока что оставим .txt как в ядре, чтобы лог продолжася в том же файле. Это форос рефакторинга в будущем.
	std::string filename = "logs/log_" + date_str + ".txt";
	// Второй аргумент, нужен чтобы в файле новые записи добавлялись в конец.
	std::ofstream log_file( filename, std::ios::app );
	if ( log_file.is_open() ) {
		log_file << "[" << time_str << "] " << level_str << message << std::endl;
		log_file.close();
	}
	std::cerr << "[" << time_str << "] " << level_str << message << std::endl;
}

void ALoggerFake::cleanup_logs( int max_logs = 7 ) {
	if ( max_logs <= 0 ) {
		max_logs = 7;
	}

	namespace fs = std::filesystem;
	std::vector<fs::directory_entry> logs;

	for ( const auto& entry : fs::directory_iterator( "logs" ) ) {
		// ПОМНИМ!!! пока что везде используются ".txt" файлы как логи. Это вопрос архитектурного рефакторинга в будущем, не сейчас, поэтому заметка.
		if ( entry.is_regular_file() && entry.path().extension() == ".txt" ) {
			logs.push_back( entry );
		}
	}

	std::sort( logs.begin(), logs.end(), []( const auto& a, const auto& b ) {
		return fs::last_write_time( a ) > fs::last_write_time( b );
	} );

	for ( size_t i = max_logs; i < logs.size(); ++i ) {
		fs::remove( logs[i] );
	}
}

bool ALoggerFake::init() {
	ALoggerFake::log( "[ALoggerFake] Fake logger initialized (no external dependencies required)" );
	return true;
}

bool ALoggerFake::configure( std::string path ) {
	ALoggerFake::log( "[ALoggerFake] Fake logger does not support configuration. Path '" + path + "' will be ignored.", LOG_LEVEL::WARNING );
	return true;
}

ALoggerFake::~ALoggerFake() {
	ALoggerFake::log( "[ALoggerFake] Fake logger shutdown completed" );
}
