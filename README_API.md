# BLINK_API (модуль абстракций)

**Версия:**
blink_api_version = 0.1.0-proto
**Назначение:** Слой абстракций для создания плагинов, совместимых с ядром BLINK_CORE.

## Состав
- `bin/libblink_api.so` — shared-библиотека
- `include/blink_api/` — заголовочные файлы интерфейсов
- ~~`configs/api_plugins/` — конфигурации плагинов~~ (появится в будущем)
---

## Использование

### Для интеграции с ядром
> Ядро `BLINK_CORE` динамически загружает `libblink_api.so` и использует C-интерфейс:
```C
extern "C" {
        BLINK_API_EXPORT BLINK_API* create_api();
        BLINK_API_EXPORT void destroy_api( BLINK_API* api );
        BLINK_API_EXPORT bool api_init( BLINK_API* api );
        BLINK_API_EXPORT void api_update( BLINK_API* api );
        BLINK_API_EXPORT bool api_exit( BLINK_API* api );
}
```

> Dynamic Loading Example (Linux)
```cpp
void* handle = dlopen( "bin/libblink_api.so", RTLD_LAZY );
auto* api = ( ( BLINK_API*(*)() )dlsym( handle, "create_api" ) )();
api->init();
```

> Пример использования:
```cpp
BLINK_API* api = create_api();
api_init(api);
api_update(api);
api_exit(api);
destroy_api(api);
dlclose(handle);
```
---

### Для разработки плагинов
> Создайте класс, унаследованный от одной из абстракций, и реализуйте все виртуальные методы.
> Пример плагина для логирования:
```cpp
 #include <blink_api/abstractions/ALogger.h>

class CustomLogger : public ALogger {
public:
    bool init() override {
        // ваша реализация инициализации
        return true;
    }

    void log(const std::string& message, LOG_LEVEL level) override {
        // ваша реализация логирования
    }

    // ... остальные методы
};
```
---

### Абстракции

#### ALogger
Интерфейс системы логирования.
Методы:
- `init()` — инициализация логгера
- `log(message, level)` — запись сообщения с указанным уровнем
- `cleanup_logs(max_logs)` — удаление старых логов
- `get_current_time()` — получение текущего времени (для меток)
- `configure(path)` — загрузка конфигурации
---

#### AOutput
Интерфейс системы вывода.
Методы:
- `cli_out(message, color, bg)` — вывод в консоль с цветом
- `cli_endl()` — перенос строки в консоли
- `file_out(message, path, color, bg)` — вывод в файл с цветом
- `file_endl(path)` — перенос строки в файле
---

#### Другие абстракции
- `AScriptEngine` — исполнение скриптов
- `AParser` — парсинг конфигураций
- `AInput` — обработка ввода
---

### Версионирование
Версия API определяется в version.h и отображается при инициализации.
Плагины должны быть совместимы с версией API, используемой ядром.

## Диагностика
При успешной загрузке API выводит в консоль версию (Например):
`[ALoggerStub][DEBUG] BLINK_API: v0.1.0-proto`
