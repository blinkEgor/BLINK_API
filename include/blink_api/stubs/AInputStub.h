#include "../abstractions/AInput.h"

class AInputStub : public AInput {
	std::string get_input( const std::string& message ) override;
};
