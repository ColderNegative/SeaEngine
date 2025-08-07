package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "main",
    srcs = ["main.c"],
    deps = [
        "//src/engine/render:window",
        "//src/engine/input:keyboard",
        "//src/engine/input:mouse",
        "//src/engine/render:mesh",
        "//src/engine/render:shader",
        "//src/engine:array",
        "//third_party/glad:glad",
    ],
)
