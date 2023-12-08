#ifndef LOGLIBRARY_H
#define LOGLIBRARY_H

#include <syslog.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LINE_SIZE 500

char buffer[MAX_LINE_SIZE + 1];

#define LOUD getenv("LOUD_LOG") != NULL
#define DEBUG_ENABLED getenv("DEBUG_ENABLED") =! NULL

#define LOUD_ECHO   \
if (LOUD) { \
        snprintf(buffer, MAX_LINE_SIZE, fmt __VA_OPT__(,) __VA_ARGS__); \
        std::cout << buffer << std::endl; \
}

#define DEBUG(fmt, ...)  \
if (DEBUG_ENABLED) { \
        syslog(LOG_DEBUG, fmt __VA_OPT__(,) __VA_ARGS__); \
        LOUD_ECHO \
}

#define LOG(fmt, ...)  \
syslog(LOG_INFO, fmt __VA_OPT__(,) __VA_ARGS__); \
    LOUD_ECHO

#define ERROR(fmt, ...)  \
    syslog(LOG_ERR, fmt __VA_OPT__(,) __VA_ARGS__); \
    LOUD_ECHO


#endif // LOGLIBRARY_H
