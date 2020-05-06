//
// Created by Vlad on 09/10/18.
//

#ifndef ARCHITECTURE_AbstractionState_H
#define ARCHITECTURE_AbstractionState_H

#include <string>

#include "Common/Color.h"

class AbstractionState
{
public:
    enum class StateType {Creating, Editing};

    virtual ~AbstractionState() = default;

    virtual StateType getCurrentState() = 0;

    virtual void select(int x, int y);
    virtual void unselect(int x, int y);
    virtual void move(int x, int y);
    virtual void changeSize(int x, int y);
    virtual void changeColor(const Color& color);
    virtual void deleteSelected();

    virtual void create(const std::string& primitiveType);
    virtual void copy();
    virtual void group();
};

#endif //ARCHITECTURE_AbstractionState_H
