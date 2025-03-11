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
    name = "global",
    hdrs = ["global.h"],
    srcs = ["global.c"],
    deps = [
        "//src/engine/render:window",
    ],
)