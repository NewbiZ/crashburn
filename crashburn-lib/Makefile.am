# Copyright (C) 2014 Aurelien Vallee
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy of
# this software and associated documentation files (the "Software"), to deal in
# the Software without restriction, including without limitation the rights to
# use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
# of the Software, and to permit persons to whom the Software is furnished to do
# so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
# FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
# COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
# IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
# CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

AM_CXXFLAGS = \
	-std=c++11 \
	-pedantic \
	-fno-exceptions \
	-fstack-protector -Wl,-z,relro -Wl,-z,now -Wformat-security \
	-ffast-math \
	-W -Wall \
	-Werror \
	-Wpointer-arith \
	-Winit-self \
	-Wformat=2 \
	-Wcast-align \
	-Wlogical-op \
	-Wshadow \
	-fvisibility=hidden \
	-Wl,--discard-all \
	-g \
	-rdynamic \
	-I$(top_srcdir)/crashburn-lib/include

lib_LTLIBRARIES = \
	libcrashburn.la

libcrashburn_la_SOURCES = \
	$(top_srcdir)/crashburn-lib/src/crashburn.cpp \
	$(top_srcdir)/crashburn-lib/src/engine/engine.cpp \
	$(top_srcdir)/crashburn-lib/src/engine/static_text.cpp \
	$(top_srcdir)/crashburn-lib/src/loader/tga.cpp \
	$(top_srcdir)/crashburn-lib/src/scene/scene.cpp

engineincludedir = $(pkgincludedir)/engine
loaderincludedir = $(pkgincludedir)/loader
sceneincludedir = $(pkgincludedir)/scene

pkginclude_HEADERS = \
	$(top_srcdir)/crashburn-lib/include/crashburn/crashburn.h

engineinclude_HEADERS = \
	$(top_srcdir)/crashburn-lib/include/crashburn/engine/engine.h \
	$(top_srcdir)/crashburn-lib/include/crashburn/engine/static_text.h

sceneinclude_HEADERS = \
	$(top_srcdir)/crashburn-lib/include/crashburn/scene/scene.h

loaderinclude_HEADERS = \
	$(top_srcdir)/crashburn-lib/include/crashburn/loader/loader.h \
	$(top_srcdir)/crashburn-lib/include/crashburn/loader/tga.h

libcrashburn_la_LDFLAGS = \
	-no-undefined \
	-version-info $(LTVER)

libcrashburn_la_CPPFLAGS = \
	${libglfw_CPPFLAGS}

libcrashburn_la_CFLAGS = \
	${libglfw_CFLAGS}

libcrashburn_la_LIBADD = \
	${libglfw_LIBS}

MAINTAINERCLEANFILES = \
	Makefile.in
