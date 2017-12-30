cc_library(
  name = "freetype_base",
  textual_hdrs = glob(['src/**/*.c', 'src/**/*.h']),
)

genrule(
  name='ftconfig_h',
  outs=['include/ftconfig.h'],
  cmd='echo "#include <freetype/config/ftconfig.h>" > $(OUTS)'
)


MODULES = [
  'autofit',
  'bdf',
  'cff',
  'gxvalid',
  'otvalid',
  'pcf',
  'pfr',
  'psaux',
  'pshinter',
  'psnames',
  'raster',
  'sfnt',
  'smooth',
  'truetype',
  'type1',
  'type42',
]

FTMODULES = [
  'base',
  'bzip2',
  'cache',
  'gzip',
  'lzw',
]


cc_library(
    name = "freetype",
    srcs = glob(
     ['builds/unix/ftsystem.c',] +
     ['src/%s/%s.c' % (m,m) for m in MODULES] +
     ['src/%s/ft%s.c' % (m,m) for m in FTMODULES] +
     ['src/gzip/inflate.c','src/gzip/zutil.h',] +
     ['src/cid/type1cid.c',
      'src/winfonts/winfnt.c',
      'src/base/ftinit.c',
      'src/base/ftbitmap.c',
      'src/base/ftfstype.c',
      'src/base/ftmm.c',
      'src/base/ftfntfmt.c',
      'src/base/ftlcdfil.c',
      'src/base/fttype1.c',
      'src/base/ftglyph.c',
      'src/base/ftstroke.c',
      'builds/unix/ftsystem.c',
     ],
    ),
    includes = [
        "include",
    ],
    hdrs = glob([
        'include/**/*.h',
        'include/*.h']
        ) +
        ['include/ftconfig.h'],
#    hdrs = glob([
#        "include/**/*.h",
#        "builds/unix/*.h",
#        "src/*.h",
#        "src/**/*.h",
#    ]),
    defines = [
        "FT2_BUILD_LIBRARY",
        'HAVE_FCNTL_H',
        'HAVE_UNISTD_H',
        'FT_CONFIG_OPTION_USE_ZLIB',
        'FT_CONFIG_OPTION_SYSTEM_ZLIB',
    ],
    deps = [
        "freetype_base",
        "@com_github_madler_zlib//:z",
    ],
    copts = [
        #"-Iexternal/freetype/include",
        #"-Iexternal/freetype/include/freetype/config",
    ],
    visibility = ["//visibility:public"],
)
