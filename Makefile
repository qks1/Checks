#############################################################################
# Makefile for building: checks
# Generated by qmake (2.01a) (Qt 4.8.1) on: Sun Aug 12 06:07:59 2012
# Project:  checks.pro
# Template: app
# Command: /usr/bin/qmake -spec /usr/share/qt4/mkspecs/linux-g++-32 -o Makefile checks.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_NO_DEBUG -DQT_SQL_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m32 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m32 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-32 -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtSql -I/usr/include/qt4 -I. -I.
LINK          = g++
LFLAGS        = -m32 -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/i386-linux-gnu -lQtSql -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = doctable.cpp \
		main.cpp \
		mainwindow.cpp \
		mtable.cpp \
		myproxymodel.cpp \
		settingsdialog.cpp moc_doctable.cpp \
		moc_mainwindow.cpp \
		moc_mtable.cpp \
		moc_myproxymodel.cpp \
		moc_settingsdialog.cpp
OBJECTS       = doctable.o \
		main.o \
		mainwindow.o \
		mtable.o \
		myproxymodel.o \
		settingsdialog.o \
		moc_doctable.o \
		moc_mainwindow.o \
		moc_mtable.o \
		moc_myproxymodel.o \
		moc_settingsdialog.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		checks.pro
QMAKE_TARGET  = checks
DESTDIR       = 
TARGET        = checks

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: checks.pro  /usr/share/qt4/mkspecs/linux-g++-32/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/i386-linux-gnu/libQtSql.prl \
		/usr/lib/i386-linux-gnu/libQtGui.prl \
		/usr/lib/i386-linux-gnu/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++-32 -o Makefile checks.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/i386-linux-gnu/libQtSql.prl:
/usr/lib/i386-linux-gnu/libQtGui.prl:
/usr/lib/i386-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++-32 -o Makefile checks.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/checks1.0.0 || $(MKDIR) .tmp/checks1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/checks1.0.0/ && $(COPY_FILE) --parents doctable.h mainwindow.h mtable.h myproxymodel.h settingsdialog.h .tmp/checks1.0.0/ && $(COPY_FILE) --parents doctable.cpp main.cpp mainwindow.cpp mtable.cpp myproxymodel.cpp settingsdialog.cpp .tmp/checks1.0.0/ && (cd `dirname .tmp/checks1.0.0` && $(TAR) checks1.0.0.tar checks1.0.0 && $(COMPRESS) checks1.0.0.tar) && $(MOVE) `dirname .tmp/checks1.0.0`/checks1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/checks1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_doctable.cpp moc_mainwindow.cpp moc_mtable.cpp moc_myproxymodel.cpp moc_settingsdialog.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_doctable.cpp moc_mainwindow.cpp moc_mtable.cpp moc_myproxymodel.cpp moc_settingsdialog.cpp
moc_doctable.cpp: myproxymodel.h \
		doctable.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) doctable.h -o moc_doctable.cpp

moc_mainwindow.cpp: mtable.h \
		myproxymodel.h \
		doctable.h \
		mainwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

moc_mtable.cpp: myproxymodel.h \
		mtable.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mtable.h -o moc_mtable.cpp

moc_myproxymodel.cpp: myproxymodel.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) myproxymodel.h -o moc_myproxymodel.cpp

moc_settingsdialog.cpp: settingsdialog.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) settingsdialog.h -o moc_settingsdialog.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

doctable.o: doctable.cpp doctable.h \
		myproxymodel.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o doctable.o doctable.cpp

main.o: main.cpp mtable.h \
		myproxymodel.h \
		mainwindow.h \
		doctable.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		mtable.h \
		myproxymodel.h \
		doctable.h \
		settingsdialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

mtable.o: mtable.cpp mtable.h \
		myproxymodel.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mtable.o mtable.cpp

myproxymodel.o: myproxymodel.cpp myproxymodel.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o myproxymodel.o myproxymodel.cpp

settingsdialog.o: settingsdialog.cpp settingsdialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o settingsdialog.o settingsdialog.cpp

moc_doctable.o: moc_doctable.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_doctable.o moc_doctable.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_mtable.o: moc_mtable.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mtable.o moc_mtable.cpp

moc_myproxymodel.o: moc_myproxymodel.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_myproxymodel.o moc_myproxymodel.cpp

moc_settingsdialog.o: moc_settingsdialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_settingsdialog.o moc_settingsdialog.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

