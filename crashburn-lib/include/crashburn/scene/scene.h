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
#ifndef CRASHBURN_SCENE_H
#define CRASHBURN_SCENE_H

#include <crashburn/crashburn.h>

namespace crashburn
{

class Engine;

class CRASHBURN_EXPORT Scene
{
public:
    /*
     * Do not load resources in the Scene constructor, since Scene may
     * be created in advance but used later on. Use setup() instead
     */
    Scene(Engine& engine);

    /*
     * Do not deallocate resources in the Scene destructor, since you have
     * no guarantee on when the destructor will be called. Use cleanup()
     * instead
     */
    virtual ~Scene();

public:
    /*
     * Allow you to setup the Scene, acquire its resources, etc.
     * This is the very first method that will be called before
     * actually using this Scene
     */
    virtual bool setup();

    /*
     * Allow you to deallocate resources request by setup()
     * This is the very last method that will be used before discarding
     * this Scene
     */
    virtual bool cleanup();

    /*
     * Allow you to process events such as keyboard and mouse inputs
     */
    virtual void handle_events();

    /*
     * Allow you to compute all the data needed to render the Scene
     * The time_delta parameter is the number of seconds since the
     * previous call to update()
     */
    virtual void update(double time_delta);

    /*
     * Allow you to render the Scene
     */
    virtual void render();

protected:
    Engine& engine_;
};

} // end of namespace 'crashburn'

#endif // CRASHBURN_SCENE_H

