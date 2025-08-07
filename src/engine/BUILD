package(default_visibility = ["//visibility:public"])

cc_library(
    name = "util",
    hdrs = ["util.h"],
)

cc_library(
    name = "types",
    hdrs = ["types.h"],
)

cc_library(
    name = "array",
    srcs = ["array.c"],
    hdrs = ["array.h"],
    deps = [
        "//src/engine:types",
        "//src/engine:util",
    ],
)


