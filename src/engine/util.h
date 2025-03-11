#pragma once

#include <stdio.h>

// error macros, source: JDH youtube
// do while used to ensure correct syntax in all use cases

#define ERROR_EXIT(...)      do {fprintf(stderr, __VA_ARGS__); exit(-1);} while (0)
#define ERROR_RETURN(R, ...) do {fprintf(stderr, __VA_ARGS__); return R;} while (0)