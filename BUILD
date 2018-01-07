filegroup(
    name = "assets",
    srcs = glob(["assets/**"]),
    visibility = ["//visibility:public"],
)

load("@build_bazel_rules_apple//apple:versioning.bzl", "apple_bundle_version")
apple_bundle_version(
    name = "AppVersion",
    build_version = "1.0",
)

load("@build_bazel_rules_apple//apple:macos.bzl", "macos_command_line_application")
macos_command_line_application(
    name = "cli",
    bundle_id = "com.dubgames.breakout",
    infoplists = [":Cli-Info.plist"],
    minimum_os_version = "10.11",
    version = ":AppVersion",
    deps = [
        "//breakout:breakout",
        "@sdl2//:mac_sdl2",
    ],
)

load("@build_bazel_rules_apple//apple:macos.bzl", "macos_application")
macos_application(
    name = "app",
    bundle_id = "com.dubgames.breakout",
    infoplists = [":App-Info.plist"],
    minimum_os_version = "10.11",
    version = ":AppVersion",
    deps = [
        "//breakout:breakout",
        "@sdl2//:mac_sdl2",
    ],
    additional_contents = {
        ":assets": "Resources",
    },
)