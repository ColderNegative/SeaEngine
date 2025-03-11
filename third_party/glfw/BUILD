package(default_visibility = ["//visibility:public"])

# work around for includes bug regarding cc_import: https://github.com/bazelbuild/bazel/issues/19182
cc_library(
    name = "glfw3",
    includes = ["include"],
    deps = ["glfw3_shared"],
)


cc_import(
    name = "glfw3_shared",
    hdrs = ["include/glfw3.h"],
    shared_library = "libglfw.3.dylib",
)