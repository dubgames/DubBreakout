package(default_visibility = ["//visibility:public"])


cc_binary(
    name = "windows",
    srcs = glob([
          "*.cpp",
          "*.h"
    ]),
    deps = [
       "@sdl2//:win_sdl2",
       "@sdl_image//:sdl_image",
       "@sdl_ttf//:sdl_ttf",
       "@sdl_mixer//:sdl_mixer",
    ],
)

cc_library(
    name = "breakout",
    srcs = glob([
          "*.cpp",
          "*.h"
    ]),
    deps = [
       "@sdl2//:sdl2_headers",
       "@sdl_image//:sdl_image",
       "@sdl_ttf//:sdl_ttf",
       "@sdl_mixer//:sdl_mixer",
    ],
)

#objc_library(
#  name = "mac",
#  srcs = glob([
#      "*.cpp",
#      "*.h"
#  ]),
#  deps = [
#     "@sdl2//:mac_sdl2",
#     "@sdl_image//:sdl_image",
#     "@sdl_ttf//:sdl_ttf",
#     "@sdl_mixer//:sdl_mixer",
#  ],
#)