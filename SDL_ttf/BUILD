
#objc_framework(
#    name = "freetype_framework",
#    framework_imports = glob([
#        "Xcode/Frameworks/FreeType.framework/**"
#    ]),
##    is_dynamic = 1,
#)

objc_library(
    name = "mac_sdl_ttf",
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
       "@sdl2//:mac_sdl2",
#       "freetype_framework",
    ],
    copts = [
    ],
    visibility = ["//visibility:public"],
)
