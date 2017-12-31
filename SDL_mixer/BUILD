cc_library(
     name = 'libvorbis-1.3.5',
     srcs = glob([
         "external/libvorbis-1.3.5/lib/**/*.c",
     ],
     exclude = [
         "external/libvorbis-1.3.5/lib/psytune.c",
#         "external/libvorbis-1.3.5/lib/sharedbook.c",
         "external/libvorbis-1.3.5/lib/tone.c",
         "external/libvorbis-1.3.5/lib/barkmel.c",
     ]),
     includes = [
         "external/libvorbis-1.3.5/include",
         "external/libvorbis-1.3.5/lib",
         "external/libvorbis-1.3.5/lib/modes",
     ],
     hdrs = glob([
         "external/libvorbis-1.3.5/lib/**/*.h",
         "external/libvorbis-1.3.5/include/vorbis/*.h",
     ]),
     defines = [
     ],
     deps = [
        "libogg-1.3.2",
        'libvorbisidec-1.2.1',
    ],
 )

genrule(
  name='endian_h',
  outs=['include/endian.h'],
  cmd='echo "#include <sys/types.h>" > $(OUTS) && echo "GENNED"'
)

cc_library(
     name = 'libvorbisidec-1.2.1',
     srcs = glob([
         "external/libvorbisidec-1.2.1/*.c",
     ],
     exclude = [         
#         "external/libvorbisidec-1.2.1/codebook.c",
         "external/libvorbisidec-1.2.1/iseeking_example.c",
         "external/libvorbisidec-1.2.1/ivorbisfile_example.c",
     ]),
     includes = [
         "include",
     ],
     hdrs = glob([
         "external/libvorbisidec-1.2.1/*.h",
     ],
     exclude = [
#         "external/libvorbisidec-1.2.1/block.h",
     ],)
     +         ["include/endian.h"]
      ,
     defines = [
         "_USE_MATH_DEFINES" # MSVC M_PI
     ],
     deps = [
         "libogg-1.3.2",
    ],
    copts = [
#        "-isystem /usr/include",
#        "-isystem /usr/include/machine",
    ],
 )

cc_library(
     name = 'libogg-1.3.2',
     srcs = glob([
         "external/libogg-1.3.2/src/bitwise.c",
         "external/libogg-1.3.2/src/framing.c",
     ],
     exclude = [
     ]),
     includes = [
         "external/libogg-1.3.2/include",
     ],
     hdrs = glob([
         "external/libogg-1.3.2/include/ogg/*.h",
     ]),
     defines = [
     ],
 )

cc_library(
    name = "sdl_mixer",
    srcs = glob([
        "*.c",
        "native_midi/*.c",
    ]),
    includes = [
        "./",
        "native_midi/*.h",
    ],
    hdrs = glob([
        "**/*.h",
    ]),
    deps = [
       "@sdl2//:sdl2_headers",
       "libvorbis-1.3.5",
    ],
    defines = [
        "MUSIC_OGG",
    ],
    visibility = ["//visibility:public"],
)