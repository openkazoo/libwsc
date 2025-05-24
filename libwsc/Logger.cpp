/*
 *  Logger.cpp
 *  Author: Milan M.
 *  Copyright (c) 2025 AMSOFTSWITCH LTD. All rights reserved.
 */

#include "Logger.h"
#include <ctime>
#include <sys/time.h>

/**
 * \brief Logs a debug message with timestamp to stdout.
 * 
 * \param message The debug message to log (null-terminated string)
 * 
 * \details Formats the log message as:
 * `[DEBUG HH:MM:SS.mmm] message`
 * where:
 * - HH:MM:SS is the local time
 * - mmm is milliseconds precision
 * 
 * \note Uses gettimeofday() for high-resolution timing and localtime_r() for thread-safety.
 * The output is written to stdout using printf().
 */
void log_debug(const char* message) {
    struct timeval tv;
    gettimeofday(&tv, nullptr);
    time_t now = tv.tv_sec;
    struct tm tm_info;
    localtime_r(&now, &tm_info);

    char time_buf[20];
    strftime(time_buf, sizeof(time_buf), "%H:%M:%S", &tm_info);

    printf("[DEBUG %s.%03ld] %s\n", time_buf, tv.tv_usec / 1000, message);
}

/**
 * \brief Logs an error message with timestamp to stdout.
 * 
 * \param message The error message to log (null-terminated string)
 * 
 * \details Formats the log message as:
 * `[ERROR HH:MM:SS.mmm] message`
 * where:
 * - HH:MM:SS is the local time
 * - mmm is milliseconds precision
 * 
 * \note Uses the same timestamping mechanism as log_debug() for consistency.
 * The output is written to stdout using printf().
 * 
 * \see log_debug()
 */
void log_error(const char* message) {
    struct timeval tv;
    gettimeofday(&tv, nullptr);
    time_t now = tv.tv_sec;
    struct tm tm_info;
    localtime_r(&now, &tm_info);

    char time_buf[20];
    strftime(time_buf, sizeof(time_buf), "%H:%M:%S", &tm_info);

    printf("[ERROR %s.%03ld] %s\n", time_buf, tv.tv_usec / 1000, message);
}