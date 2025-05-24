/*
 *  Logger.h
 *  Author: Milan M.
 *  Copyright (c) 2025 AMSOFTSWITCH LTD. All rights reserved.
 */

#ifndef LOGGER_H
#define LOGGER_H

#include <cstdio>
#include <cstring>

void log_debug(const char* message);
void log_error(const char* message);

inline void log_debug_fmt(const char* message) {
    log_debug(message);
}
inline void log_error_fmt(const char* message) {
    log_error(message);
}

template<typename... Args>
inline void log_debug_fmt(const char* fmt, Args... args) {
    char buf[256];
    snprintf(buf, sizeof(buf), fmt, args...);
    log_debug(buf);
}

template<typename... Args>
inline void log_error_fmt(const char* fmt, Args... args) {
    char buf[256];
    snprintf(buf, sizeof(buf), fmt, args...);
    log_error(buf);
}

#ifdef USE_DEBUG
    #define LOG_DEBUG(...) log_debug_fmt(__VA_ARGS__)
#else
    #define LOG_DEBUG(...) ((void)0)
#endif

#define LOG_ERROR(...) log_error_fmt(__VA_ARGS__)

#endif // LOGGER_H