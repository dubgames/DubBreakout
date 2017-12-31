
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
#        linkopts = [
#          '-link user32.lib',
#          '-link Gdi32.lib',
##          '-Wl,User32.lib',
##          '-Wl,Gdi32.lib',
#        ],
)

objc_library(
  name = "breakout",
  srcs = glob([
      "*.cpp",
      "*.h"
  ]),
  deps = [
     "@sdl2//:mac_sdl2",
     "@sdl_image//:sdl_image",
     "@sdl_ttf//:sdl_ttf",
     "@sdl_mixer//:sdl_mixer",
  ],
  hdrs = [
  ],
  includes = [
  ],
  resources = glob([
    "assets/*"
  ]),
)

load("@build_bazel_rules_apple//apple:versioning.bzl", "apple_bundle_version")

apple_bundle_version(
    name = "HelloWorldVersion",
    build_version = "1.0",
)

#load("@build_bazel_rules_apple//apple:macos.bzl", "macos_application")
load(
    "@build_bazel_rules_apple//apple:macos.bzl",
    "macos_command_line_application",
)

macos_command_line_application(
    name = "HelloWorld",
    bundle_id = "com.example.hello-world",
    infoplists = [":Info.plist"],
    minimum_os_version = "10.11",
    version = ":HelloWorldVersion",
    deps = [
        ":breakout",
    ],
)
