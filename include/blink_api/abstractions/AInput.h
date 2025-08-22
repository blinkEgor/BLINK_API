#pragma once

#include <string>
#include <iostream>

class AInput {
public:
	virtual ~AInput() = default;

	// Сейчас используется только для CLI. Позже можно расширить до других типов ввода
	virtual std::string get_input( const std::string& message ) = 0;
};
