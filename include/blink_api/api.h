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
#include "PluginManager.h"
#include <memory>

class BLINK_API {
public:
	BLINK_API();
	~BLINK_API();

	bool init();
	void update();
	bool exit();

private:
	std::unique_ptr<ALogger> logger;
	std::unique_ptr<AOutput> output;
	std::unique_ptr<AScriptEngine> script;
	std::unique_ptr<AParser> parser;
	std::unique_ptr<AInput> input;
    std::unique_ptr<PluginManager> plugin_manager;
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
