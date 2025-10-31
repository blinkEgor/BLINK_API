#include "../include/blink_api/api.h"

#include "../include/blink_api/fakes/ALoggerFake.h"
#include "../include/blink_api/stubs/AOutputStub.h"
#include "../include/blink_api/stubs/AScriptEngineStub.h"
#include "../include/blink_api/fakes/AParserFake.h"
#include "../include/blink_api/stubs/AInputStub.h"

#include "../include/blink_api/version.h"

BLINK_API::BLINK_API() {
	logger = std::make_unique<ALoggerFake>();

	if ( logger ) {
		output = std::make_unique<AOutputStub>( logger.get() );
		script = std::make_unique<AScriptEngineStub>( logger.get() );
		parser = std::make_unique<AParserFake>();
		input  = std::make_unique<AInputStub>( logger.get() );
	}
}

BLINK_API::~BLINK_API() {

}

bool BLINK_API::init() {
	if( !logger ) {
		std::cerr << "[std::cerr] [FATAL] Logger is not created. \n";
		return false;
	} else { logger->log( "Logger was created", LOG_LEVEL::DEBUG ); }

	if( !parser ) {
		logger->log( "Parser is not created", LOG_LEVEL::FATAL );
		return false;
	} else { logger->log( "Parser was created", LOG_LEVEL::DEBUG ); }

	logger->log( "API init called", LOG_LEVEL::INFO );
	logger->log( "BLINK_API: v" + std::string( BLINK_API_VERSION ) + "-proto", LOG_LEVEL::DEBUG );
	return true;
}

void BLINK_API::update() {
	script->update();
}

bool BLINK_API::exit() {
	logger->log( "API exiting...", LOG_LEVEL::INFO );
	return true;
}

// ==== C API реализация ====
extern "C" BLINK_API* create_api() {
	return new BLINK_API();
}

extern "C" void destroy_api( BLINK_API* api ) {
	delete api;
}

extern "C" bool api_init( BLINK_API* api ) {
	return api->init();
}

extern "C" void api_update( BLINK_API* api ) {
	api->update();
}

extern "C" bool api_exit( BLINK_API* api ) {
	return api->exit();
}

extern "C" const char* api_get_version() {
	return BLINK_API_VERSION;
}
