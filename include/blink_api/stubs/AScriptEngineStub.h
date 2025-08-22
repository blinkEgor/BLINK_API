#include "../abstractions/AScriptEngine.h"

class AScriptEngineStub : public AScriptEngine {
public:
	~AScriptEngineStub() override = default;
	void init() override;
	void update() override;
	void exit() override;
};
