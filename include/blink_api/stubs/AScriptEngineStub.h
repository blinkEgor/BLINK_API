#include "../abstractions/AScriptEngine.h"

class AScriptEngineStub : public AScriptEngine {
public:
    AScriptEngineStub( ALogger* logger = nullptr ) : AScriptEngine( logger ) {}
	~AScriptEngineStub() override = default;
	void init() override;
	void update() override;
	void exit() override;
};
