#ifndef __CLOG_H_INCLUDED__
#define __CLOG_H_INCLUDED__

#include <stdio.h>

#define CLOG_NONE 0
#define CLOG_CRIT 1
#define CLOG_ERRO 2
#define CLOG_WARN 3
#define CLOG_INFO 4
#define CLOG_DEBU 5
#define CLOG_TRAC 6
#define CLOG_LALL 7

void clog_printc(int level, const char *__restrict__ fmt, ...);
void clog_prints(int level, FILE *__restrict__ stream,
		 const char *__restrict__ fmt, ...);

#endif // __CLOG_CORE_LOGGER_H_INCLUDED__
