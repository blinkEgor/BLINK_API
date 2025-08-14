#include "../../include/blink_api/stubs/AOutputStub.h"

void AOutputStub::cli_out( const std::string& message = "", text_color color = text_color::none, bg_color bg = bg_color::none ) {
	std::string paint_text_color = "\033[0m";
	std::string paint_bg_color = "\033[0m";
	std::string paint_none = "\033[0m";

	std::cout << "[\033[91mAOutputStub]\033[0m " << paint_bg_color << paint_text_color << message << paint_none;
}

void AOutputStub::cli_endl() {
	std::cout << std::endl;
}

bool AOutputStub::file_out( const std::string& message = "", const std::string& path = "", text_color color = text_color::none, bg_color bg = bg_color::none ) {
	if ( path == "" ) { return false; }

	std::string paint_text_color = "\033[0m";
	std::string paint_bg_color = "\033[0m";
	std::string paint_none = "\033[0m";

	if ( color != text_color::none ) {
		paint_text_color = "\033[32m";
	} else { paint_text_color = ""; }

	if ( bg != bg_color::none ) {
		paint_bg_color = "\033[45m";
	} else { paint_bg_color = ""; }

	if ( ( color == text_color::none ) && ( bg == bg_color::none ) ) {
		paint_none = "";
	}

	std::cout << "[AOutputStub] " << "Message: [" << paint_bg_color << paint_text_color << message << paint_none << "], was printed to file, by path: [" << path << "]\n";
	return true;
}

bool file_endl( const std::string& path ) {
	if ( path == "" ) { return false; }

	std::cout << std::endl;
	std::cout << "[\033[91mAOutputStub]\033[0m " << "File path: [" << path << "] was endl\n";

	return true;
}
