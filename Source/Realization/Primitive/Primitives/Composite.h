//
// Created by Vlad on 10.10.18.
//

#ifndef ARCHITECTURE_COMPOSITE_H
#define ARCHITECTURE_COMPOSITE_H

#include <list>
#include <memory>

#include "Primitive/Primitive.h"

class Composite : public Primitive
{
public:
    explicit Composite(const std::list<std::shared_ptr<Primitive>>& primitives);
    ~Composite() override = default;
    Composite(const Composite& other);

    std::unique_ptr<Primitive> clone() override;

    void setColor(const Color& color) override;
    void move(int x, int y) override;
    void changeSize(int x, int y) override;
    bool containsPoint(int x, int y) override;
    const Color& getColor() override;

    const std::list<std::shared_ptr<Primitive>>& getChildren();

private:
    std::list<std::shared_ptr<Primitive>> m_children;
};


#endif //ARCHITECTURE_COMPOSITE_H
