#ifndef __CLOG_CONFIG_DEF_INCLUDED_H__
#define __CLOG_CONFIG_DEF_INCLUDED_H__

#define CLOG_LEVEL 4                         // default info
#define CLOG_TIME_FORMAT "%Y-%m-%dT%H:%M:%S" // default time format
#define CLOG_OUTBUF_LEN 128                  // default output buffer 128
#define CLOG_COLORIZE 1                      // default colorize
#define CLOG_COLOR_CRIT "255;0;0"            // red
#define CLOG_COLOR_ERRO "255;0;0"            // red
#define CLOG_COLOR_WARN "255;255;0"          // yellow
#define CLOG_COLOR_INFO "0;255;255"          // cyan
#define CLOG_COLOR_DEBU "0;128;0"            // green
#define CLOG_COLOR_TRAC "0;0;255"            // blue

#endif // __CLOG_CONFIG_DEF_INCLUDED_H__
