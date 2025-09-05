#pragma once

// --- макрос для экспорта символов ---
#if defined(_WIN32) || defined(_WIN64)
	#define BLINK_API_EXPORT __declspec(dllexport)
#else
	#define BLINK_API_EXPORT __attribute__((visibility("default")))
#endif

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
	BLINK_API_EXPORT BLINK_API* create_api();
	BLINK_API_EXPORT void destroy_api( BLINK_API* api );

	// Обёртки для динамической загрузки:
	BLINK_API_EXPORT bool api_init( BLINK_API* api );
	BLINK_API_EXPORT void api_update( BLINK_API* api );
	BLINK_API_EXPORT bool api_exit( BLINK_API* api );

	// Версия API
	BLINK_API_EXPORT const char* api_get_version();
}
