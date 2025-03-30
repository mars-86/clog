#include "logger.h"
#include <stdarg.h>
#include <stdio.h>
#include <time.h>

#ifdef CLOG_CUSTOM_CONFIG
#include "../config/config.h"
#else
#include "config.h"
#endif

#ifdef CLOG_COLORIZE
#define PRINT_LEVEL(stream, level)                                             \
  fprintf(stream, "\x1B[1m\x1B[38;2;%sm%s\x1B[0m", __colors[level],            \
          __levels[level]);
#else
#define PRINT_LEVEL(stream, level) fprintf(stream, "%s", __levels[level])
#endif

#define PARSE_ARGS(print_func)                                                 \
  va_list args;                                                                \
  va_start(args, format);                                                      \
  print_func;                                                                  \
  va_end(args);

char *__levels[] = {"", "CRIT", "ERRO", "WARN", "INFO", "DEBU", "TRAC"};
char *__colors[] = {"",
                    CLOG_COLOR_CRIT,
                    CLOG_COLOR_ERRO,
                    CLOG_COLOR_WARN,
                    CLOG_COLOR_INFO,
                    CLOG_COLOR_DEBU,
                    CLOG_COLOR_TRAC};

static void clog_print(FILE *stream, int level, const char *format,
                       va_list args) {
  time_t now = time(NULL);
  PRINT_LEVEL(stream, level);

#ifdef CLOG_TIME_FORMAT
  char time_fmt[CLOG_OUTBUF_LEN];
  strftime(time_fmt, CLOG_OUTBUF_LEN, CLOG_TIME_FORMAT, localtime(&now));
  fprintf(stream, "[%s] ", time_fmt);
#endif

  vfprintf(stream, format, args);
  putc('\n', stream);
}

void clog_crit(const char *format, ...) {
#if CLOG_LEVEL_CRIT <= CLOG_LEVEL
  PARSE_ARGS(clog_print(stderr, CLOG_LEVEL_CRIT, format, args));
#endif
}

void clog_erro(const char *format, ...) {
#if CLOG_LEVEL_ERRO <= CLOG_LEVEL
  PARSE_ARGS(clog_print(stderr, CLOG_LEVEL_ERRO, format, args));
#endif
}

void clog_warn(const char *format, ...) {
#if CLOG_LEVEL_WARN <= CLOG_LEVEL
  PARSE_ARGS(clog_print(stdout, CLOG_LEVEL_WARN, format, args));
#endif
}

void clog_info(const char *format, ...) {
#if CLOG_LEVEL_INFO <= CLOG_LEVEL
  PARSE_ARGS(clog_print(stdout, CLOG_LEVEL_INFO, format, args));
#endif
}

void clog_debu(const char *format, ...) {
#if CLOG_LEVEL_DEBU <= CLOG_LEVEL
  PARSE_ARGS(clog_print(stdout, CLOG_LEVEL_DEBU, format, args));
#endif
}

void clog_trac(const char *format, ...) {
#if CLOG_LEVEL_TRAC <= CLOG_LEVEL
  PARSE_ARGS(clog_print(stdout, CLOG_LEVEL_TRAC, format, args));
#endif
}
