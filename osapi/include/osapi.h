#include <osapi_types.h>
#include <stdarg.h>

//functions defs
#ifdef __cplusplus
extern "C" {
#endif
       int printf(const char *format, ...);
       int vprintf(const char *format, va_list ap);
       int vfprintf(FILE *stream, const char *format, va_list ap);
       int vsprintf(char *str, const char *format, va_list ap);
       int vsnprintf(char *str, size_t size, const char *format, va_list ap);
#ifdef __cplusplus
}
#endif
