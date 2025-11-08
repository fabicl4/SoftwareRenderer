#ifndef RLOGGER_H
#define RLOGGER_H

#include <stdarg.h>
#include <stdbool.h>

typedef enum {
    RLOG_LEVEL_TRACE,
    RLOG_LEVEL_DEBUG,
    RLOG_LEVEL_INFO,
    RLOG_LEVEL_WARN,
    RLOG_LEVEL_ERROR,
    RLOG_LEVEL_FATAL
} RLogLevel;

void rlog_init(void);
void rlog_shutdown(void);

void rlog_set_level(RLogLevel level);
RLogLevel rlog_get_level(void);

void rlog_log(RLogLevel level, const char *fmt, ...);

typedef void (*RLogOutputFn)(RLogLevel, const char *msg, void *user_data);

// custom output
void rlog_set_output(RLogOutputFn fn, void *user_data);

void rlog_to_file(const char *path);

/* Helpers for convenience */
#define RLOG_TRACE(...) rlog_log(RLOG_LEVEL_TRACE, __VA_ARGS__)
#define RLOG_DEBUG(...) rlog_log(RLOG_LEVEL_DEBUG, __VA_ARGS__)
#define RLOG_INFO(...)  rlog_log(RLOG_LEVEL_INFO,  __VA_ARGS__)
#define RLOG_WARN(...)  rlog_log(RLOG_LEVEL_WARN,  __VA_ARGS__)
#define RLOG_ERROR(...) rlog_log(RLOG_LEVEL_ERROR, __VA_ARGS__)
#define RLOG_FATAL(...) rlog_log(RLOG_LEVEL_FATAL, __VA_ARGS__)

#endif
