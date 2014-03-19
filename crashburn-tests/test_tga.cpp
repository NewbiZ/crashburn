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
#include <crashburn/loader/tga.h>

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cassert>
#include <cstring>

void check_texture(const std::string& input, const std::string& output)
{
    crashburn::TextureInfo ti;
    crashburn::load_tga(input, ti);

    std::ifstream ifs(output.c_str(), std::ios::binary);

    std::size_t header_size = sizeof(ti.target) + sizeof(ti.level) +
                              sizeof(ti.internalFormat) + sizeof(ti.width) +
                              sizeof(ti.height) + sizeof(ti.format) +
                              sizeof(ti.type);
    std::size_t data_size = ti.width*ti.height*(ti.format==GL_RGBA?4:3);

    ifs.seekg(0, std::ios::end);
    std::size_t size = ifs.tellg();

    assert(size == header_size + data_size &&
           "error: reference and loaded tga have different sizes");
    ifs.seekg(0);
    
    GLenum   target;
    GLint    level;
    GLint    internalFormat;
    GLsizei  width;
    GLsizei  height;
    GLenum   format;
    GLenum   type;

    ifs.read((char*)&target,         sizeof(GLenum));
    ifs.read((char*)&level,          sizeof(GLint));
    ifs.read((char*)&internalFormat, sizeof(GLint));
    ifs.read((char*)&width,          sizeof(GLsizei));
    ifs.read((char*)&height,         sizeof(GLsizei));
    ifs.read((char*)&format,         sizeof(GLenum));
    ifs.read((char*)&type,           sizeof(GLenum));

    assert(ti.target         == target &&
           ti.level          == level &&
           ti.internalFormat == internalFormat &&
           ti.width          == width &&
           ti.height         == height &&
           ti.format         == format &&
           ti.type           == type &&
           "error: header reference and loaded are different");

    uint8_t* data = new uint8_t[data_size];
    ifs.read((char*)data, data_size);
    assert(std::memcmp(ti.data, data, data_size)==0 &&
           "error: data reference and data loaded are different");

    delete [] data;
    delete [] ti.data;
}

int main( int /*argc*/, char** /*argv*/ )
{
    check_texture("data/test_tga_ctc24.tga",
                  "data/test_tga_ctc24.tga.out");

    check_texture("data/test_tga_ctc32.tga",
                  "data/test_tga_ctc32.tga.out");
    
    check_texture("data/test_tga_utc24.tga",
                  "data/test_tga_utc24.tga.out");
    
    check_texture("data/test_tga_utc32.tga",
                  "data/test_tga_utc32.tga.out");
  
    return EXIT_SUCCESS;
}

