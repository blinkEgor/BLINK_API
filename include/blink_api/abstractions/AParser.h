#pragma once

#include <string>
#include <unordered_map>

class ALogger;

class AParser {
public:
    AParser( ALogger* logger = nullptr ) : m_logger( logger ) {}
	virtual ~AParser() = default;

	// Загрузка конфигурации из файла в unordered_map
	virtual bool load_from_file( const std::string& path ) = 0;

	// Сохранение конфигурации в файл из unordered_map
	virtual bool save_to_file( const std::string& path ) const = 0;

	// Получить значение по ключу с fallback из unordered_map
	virtual std::string get( const std::string& key, const std::string& fallback ) const = 0;

	// Установить значение по ключу
	virtual void set( const std::string& key, const std::string& value ) = 0;

	// Получить карту всех пар ключ-значение
	virtual std::unordered_map<std::string, std::string> get_all() const = 0;

protected: ALogger* m_logger;
};
