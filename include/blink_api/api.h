#pragma once

#include "abstractions/ALogger.h"
#include "abstractions/AOutput.h"
#include "abstractions/AScriptEngine.h"
#include "abstractions/AParser.h"
#include "abstractions/AInput.h"

class BLINK_API {
public:
	BLINK_API();
	~BLINK_API();

	bool init();
	void update();
	bool exit();

private:
	ALogger* logger;
	AOutput* output;
	AScriptEngine* script;
	AParser* parser;
	AInput* input;
};

// ==== C API ====
// Эти функции будут вызываться при dlopen
extern "C" {
	BLINK_API* create_api();
	void destroy_api( BLINK_API* api );
}
