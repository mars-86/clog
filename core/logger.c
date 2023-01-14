#include "logger.h"
#include <stdio.h>
#include <stdarg.h>

enum LogLevel {
    NONE,
    CRITICAL,
    ERROR,
    WARN,
    INFO,
    DEBUG,
    TRACE,
    ALL
};

#ifndef _LOG_LEVEL
  #define _LOG_LEVEL INFO 
#endif

#define _LOG_LEVEL_CHECK(level) \
    do { \
        if (_LOG_LEVEL < level) return; \
    } while (0);

#define _LOG_LEVEL_PRINT(stream, format) \
    do { \
        va_list args; \
        va_start(args, format); \
        vfprintf(stream, format, args); \
        va_end(args); \
    } while (0);

void print_log(enum LogLevel level, FILE *stream, const char *format, ...);

void log_critical(const char *format, ...)
{
    _LOG_LEVEL_CHECK(CRITICAL);
    _LOG_LEVEL_PRINT(stderr, format);
}

void log_error(const char *format, ...)
{
    _LOG_LEVEL_CHECK(ERROR);
    _LOG_LEVEL_PRINT(stderr, format);
}

void log_warn(const char *format, ...)
{
    _LOG_LEVEL_CHECK(WARN);
    _LOG_LEVEL_PRINT(stdout, format);
}

void log_info(const char *format, ...)
{
    _LOG_LEVEL_CHECK(INFO);
    _LOG_LEVEL_PRINT(stdout, format);
}

void log_debug(const char *format, ...)
{
    _LOG_LEVEL_CHECK(DEBUG);
    _LOG_LEVEL_PRINT(stdout, format);
}

void log_trace(const char *format, ...)
{
    _LOG_LEVEL_CHECK(TRACE);
    _LOG_LEVEL_PRINT(stdout, format);    
}
