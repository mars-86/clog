#ifndef __CLOG_CUSTOM_CONFIG_INCLUDED_H__
#define __CLOG_CUSTOM_CONFIG_INCLUDED_H__

#define CLOG_LEVEL 6 // info
#define CLOG_TIME_FORMAT "%Y-%m-%dT%H:%M:%S"
#define CLOG_TIME_APPEND_MILLI 1

/* default time format output buffer */
#define CLOG_TIME_BUF_LEN 128

/* default colorize levels */
#define CLOG_COLORIZE 0

/* default level colors */

/* default critical red */
#define CLOG_COLOR_CRIT "255;0;0"

/* default error red */
#define CLOG_COLOR_ERRO "255;0;0"

/* default warning yellow */
#define CLOG_COLOR_WARN "255;255;0"

/* default info cyan */
#define CLOG_COLOR_INFO "0;255;255"

/* default debug green */
#define CLOG_COLOR_DEBU "0;128;0"

/* default trace blue */
#define CLOG_COLOR_TRAC "0;0;255"

#endif // __CLOG_CUSTOM_CONFIG_INCLUDED_H__
