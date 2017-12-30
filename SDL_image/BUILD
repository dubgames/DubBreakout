cc_library(
    name = 'jpeg-9b',
    srcs = glob([
        "external/jpeg-9b/*.c",
    ],
    exclude = [
        "external/jpeg-9b/jmemdos.c",
        "external/jpeg-9b/jmemmac.c",
        "external/jpeg-9b/jmem-android.c",
    ]),
    includes = [
        "external/jpeg-9b",
    ],
    hdrs = glob([
        "external/jpeg-9b/*.h",
    ]),
    defines = [
#      "USE_MAC_MEMMGR",
    ],
)

cc_library(
    name = 'libpng-1.6.32',
    srcs = glob([
        "external/libpng-1.6.32/*.c",
    ],
    exclude = [
        "external/libpng-1.6.32/example.c",
    ]),
    includes = [
        "external/libpng-1.6.32",
    ],
    hdrs = glob([
        "external/libpng-1.6.32/*.h",
    ]),
    defines = [
    ],
)

#cc_library(
#    name = "image_base",
#    textual_hdrs = glob([
#        "*.h",
#        "*.c",
#    ]),
#)

cc_library(
    name = "mac_sdl_image",
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
#        ".",
    ],
    textual_hdrs = [
        "SDL_image.h"
    ],
#    hdrs = glob([
#        "SDL_image.h",
#    ], exclude= [
##      "SDL_image.h",
#    ],),
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