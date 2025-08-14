#include "../../include/blink_api/stubs/AInputStub.h"

std::string AInputStub::get_input( const std::string& message = ": " ) {
	std::cerr << "[TRACE] " << "[AInputStub] " << "Get input is working\n";

	std::string hendle_input = "";

	std::cerr << message;
	std::cin >> hendle_input;

	return hendle_input;
}
