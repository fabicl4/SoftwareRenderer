#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#include <rlogger/rlogger.h>

typedef struct LogState
{
    RLogLevel current_level;

    bool log_to_file;
    // output
    FILE *out;

} LogState;

static struct LogState state;

/* *
 * DECLARATIONS PRIVATE FUNCTIONS
 * */
static void _set_color(RLogLevel level);
static void _reset_color(void);
static const char *_level_to_string(RLogLevel level);
static void _set_default();

/* *
 *  FUNCTION IMPLEMENTATION
 * */
void rlog_init(void)
{
    state.current_level = RLOG_LEVEL_INFO;
}

void rlog_shutdown(void)
{
    // Future: close files, free memory, etc.
}

void rlog_set_level(RLogLevel level) { state.current_level = level; }
RLogLevel rlog_get_level(void) { return state.current_level; }

void rlog_log(RLogLevel level, const char *fmt, ...)
{
    if (level < state.current_level)
        return;

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char time_buf[32];
    strftime(time_buf, sizeof(time_buf), "%H:%M:%S", t);

    // output only same level or higher.

    set_color(level);
    fprintf(stdout, "[%s] %-5s | ", time_buf, level_to_string(level));

    va_list args;
    va_start(args, fmt);
    vfprintf(stdout, fmt, args);
    va_end(args);

    reset_color();
    fprintf(stdout, "\n");

    if (level == RLOG_LEVEL_FATAL)
    {
        fflush(stdout);
        abort(); // or custom behavior
    }
}

#ifdef _WIN32
#include <windows.h>
#endif

// only console mode
static void _set_color(RLogLevel level)
{
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    switch (level)
    {
    case RLOG_LEVEL_TRACE:
        SetConsoleTextAttribute(hConsole, 8);
        break; // Gray
    case RLOG_LEVEL_DEBUG:
        SetConsoleTextAttribute(hConsole, 7);
        break; // White
    case RLOG_LEVEL_INFO:
        SetConsoleTextAttribute(hConsole, 10);
        break; // Green
    case RLOG_LEVEL_WARN:
        SetConsoleTextAttribute(hConsole, 14);
        break; // Yellow
    case RLOG_LEVEL_ERROR:
        SetConsoleTextAttribute(hConsole, 12);
        break; // Red
    case RLOG_LEVEL_FATAL:
        SetConsoleTextAttribute(hConsole, 15 | 4);
        break; // Bright red
    }
#else
    switch (level)
    {
    case RLOG_LEVEL_TRACE:
        printf("\033[90m");
        break; // Gray
    case RLOG_LEVEL_DEBUG:
        printf("\033[37m");
        break; // White
    case RLOG_LEVEL_INFO:
        printf("\033[32m");
        break; // Green
    case RLOG_LEVEL_WARN:
        printf("\033[33m");
        break; // Yellow
    case RLOG_LEVEL_ERROR:
        printf("\033[31m");
        break; // Red
    case RLOG_LEVEL_FATAL:
        printf("\033[1;31m");
        break; // Bold Red
    }
#endif
}

static void _reset_color(void)
{
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7);
#else
    printf("\033[0m");
#endif
}

static const char *_level_to_string(RLogLevel level)
{
    switch (level)
    {
    case RLOG_LEVEL_TRACE:
        return "TRACE";
    case RLOG_LEVEL_DEBUG:
        return "DEBUG";
    case RLOG_LEVEL_INFO:
        return "INFO";
    case RLOG_LEVEL_WARN:
        return "WARN";
    case RLOG_LEVEL_ERROR:
        return "ERROR";
    case RLOG_LEVEL_FATAL:
        return "FATAL";
    default:
        return "UNKNOWN";
    }
}

static void _set_default()
{
    state.current_level = RLOG_LEVEL_INFO;
    state.log_to_file = false;
    state.out = NULL;
}