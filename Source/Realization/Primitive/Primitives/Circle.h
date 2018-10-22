//
// Created by Vlad on 10.10.18.
//

#ifndef ARCHITECTURE_CIRCLE_H
#define ARCHITECTURE_CIRCLE_H

#include <memory>

#include "Primitive/Primitive.h"

class Circle : public Primitive
{
public:
    Circle();
    ~Circle() override = default;
    Circle(const Circle& other);

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
    int m_x;
    int m_y;
    int m_radius;
};


#endif //ARCHITECTURE_CIRCLE_H
