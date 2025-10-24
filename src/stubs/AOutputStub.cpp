#include "../../include/blink_api/stubs/AOutputStub.h"
#include "../../include/blink_api/abstractions/ALogger.h"

void AOutputStub::cli_out( const std::string& message = "", text_color color = text_color::none, bg_color bg = bg_color::none ) {
	if ( m_logger ) {
		m_logger->log( "AOutputStub::cli_out called with message: " + message, LOG_LEVEL::DEBUG );
	}

	std::string paint_text_color = "\033[0m";
	std::string paint_bg_color = "\033[0m";
	std::string paint_none = "\033[0m";

	std::cout << "[\033[91mAOutputStub]\033[0m " << paint_bg_color << paint_text_color << message << paint_none;
}

void AOutputStub::cli_endl() {
	if ( m_logger ) {
		m_logger->log( "AOutputStub::cli_endl called", LOG_LEVEL::DEBUG );
	}

	std::cout << std::endl;
}

bool AOutputStub::file_out( const std::string& message = "", const std::string& path = "", text_color color = text_color::none, bg_color bg = bg_color::none ) {
	if ( path == "" ) {
		if (m_logger) {
			m_logger->log( "AOutputStub::file_out failed - empty path", LOG_LEVEL::WARNING );
		}
		return false;
	}

	if ( m_logger ) {
		m_logger->log( "AOutputStub::file_out writing to: " + path, LOG_LEVEL::DEBUG );
	}

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

bool AOutputStub::file_endl( const std::string& path ) {
	if ( path == "" ) {
		if ( m_logger ) {
			m_logger->log( "AOutputStub::file_endl failed - empty path", LOG_LEVEL::WARNING );
		}
		return false;
	}

	if ( m_logger ) {
		m_logger->log( "AOutputStub::file_endl called for path: " + path, LOG_LEVEL::DEBUG );
	}

	std::cout << std::endl;
	std::cout << "[\033[91mAOutputStub]\033[0m " << "File path: [" << path << "] was endl\n";

	return true;
}
