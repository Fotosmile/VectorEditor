//
// Created by Vlad on 10.10.18.
//

#ifndef ARCHITECTURE_LINE_H
#define ARCHITECTURE_LINE_H

#include <memory>

#include "Primitive/IPrimitive.h"
#include "Primitive/Painter/IPainter.h"

class Line : public IPrimitive
{
public:
    Line();
    Line(const Line& other);

    std::unique_ptr<IPrimitive> clone() override;
    void setColor(const Color& color) override;
    void move(int x, int y) override;
    void changeSize(int x, int y) override;
    bool containsPoint(int x, int y) override;
    const Color& getColor() override;

private:
    void update();

private:
    Color m_color;
    int m_x1;
    int m_y1;
    int m_x2;
    int m_y2;
    std::unique_ptr<IPainter> m_painter;
};

#endif //ARCHITECTURE_LINE_H
