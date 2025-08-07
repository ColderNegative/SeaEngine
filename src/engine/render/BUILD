package(default_visibility = ["//visibility:public"])

cc_library(
    name = "window",
    srcs = ["window.c"],
    hdrs = ["window.h"],
    deps = [
        "//third_party/glfw:glfw3",
        "//third_party/glad:glad",
        "//src/engine:util",
        "//src/engine:types"
    ],
)

cc_library(
    name = "shader",
    srcs = ["shader.c"],
    hdrs = ["shader.h"],
    deps = [
        "//src/engine:util",
        "//src/engine:types",
        "//third_party/glad:glad",
    ],
)

cc_library(
    name = "mesh",
    srcs = ["mesh.c"],
    hdrs = ["mesh.h"],
    deps = [
        "//src/engine:array",
        "//src/engine:types",
        "//src/engine/render:shader",
        "//third_party/glad:glad",
        "//third_party/cglm:cglm",
    ],
)
