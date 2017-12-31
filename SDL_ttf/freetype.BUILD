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
     #['builds/unix/ftsystem.c',] +
     ['src/%s/%s.c' % (m,m) for m in MODULES] +
     ['src/%s/ft%s.c' % (m,m) for m in FTMODULES] +
     #['src/gzip/*.c'] +
     #[
     #   'src/gzip/inflate.c',
     #   'src/gzip/zutil.h',
     #   'src/gzip/zconf.h',
     #   'src/gzip/infblock.h',
     #   'src/gzip/infblock.c',
     #   'src/gzip/inftrees.h',
     #   'src/gzip/inftrees.c',
     #   'src/gzip/infutil.h',
     #   'src/gzip/infutil.c',
     #] +
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
      'src/base/ftsystem.c',
      #'builds/unix/ftsystem.c',
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
    defines = [
        "FT2_BUILD_LIBRARY",
        'HAVE_FCNTL_H',
        'HAVE_UNISTD_H',
        'FT_CONFIG_OPTION_USE_ZLIB',
        'FT_CONFIG_OPTION_SYSTEM_ZLIB',
        #'NO_INFLATE_MASK',
        #'__MVS__',
    ],
    deps = [
        "freetype_base",
        "@com_github_madler_zlib//:z",
    ],
    copts = [
    ],
    visibility = ["//visibility:public"],
)
