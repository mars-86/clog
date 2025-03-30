#ifndef __CLOG_CORE_LOGGER_H_INCLUDED__
#define __CLOG_CORE_LOGGER_H_INCLUDED__

#define CLOG_LEVEL_NONE 0
#define CLOG_LEVEL_CRIT 1
#define CLOG_LEVEL_ERRO 2
#define CLOG_LEVEL_WARN 3
#define CLOG_LEVEL_INFO 4
#define CLOG_LEVEL_DEBU 5
#define CLOG_LEVEL_TRAC 6
#define CLOG_LEVEL_LALL 7

void clog_crit(const char *format, ...);
void clog_erro(const char *format, ...);
void clog_warn(const char *format, ...);
void clog_info(const char *format, ...);
void clog_debu(const char *format, ...);
void clog_trac(const char *format, ...);

#endif // __CLOG_CORE_LOGGER_H_INCLUDED__
