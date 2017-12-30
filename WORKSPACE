
http_archive(
    name = "build_bazel_rules_apple",
    strip_prefix = "rules_apple-0.2.0",
    urls = ["https://github.com/bazelbuild/rules_apple/archive/0.2.0.tar.gz"],
)

new_http_archive(
    name = "sdl2",
    build_file = "SDL2/BUILD",
    url = "https://www.libsdl.org/release/SDL2-2.0.7.zip",
    strip_prefix = "SDL2-2.0.7",
    sha256 = "feab4ef539a3e88b9da63a3e0a0df474397e7739f2e5f0526549d3af6c0959b8",
)

new_http_archive(
    name = "sdl_image",
    build_file = "SDL_image/BUILD",
    url = "https://www.libsdl.org/projects/SDL_image/release/SDL2_image-2.0.2.zip",
    strip_prefix = "SDL2_image-2.0.2",
    sha256 = "7c3158ca1bf84ef041bcf55ea237306684caf6b70f4303ee7e1f0777bfba55a2",
)

new_http_archive(
    name = "sdl_ttf",
    build_file = "SDL_ttf/BUILD",
    url = "https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-2.0.14.zip",
    strip_prefix = "SDL2_ttf-2.0.14",
    sha256 = "ad7a7d2562c19ad2b71fa4ab2e76f9f52b3ee98096c0a7d7efbafc2617073c27",
)

# taken from: https://github.com/google/ced/blob/master/WORKSPACE
#new_http_archive(
#    name = "freetype",
#    urls = [
#        "https://download.savannah.gnu.org/releases/freetype/freetype-2.8.1.tar.bz2",
#    ],
#    strip_prefix = "freetype-2.8.1",
#    build_file = "SDL_ttf/BUILD.freetype",
#)

new_http_archive(
    name = "freetype",
    build_file = "SDL_ttf/freetype.BUILD",
    url = "https://download.savannah.gnu.org/releases/freetype/freetype-2.4.0.tar.bz2",
    strip_prefix = "freetype-2.4.0",
    sha256 = "98d64deaa4f4ed743852ad15d31ec2a044dc3e0a425551c10168215088c6d9b3",
)

# taken from: https://github.com/google/ced/blob/master/WORKSPACE
new_http_archive(
    name = "com_github_madler_zlib",
    build_file = "SDL_ttf/BUILD.zlib",
    strip_prefix = "zlib-cacf7f1d4e3d44d871b605da3b647f07d718623f",
    url = "https://github.com/madler/zlib/archive/cacf7f1d4e3d44d871b605da3b647f07d718623f.tar.gz",
)

new_http_archive(
    name = "sdl_mixer",
    build_file = "SDL_mixer/BUILD",
    url = "https://www.libsdl.org/projects/SDL_mixer/release/SDL2_mixer-2.0.2.zip",
    strip_prefix = "SDL2_mixer-2.0.2",
    sha256 = "ecd687e74b0aa33800812dffa2fac2714260bc91d17866d307c5379181c0a9c5",
)


