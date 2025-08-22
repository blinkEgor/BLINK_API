#include "../abstractions/AInput.h"

class AInputStub : public AInput {
	~AInputStub() override = default;
	std::string get_input( const std::string& message ) override;
};
