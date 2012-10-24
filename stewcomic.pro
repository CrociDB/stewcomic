#-------------------------------------------------
#
# Project created by QtCreator 2012-10-14T01:35:48
#
#-------------------------------------------------

QT       += core gui webkit

TARGET = stewcomic
TEMPLATE = app


SOURCES += main.cpp\
        stewcomic.cpp \
    viewerwidget.cpp \
    fex/Zlib_Inflater.cpp \
    fex/Zip7_Extractor.cpp \
    fex/Zip_Extractor.cpp \
    fex/Rar_Extractor.cpp \
    fex/Gzip_Reader.cpp \
    fex/Gzip_Extractor.cpp \
    fex/File_Extractor.cpp \
    fex/fex.cpp \
    fex/Data_Reader.cpp \
    fex/blargg_errors.cpp \
    fex/blargg_common.cpp \
    fex/Binary_Extractor.cpp \
    zlib/zutil.c \
    zlib/inftrees.c \
    zlib/inflate.c \
    zlib/inffast.c \
    zlib/crc32.c \
    zlib/adler32.c \
    unrar/unrar.cpp \
    unrar/unrar_open.cpp \
    unrar/unrar_misc.cpp \
    unrar/unpack20.cpp \
    unrar/unpack15.cpp \
    unrar/unpack.cpp \
    unrar/unicode.cpp \
    unrar/suballoc.cpp \
    unrar/rawread.cpp \
    unrar/rarvmtbl.cpp \
    unrar/rarvm.cpp \
    unrar/model.cpp \
    unrar/getbits.cpp \
    unrar/extract.cpp \
    unrar/encname.cpp \
    unrar/crc.cpp \
    unrar/coder.cpp \
    unrar/arcread.cpp \
    unrar/archive.cpp \
    7z_C/LzmaDec.c \
    7z_C/Bra86.c \
    7z_C/Bcj2.c \
    7z_C/7zStream.c \
    7z_C/7zItem.c \
    7z_C/7zIn.c \
    7z_C/7zHeader.c \
    7z_C/7zExtract.c \
    7z_C/7zDecode.c \
    7z_C/7zCrc.c \
    7z_C/7zBuf.c \
    7z_C/7zAlloc.c \
    exceptions/ioexception.cpp \
    exceptions/exception.cpp \
    fileextractor.cpp \
    directorytools.cpp

HEADERS  += stewcomic.h \
    viewerwidget.h \
    fex/Zlib_Inflater.h \
    fex/Zip7_Extractor.h \
    fex/Zip_Extractor.h \
    fex/Rar_Extractor.h \
    fex/Gzip_Reader.h \
    fex/Gzip_Extractor.h \
    fex/File_Extractor.h \
    fex/fex.h \
    fex/Data_Reader.h \
    fex/blargg_source.h \
    fex/blargg_errors.h \
    fex/blargg_endian.h \
    fex/blargg_config.h \
    fex/blargg_common.h \
    fex/Binary_Extractor.h \
    zlib/zutil.h \
    zlib/zlib.h \
    zlib/zconf.h \
    zlib/inftrees.h \
    zlib/inflate.h \
    zlib/inffixed.h \
    zlib/inffast.h \
    zlib/crc32.h \
    unrar/unrar.h \
    unrar/unpack.hpp \
    unrar/unicode.hpp \
    unrar/suballoc.hpp \
    unrar/rawread.hpp \
    unrar/rarvm.hpp \
    unrar/rar.hpp \
    unrar/model.hpp \
    unrar/headers.hpp \
    unrar/getbits.hpp \
    unrar/encname.hpp \
    unrar/compress.hpp \
    unrar/coder.hpp \
    unrar/array.hpp \
    unrar/archive.hpp \
    7z_C/Types.h \
    7z_C/LzmaDec.h \
    7z_C/CpuArch.h \
    7z_C/Bra.h \
    7z_C/Bcj2.h \
    7z_C/7zItem.h \
    7z_C/7zIn.h \
    7z_C/7zHeader.h \
    7z_C/7zExtract.h \
    7z_C/7zDecode.h \
    7z_C/7zCrc.h \
    7z_C/7zBuf.h \
    7z_C/7zAlloc.h \
    exceptions/ioexception.h \
    exceptions/exception.h \
    fileextractor.h \
    directorytools.h

FORMS    += stewcomic.ui

OTHER_FILES += \
    img/open.png \
    zlib/zlib.txt \
    zlib/readme.txt \
    unrar/whatsnew.txt \
    unrar/technote.txt \
    unrar/readme.txt \
    unrar/license.txt \
    unrar/changes.txt \
    7z_C/readme.txt \
    7z_C/lzma.txt \
    7z_C/7zC.txt

RESOURCES += \
    res.qrc
