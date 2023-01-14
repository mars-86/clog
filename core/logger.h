#ifndef __KADMOS_CORE_LOGGER_H_INCLUDED__
#define __KADMOS_CORE_LOGGER_H_INCLUDED__

void log_critical(const char *format, ...);
void log_error(const char *format, ...);
void log_warn(const char *format, ...);
void log_info(const char *format, ...);
void log_debug(const char *format, ...);
void log_trace(const char *format, ...);

#endif // __KADMOS_CORE_LOGGER_H_INCLUDED__
