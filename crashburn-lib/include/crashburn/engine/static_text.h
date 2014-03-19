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
#ifndef CRASHBURN_STATIC_TEXT_H
#define CRASHBURN_STATIC_TEXT_H

#include <crashburn/crashburn.h>

#include <string>

#include <GL/glfw.h>

namespace crashburn
{

class CRASHBURN_EXPORT StaticText
{

public:
    StaticText(); 
    StaticText(const std::string& text); 
    ~StaticText();

public:
    void resize(float size);
    void set_text(const std::string& text);
    void set_color(float r, float g, float b);
    void set_position(float x, float y);

public:
    float              size() const;
    const std::string& text() const;
    const vec3f_t&     color() const;
    const vec2f_t&     position() const;

public:
    void render() const;

private:
    vec2f_t     position_;
    vec3f_t     color_;
    float       size_;
    std::string text_;   
    
};

} // end of namespace crashburn

#endif // CRASHBURN_STATIC_TEXT_H
