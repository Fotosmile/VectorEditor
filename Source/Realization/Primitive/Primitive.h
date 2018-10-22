//
// Created by Vlad on 10.10.18.
//

#ifndef ARCHITECTURE_PRIMITIVE_H
#define ARCHITECTURE_PRIMITIVE_H

#include <memory>

#include "Common/Color.h"

class Painter;

class Primitive
{
public:
    virtual ~Primitive() = default;

    virtual std::unique_ptr<Primitive> clone() = 0;
    virtual void setColor(const Color& color) = 0;
    virtual void move(int x, int y) = 0;
    virtual void changeSize(int x, int y) = 0;
    virtual bool containsPoint(int x, int y) = 0;
    virtual const Color& getColor() = 0;

protected:
    static Painter& getPainter();
};

#endif //ARCHITECTURE_PRIMITIVE_H
