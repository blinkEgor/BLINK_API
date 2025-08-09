#include "../../include/blink_api/abstractions/AInput.h"

class AInputStub : public AInput {
public:
	std::string get_input( const std::string& message = ": " ) {
		std::cerr << "[TRACE] " << "[AInputStub] " << "Get input is working\n";

		std::string hendle_input = "";

		std::cerr << message;
		std::cin >> hendle_input;

		return hendle_input;
	}
};
