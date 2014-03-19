/*
Copyright (C) 2014 Aurelien Vallee

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#ifndef CRASHBURN_H
#define CRASHBURN_H

#include <string>

#include <GL/glfw.h>

#define CRASHBURN_VERSION_API_MAJOR 3
#define CRASHBURN_VERSION_API_MINOR 0
#define CRASHBURN_VERSION_API_PATCH 0

#define CRASHBURN_VERSION_ABI_CURRENT  0
#define CRASHBURN_VERSION_ABI_REVISION 0
#define CRASHBURN_VERSION_ABI_AGE      0

#define CRASHBURN_EXPORT __attribute__ ((visibility("default")))
#define CRASHBURN_HIDDEN __attribute__ ((visibility("hidden")))

namespace crashburn {

CRASHBURN_EXPORT
const std::string& version();

typedef float vec2f_t[2];
typedef float vec3f_t[3];
typedef float vec4f_t[4];

typedef double vec2d_t[2];
typedef double vec3d_t[3];
typedef double vec4d_t[4];

} // namespace crashburn

#endif // CRASHBURN_H

