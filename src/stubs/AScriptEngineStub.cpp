#include "../../include/blink_api/stubs/AScriptEngineStub.h"
#include <iostream>

void AScriptEngine::init() {
	std::cerr << "[TRACE] AScriptEngineStub::init() called (no script engine connected)" << std::endl;
}

void AScriptEngine::update() {
	std::cerr << "[TRACE] AScriptEngineStub::update() called (no script logic)" << std::endl;
}

void AScriptEngine::exit() {
	std::cerr << "[TRACE] AScriptEngineStub::exit() called (no cleanup required)" << std::endl;
}
