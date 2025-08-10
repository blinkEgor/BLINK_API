#include "../include/blink_api/api.h"

#include "../include/blink_api/stubs/ALoggerStub.h"
#include "../include/blink_api/stubs/AOutputStub.h"
#include "../include/blink_api/stubs/AScriptEngineStub.h"
#include "../include/blink_api/stubs/AParserStub.h"
#include "../include/blink_api/stubs/AInputStub.h"

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
	return true;
}

void BLINK_API::update() {
	script->update();
}

bool BLINK_API::exit() {
	logger->log( "API exiting...", LOG_LEVEL::INFO );
	return true;
}
