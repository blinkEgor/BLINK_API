#pragma once
#include <string>
#include <iostream>

class ALogger;

class AInput {
public:
    AInput( ALogger* logger = nullptr ) : m_logger( logger ) {}
	virtual ~AInput() = default;

	// Сейчас используется только для CLI. Позже можно расширить до других типов ввода
	virtual std::string get_input( const std::string& message ) = 0;
protected: ALogger* m_logger;
};
