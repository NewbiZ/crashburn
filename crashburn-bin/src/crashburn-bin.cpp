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
#include <iostream>
#include <cstdlib>

#include <crashburn/crashburn.h>
#include <crashburn/engine/engine.h>
#include <crashburn/scene/scene.h>
#include <crashburn/engine/static_text.h>

class MyTestScene : public crashburn::Scene
{
public:
    MyTestScene(crashburn::Engine& engine)
        : crashburn::Scene(engine)
    {
    }

public:
    virtual bool setup()
    {
        // Clear values
        glClearColor(0.25, 0.5, 0.75, 0);
        glClearDepth(0);

        // Setup projection matrix
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho (0.0, 1024, 0.0, 768, -1.0, 1.0);

        // Setup modelview matrix
        glMatrixMode(GL_MODELVIEW);

        // Setup the text properties
        text1_.set_text("This is an example text, using special characters!");
        text1_.set_position(50., 120.);
        text1_.set_color(1., 0., 0.);

        text2_.set_text("This 1st test contains 2 numbers, and a smiley ;-)");
        text2_.set_position(50., 100.);
        text2_.set_color(0., 1., 0.);

        return true;
    }

    virtual bool cleanup()
    {
        return true;
    }

    virtual void handle_events()
    {
        // Exit when we press Escape
        if (glfwGetKey(GLFW_KEY_ESC)==GLFW_PRESS)
            engine_.stop();
    }

    virtual void update(double /*time_delta*/)
    {
    }

    virtual void render()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        text1_.render();
        text2_.render();
    }

private:
    crashburn::StaticText text1_;
    crashburn::StaticText text2_;
};

int main(int /*argc*/, char** /*argv*/)
{
    crashburn::Engine& engine = crashburn::Engine::instance();

    engine.set_scene(new MyTestScene(engine));

    engine.start();

    return EXIT_SUCCESS;
}
