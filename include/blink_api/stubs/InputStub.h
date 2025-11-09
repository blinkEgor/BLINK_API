#include "../abstractions/AInput.h" // <string> | <iostream>

class InputStub : public AInput {
public:
    InputStub( ALogger* logger = nullptr ) : AInput( logger ) {}
	~InputStub() override = default;
	std::string get_input( const std::string& message ) override;
};
