#pragma once

#include <iostream>

// Цвет текста, реализацией может быть таблица ANSI-цветов для C++.
enum class text_color {
	black,
	red,
	green,
	yellow,
	blue,
	purple,
	light_blue,
	white,
	gray,
	bright_red,
	none
};

// Цвет фона для текста, реализацией может быть таблица ANSI-цветов для C++.
enum class bg_color {
	black,
	red,
	green,
	yellow,
	blue,
	purple,
	light_blue,
	white,
	none
};

class ALogger;

class AOutput {
public:
	AOutput( ALogger* logger = nullptr ) : m_logger( logger ) {}
	virtual ~AOutput() = default;

	// Вывод текста в CLI.
	// Параметры:
	// 1. Сообщения, которое будет выведено в CLI,
	// 2. Цвет текста, смотреть таблицу text_color в файле AOutput.h,
	// 3. Цвет фона для текста, смотреть таблицу bg_color в файле AOutput.h.
	virtual void cli_out( const std::string& message, text_color color, bg_color bg ) = 0;

	// Отступ на новую строку для CLI.
	virtual void cli_endl() = 0;

	// Вывод текста в файл.
	// Параметры:
	// 1. Сообщение, котрое будет напечатано в файл,
	// 2. Путь к файлу в котором будет напечатан текст, относительно корневой директории программы,
	// 3. Цвет текста: "! НЕ ВСЕ ТЕКСТОВЫЕ РЕДАКТОРЫ И ФАЙЛЫ ПОДДЕРЖИВАЮТ ЦВЕТА !",
	// 4. Цвет фона для текста: "! НЕ ВСЕ ТЕКСТОВЫЕ РЕДАКТОРЫ И ФАЙЛЫ ПОДДЕРЖИВАЮТ ЦВЕТА !".
	virtual bool file_out( const std::string& message, const std::string& path, text_color color, bg_color bg ) = 0;

	// Отступ на новую строку в файле.
	// Параметр:
	// 1. Путь к файлу в котором будет сделан отступ, относительно корневой директории программы.
	virtual bool file_endl( const std::string& path ) = 0;

protected: ALogger* m_logger;
};
