#include "../../include/blink_api/abstractions/AScriptEngine.h"
#include <iostream>

class AScriptEngineStub : public AScriptEngine {
public:
	void init() override {
		std::cerr << "[TRACE] AScriptEngineStub::init() called (no script engine connected)" << std::endl;
	}

	void update() override {
		std::cerr << "[TRACE] AScriptEngineStub::update() called (no script logic)" << std::endl;
	}

	void exit() override {
		std::cerr << "[TRACE] AScriptEngineStub::exit() called (no cleanup required)" << std::endl;
	}
};
