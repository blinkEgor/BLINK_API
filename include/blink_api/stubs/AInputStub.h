#include "../abstractions/AInput.h" // <string> | <iostream>

class AInputStub : public AInput {
public:
    AInputStub( ALogger* logger = nullptr ) : AInput( logger ) {}
	~AInputStub() override = default;
	std::string get_input( const std::string& message ) override;
};
