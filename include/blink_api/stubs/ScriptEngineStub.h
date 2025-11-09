#include "../abstractions/AScriptEngine.h"

class ScriptEngineStub : public AScriptEngine {
public:
    ScriptEngineStub( ALogger* logger = nullptr ) : AScriptEngine( logger ) {}
	~ScriptEngineStub() override = default;
	void init() override;
	void update() override;
	void exit() override;
};
