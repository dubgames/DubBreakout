cc_library(
    name = "sdl_ttf",
    srcs = glob([
        "*.c",
    ]),
    includes = [
        "./",
    ],
    hdrs = glob([
        "*.h",
    ]),
    deps = [
       "@freetype//:freetype",
       "@sdl2//:sdl2_headers",
    ],
    copts = [
    ],
    visibility = ["//visibility:public"],
)
