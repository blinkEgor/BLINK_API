#include "../include/blink_api/api.h"

#include "../include/blink_api/stubs/ALoggerStub.h"
#include "../include/blink_api/stubs/AOutputStub.h"
#include "../include/blink_api/stubs/AScriptEngineStub.h"
#include "../include/blink_api/stubs/AParserStub.h"
#include "../include/blink_api/stubs/AInputStub.h"

#include "../include/blink_api/version.h"

BLINK_API::BLINK_API() {
	logger = new ALoggerStub();
	output = new AOutputStub();
	script = new AScriptEngineStub();
	parser = new AParserStub();
	input  = new AInputStub();
}

BLINK_API::~BLINK_API() {
	delete logger;
	delete output;
	delete script;
	delete parser;
	delete input;
}

bool BLINK_API::init() {
	logger->log( "API init called", LOG_LEVEL::INFO );
	logger->log( "BLINK_API: v" + BLINK_API_VERSION + "-proto", LOG_LEVEL::DEBUG );
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
