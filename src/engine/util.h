#pragma once

#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "types.h"

// error and log macros, source: JDH youtube
// do while used to ensure correct syntax in all use cases
#define ERROR_EXIT(fmt, ...)      do {fprintf(stderr, "ERROR: %s:%d:%s(): " fmt "\n", __FILE__, __LINE__, __func__, ##__VA_ARGS__); exit(-1);} while (0)
#define ERROR_RETURN(R, fmt, ...) do {fprintf(stderr, "ERROR: %s:%d:%s(): " fmt "\n", __FILE__, __LINE__, __func__, ##__VA_ARGS__); return R;} while (0)
#define LOG_INFO(fmt, ...)        do {fprintf(stdout, "INFO: %s:%d:%s(): " fmt "\n", __FILE__, __LINE__, __func__, ##__VA_ARGS__);} while (0)

static inline const char *read_file(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    char info_log[512];

    if (!file) {
        strerror_r(errno, info_log, 512);
        fclose(file);
        ERROR_RETURN(NULL, "failed to load file %s: %s", file_path, info_log);
    }

    fseek(file, 0, SEEK_END);
    i64 file_size = ftell(file);
    rewind(file);

    char *buffer = malloc(file_size);

    if (!fread(buffer, 1, file_size, file)) {
        strerror_r(errno, info_log, 512);
        fclose(file);
        ERROR_RETURN(NULL, "file failed to read into buffer %s: %s", file_path, info_log);
    }

    LOG_INFO("file read successfully:\n%s", buffer);

    fclose(file);
    
    return buffer;
}
