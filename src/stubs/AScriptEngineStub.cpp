#include "../../include/blink_api/stubs/AScriptEngineStub.h"
#include <iostream>

void AScriptEngineStub::init() {
	std::cerr << "[TRACE] AScriptEngineStub::init() called (no script engine connected)" << std::endl;
}

void AScriptEngineStub::update() {
	std::cerr << "[TRACE] AScriptEngineStub::update() called (no script logic)" << std::endl;
}

void AScriptEngineStub::exit() {
	std::cerr << "[TRACE] AScriptEngineStub::exit() called (no cleanup required)" << std::endl;
}
