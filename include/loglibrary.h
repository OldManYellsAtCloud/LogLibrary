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


template<typename... fmtArgs>
void DBG(const std::format_string<fmtArgs...> fmt, fmtArgs&&... args)
{
    if (DEBUG_ENABLED){
        syslog(LOG_DEBUG, std::vformat(fmt.get(), std::make_format_args(args...)).c_str());
        if (LOUD){
            std::cout << std::vformat(fmt.get(), std::make_format_args(args...)) << std::endl;
        }
    }
}


template<typename... fmtArgs>
void LOG(const std::format_string<fmtArgs...> fmt, fmtArgs&&... args)
{
    syslog(LOG_INFO, std::vformat(fmt.get(), std::make_format_args(args...)).c_str());
    if (LOUD){
        std::cout << std::vformat(fmt.get(), std::make_format_args(args...)) << std::endl;
    }
}


template<typename... fmtArgs>
void ERROR(const std::format_string<fmtArgs...> fmt, fmtArgs&&... args)
{
    syslog(LOG_ERR, std::vformat(fmt.get(), std::make_format_args(args...)).c_str());
    if (LOUD){
        std::cerr << std::vformat(fmt.get(), std::make_format_args(args...)) << std::endl;
    }
}
#endif // LOGLIBRARY_H
