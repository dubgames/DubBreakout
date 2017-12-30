
objc_library(
  name = "breakout",
  srcs = glob([
      "*.cpp",
      "*.h"
  ]),
  deps = [
     "@sdl2//:mac_sdl2",
     "@sdl_image//:mac_sdl_image",
     "@sdl_ttf//:mac_sdl_ttf",
     "@sdl_mixer//:mac_sdl_mixer",
  ],
  hdrs = [
  ],
  includes = [
#     "mac_sdl2/SDL.h",
#     "mac_sdl_image/SDL_image.h",
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
#    app_icons = ["//examples/resources:MacAppIcon.xcassets"],
    bundle_id = "com.example.hello-world",
    infoplists = [":Info.plist"],
    minimum_os_version = "10.11",
    version = ":HelloWorldVersion",
    deps = [
        ":breakout",
#             "@sdl2//:mac_sdl2",
#             "@sdl_image//:mac_sdl_image",
#             "@sdl_ttf//:mac_sdl_ttf",
#             "@sdl_mixer//:mac_sdl_mixer",
          ],
       sdk_frameworks = [
#            "AVFoundation",
#            "AVKit",
#            "CoreAudio",
#            "IOKit",

        ],
)


macos_command_line_application(
    name = "CommandLine",
    bundle_id = "com.example.command-line",
    infoplists = [":Info.plist"],
    minimum_os_version = "10.11",
    version = ":CommandLineVersion",
    deps = [":Sources"],
)
