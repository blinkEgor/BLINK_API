#include "../../include/blink_api/abstractions/AOutput.h"

class AOutputStub : public AOutput {
public:
	void cli_out( const std::string& message = "", text_color color = text_color::none, bg_color bg = bg_color::none ) override {
		std::string paint_text_color;
		std::string paint_bg_color;
		std::string paint_none = "\033[0m";

		switch( color ) {
			case text_color::black:		paint_text_color = "\033[30m"; break;
			case text_color::red: 		paint_text_color = "\033[31m"; break;
			case text_color::green: 	paint_text_color = "\033[32m"; break;
			case text_color::yellow: 	paint_text_color = "\033[33m"; break;
			case text_color::blue: 		paint_text_color = "\033[34m"; break;
			case text_color::purple: 	paint_text_color = "\033[35m"; break;
			case text_color::light_blue: 	paint_text_color = "\033[36m"; break;
			case text_color::white: 	paint_text_color = "\033[37m"; break;
			case text_color::gray: 		paint_text_color = "\033[90m"; break;
			case text_color::bright_red: 	paint_text_color = "\033[91m"; break;
			case text_color::none:     	paint_text_color = paint_none; break;
			default: 			paint_text_color = paint_none; break;
		}

		switch( bg ) {
			case bg_color::black: 		paint_bg_color = "\033[40m"; break;
			case bg_color::red: 		paint_bg_color = "\033[41m"; break;
			case bg_color::green: 		paint_bg_color = "\033[42m"; break;
			case bg_color::yellow: 		paint_bg_color = "\033[43m"; break;
			case bg_color::blue: 		paint_bg_color = "\033[44m"; break;
			case bg_color::purple: 		paint_bg_color = "\033[45m"; break;
			case bg_color::light_blue: 	paint_bg_color = "\033[46m"; break;
			case bg_color::white: 		paint_bg_color = "\033[47m"; break;
			case bg_color::none:     	paint_bg_color = paint_none; break;
			default:	 		paint_bg_color = paint_none; break;
		}

		std::cout << paint_bg_color << paint_text_color << message << paint_none;
	}

	void cli_endl() override {
		std::cout << std::endl;
	}

	bool file_out( const std::string& message = "", const std::string& path = "", text_color color = text_color::none, bg_color bg = bg_color::none ) override {
		if ( path == "" ) { return false; }

		std::string paint_text_color;
		std::string paint_bg_color;
		std::string paint_none = "\033[0m";

		if ( color != text_color::none ) {
			switch( color ) {
				case text_color::black:         paint_text_color = "\033[30m"; break;
				case text_color::red:           paint_text_color = "\033[31m"; break;
				case text_color::green:         paint_text_color = "\033[32m"; break;
				case text_color::yellow:        paint_text_color = "\033[33m"; break;
				case text_color::blue:          paint_text_color = "\033[34m"; break;
				case text_color::purple:        paint_text_color = "\033[35m"; break;
				case text_color::light_blue:    paint_text_color = "\033[36m"; break;
				case text_color::white:         paint_text_color = "\033[37m"; break;
				case text_color::gray:          paint_text_color = "\033[90m"; break;
				case text_color::bright_red:    paint_text_color = "\033[91m"; break;
				case text_color::none:          paint_text_color = paint_none; break;
				default:                        paint_text_color = paint_none; break;
			}
		} else { paint_text_color = ""; }

		if ( bg != bg_color::none ) {
			switch( bg ) {
				case bg_color::black:           paint_bg_color = "\033[40m"; break;
				case bg_color::red:             paint_bg_color = "\033[41m"; break;
				case bg_color::green:           paint_bg_color = "\033[42m"; break;
				case bg_color::yellow:          paint_bg_color = "\033[43m"; break;
				case bg_color::blue:            paint_bg_color = "\033[44m"; break;
				case bg_color::purple:          paint_bg_color = "\033[45m"; break;
				case bg_color::light_blue:      paint_bg_color = "\033[46m"; break;
				case bg_color::white:           paint_bg_color = "\033[47m"; break;
				case bg_color::none:            paint_bg_color = paint_none; break;
				default:                        paint_bg_color = paint_none; break;
			}
		} else { paint_bg_color = ""; }

		if ( ( color == text_color::none ) && ( bg == bg_color::none ) ) {
			paint_none = "";
		}

		std::cout << "Message: ["<< paint_text_color << message << paint_none << "], was printed to file, by path: [" << path << "]\n";
		return true;
	}

	bool file_endl( const std::string& path ) override {
		if ( path == "" ) { return false; }

		std::cout << std::endl;
		std::cout << "File path: [" << path << "] was endl\n";

		return true;
	}
};
