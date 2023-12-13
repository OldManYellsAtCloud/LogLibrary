#ifndef LOGLIBRARY_H
#define LOGLIBRARY_H

#include <syslog.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

#include <format>

#define LOUD getenv("LOUD_LOG") != NULL
#define DEBUG_ENABLED getenv("DEBUG_ENABLED") != NULL


#define DEBUG(fmt, ...)  \
    if (DEBUG_ENABLED) { \
        syslog(LOG_DEBUG, std::vformat(fmt, std::make_format_args(__VA_ARGS__)).c_str()); \
        if (LOUD) { \
            std::cout << std::vformat(fmt, std::make_format_args(__VA_ARGS__)) << std::endl; \
        } \
    }

#define LOG(fmt, ...)  \
    syslog(LOG_INFO, std::vformat(fmt, std::make_format_args(__VA_ARGS__)).c_str()); \
    if (LOUD) { \
        std::cout << std::vformat(fmt, std::make_format_args(__VA_ARGS__)) << std::endl; \
    }

#define ERROR(fmt, ...)  \
    syslog(LOG_ERR, std::vformat(fmt, std::make_format_args(__VA_ARGS__)).c_str()); \
    if (LOUD) { \
        std::cerr << std::vformat(fmt, std::make_format_args(__VA_ARGS__)) << std::endl; \
    }


#endif // LOGLIBRARY_H
