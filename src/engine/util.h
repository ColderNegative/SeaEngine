#pragma once

#include <stdio.h>

// error and log macros, source: JDH youtube
// do while used to ensure correct syntax in all use cases
#define ERROR_EXIT(fmt, ...)      do {fprintf(stderr, "ERROR: %s:%d:%s(): " fmt "\n", __FILE__, __LINE__, __func__, ##__VA_ARGS__); exit(-1);} while (0)
#define ERROR_RETURN(R, fmt, ...) do {fprintf(stderr, "ERROR: %s:%d:%s(): " fmt "\n", __FILE__, __LINE__, __func__, ##__VA_ARGS__); return R;} while (0)
#define LOG_INFO(fmt, ...)        do {fprintf(stdout, "INFO: %s:%d:%s(): " fmt "\n", __FILE__, __LINE__, __func__, ##__VA_ARGS__);} while (0)

