//
// Created by Vlad on 10.10.18.
//

#ifndef ARCHITECTURE_RECTANGLE_H
#define ARCHITECTURE_RECTANGLE_H

#include <memory>

#include "Primitive/Primitive.h"

class Rectangle : public Primitive
{
public:
    Rectangle();
    ~Rectangle() override = default;
    Rectangle(const Rectangle& other);

    std::unique_ptr<Primitive> clone() override;
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
};


#endif //ARCHITECTURE_RECTANGLE_H
