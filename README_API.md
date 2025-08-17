# BLINK_API
This is API for my own framework

**Версия:**
blink_api_version = 0.1.0-proto
**Назначение:** Слой абстракций для движка.

## Состав
- include/blink_api/api.h
- bin/libblink_api.so

## Использование
```bash

```

## Документация для разработки

### C API Functions
```C
extern "C" {
        BLINK_API_EXPORT BLINK_API* create_api();
        BLINK_API_EXPORT void destroy_api( BLINK_API* api );
        BLINK_API_EXPORT bool api_init( BLINK_API* api );
        BLINK_API_EXPORT void api_update( BLINK_API* api );
        BLINK_API_EXPORT bool api_exit( BLINK_API* api );
}
```

### Dynamic Loading Example (Linux)
```cpp
void* handle = dlopen( "bin/libblink_api.so", RTLD_LAZY );
auto* api = ( ( BLINK_API*(*)() )dlsym( handle, "create_api" ) )();
api->init();
```

### Troubleshooting
Error: libblink_api.so: cannot open shared object file
Fix: Укажите полный путь к .so или добавьте bin/ в LD_LIBRARY_PATH.
