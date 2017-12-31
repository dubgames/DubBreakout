cc_library(
    name = 'jpeg-9b',
    srcs = glob([
        "external/jpeg-9b/*.c",
    ],
    exclude = [
        "external/jpeg-9b/jmemdos.c",
        "external/jpeg-9b/jmemmac.c",
        "external/jpeg-9b/jmem-android.c",
        "external/jpeg-9b/wrjpgcom.c",
        "external/jpeg-9b/rdjpgcom.c",
        "external/jpeg-9b/jpegtran.c",
        "external/jpeg-9b/djpeg.c",
        "external/jpeg-9b/ckconfig.c",
        "external/jpeg-9b/cjpeg.c",
    ]),
    includes = [
        "external/jpeg-9b",
    ],
    hdrs = glob([
        "external/jpeg-9b/*.h",
    ]),
    defines = [
    ],
)

cc_library(
    name = 'libpng-1.6.32',
    srcs = glob([
        "external/libpng-1.6.32/*.c",
    ],
    exclude = [
        "external/libpng-1.6.32/example.c",
        "external/libpng-1.6.32/pngtest.c",
    ]),
    includes = [
        "external/libpng-1.6.32",
    ],
    hdrs = glob([
        "external/libpng-1.6.32/*.h",
    ]),
    deps = [
      "@com_github_madler_zlib//:z",
    ],
    defines = [
    ],
)
cc_library(
    name = "sdl_image",
    srcs = glob([
        "IMG_bmp.c",
        "IMG_gif.c",
        "IMG_jpg.c",
        "IMG_lbm.c",
        "IMG_pcx.c",
        "IMG_png.c",
        "IMG_pnm.c",
        "IMG_svg.c",
        "IMG_tga.c",
        "IMG_tif.c",
        "IMG_webp.c",
        "IMG_xcf.c",
        "IMG_xpm.c",
        "IMG_xv.c",
        "IMG_xxx.c",
        "IMG.c",
        "miniz.h",
    ], exclude = [
    ]),
    includes = [
    ],
    textual_hdrs = [
        "SDL_image.h"
    ],
  deps = [
    "@sdl2//:sdl2_headers",
    'jpeg-9b',
    'libpng-1.6.32',
  ],
  defines = [
    "SDL_IMAGE_USE_COMMON_BACKEND",
    "LOAD_PNG",
  ],
  visibility = ["//visibility:public"],
)