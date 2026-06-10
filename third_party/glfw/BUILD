package(default_visibility = ["//visibility:public"])

# work around for includes bug regarding cc_import: https://github.com/bazelbuild/bazel/issues/19182
cc_library(
    name = "glfw3",
    deps = ["glfw3_shared"],
    include_prefix = "third_party/glfw",
)


cc_import(
    name = "glfw3_shared",
    hdrs = ["glfw3.h"],
    shared_library = "libglfw.3.dylib",
)
