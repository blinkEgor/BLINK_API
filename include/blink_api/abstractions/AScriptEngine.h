#pragma once

class AScriptEngine {
public:
	virtual ~AScriptEngine() = default;

	// Инициализация логики скрипта, используется один раз после запуска ядра.
	virtual void init() = 0;

	// Основаня логика программы: опрос, обработка команд, выполнение сценариев.
	virtual void update() = 0;

	// Завершение логики программы, сохранения состояния и прощальное сообщение.
	virtual void exit() = 0;
};
