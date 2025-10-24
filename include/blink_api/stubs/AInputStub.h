#include "../abstractions/AInput.h"

class AInputStub : public AInput {
public:
	~AInputStub() override = default;
	std::string get_input( const std::string& message ) override;
};
