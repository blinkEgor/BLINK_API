#pragma once

#include <fstream>	// Для работы с файлами
#include <filesystem>	// Для работы с директориями
#include <iostream>	// Для вывода в консоль
#include <chrono>	// Для работы со временем
#include <iomanip>	// Для форматирования вывода
#include <ctime>	// Для преобразования времени в строку
#include <vector>	// Для работы с вектором
#include <algorithm>	// Для сортировки внутри вектора

// Перечисление для типов сообщений
enum class LOG_LEVEL {
	INFO,
	WARNING,
	ERROR,
	FATAL,
	DEBUG,
	TRACE,
};

class ALogger {
public:
	virtual ~ALogger() = default;

	// Инициализация логгера:
	// - подгружает конфигурацию логгера первый раз;
	// - печатает первый лог;
	// - возвращает true при успехе.
	virtual bool init() = 0;

	// Печать лога:
	// - Параметры:
	// - 1. Сообщение лога,
	// - 2. Уровень логирования из enum class LOG_LEVEL
	// - Основная функция которая вызывает лог, принимает кофигурационные настройки
	virtual void log( const std::string& message, LOG_LEVEL level ) = 0;

	// Удаляет лог файл:
	// - параметр это количество лог файлов, которые могут существовать в папке
	virtual void cleanup_logs( int max_logs ) = 0;

	// Получение системного времени (нужно для точного логирования)
	virtual std::string get_current_time() = 0;

	// Загрузка конфигурации нужные для логирования, и обновления существующей в рантайме
	virtual bool configure( std::string path ) = 0;
};
