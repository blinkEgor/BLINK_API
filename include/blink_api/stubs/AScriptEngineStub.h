#include "../abstractions/AScriptEngine.h"

class AScriptEngineStub : public AScriptEngine {
public:
	void init() override;
	void update() override;
	void exit() override;
};
