#include "clog.h"
#include <stdarg.h>
#include <stdio.h>

#ifdef CLOG_CUSTOM_CONFIG
#include "config/config.h"
#else
#include "config.h"
#endif

#if CLOG_PRINT_TIME == 1
#include <time.h>
#endif

#if CLOG_COLORIZE == 1
#define print_level(stream, level)                                        \
	fprintf(stream, "\x1B[1m\x1B[38;2;%sm%s\x1B[0m", __colors[level], \
		__levels[level]);
#else
#define print_level(stream, level) fprintf(stream, "%s", __levels[level])
#endif

#define parse_args(func, stream, level, format, args) \
	do {                                          \
		va_list args;                         \
		va_start(args, format);               \
		func(stream, level, format, args);    \
		va_end(args);                         \
	} while (0);

char *__levels[] = { "", "CRIT", "ERRO", "WARN", "INFO", "DEBU", "TRAC" };
char *__colors[] = { "",
		     CLOG_COLOR_CRIT,
		     CLOG_COLOR_ERRO,
		     CLOG_COLOR_WARN,
		     CLOG_COLOR_INFO,
		     CLOG_COLOR_DEBU,
		     CLOG_COLOR_TRAC };

static void clog_print(FILE *stream, int level, const char *format,
		       va_list args)
{
#if CLOG_PRINT_LEVEL == 1
	print_level(stream, level);
#endif

#if CLOG_PRINT_TIME == 1

#ifdef CLOG_TIME_FORMAT

	time_t now = time(NULL);
	char time_fmt[CLOG_TIME_BUF_LEN];
	strftime(time_fmt, CLOG_TIME_BUF_LEN, CLOG_TIME_FORMAT,
		 localtime(&now));

#if CLOG_TIME_APPEND_MILLI == 1

	struct timespec ts;
	timespec_get(&ts, TIME_UTC);
	fprintf(stream, "[%s.%ld]: ", time_fmt, ts.tv_nsec);

#else

	fprintf(stream, "[%s]: ", time_fmt);

#endif // CLOG_TIME_APPEND_MILLI

#endif // CLOG_TIME_FORMAT

#else
	putc(' ', stream);
#endif // CLOG_PRINT_TIME

	vfprintf(stream, format, args);
	putc('\n', stream);
}

void clog_printc(int level, const char *fmt, ...)
{
	if (level <= CLOG_LEVEL)
		parse_args(clog_print, (level <= CLOG_ERRO) ? stderr : stdout,
			   level, fmt, args);
}

void clog_prints(int level, FILE *stream, const char *fmt, ...)
{
	if (level <= CLOG_LEVEL)
		parse_args(clog_print, stream, level, fmt, args);
}
