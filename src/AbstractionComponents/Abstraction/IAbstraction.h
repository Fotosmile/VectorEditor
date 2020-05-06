//
// Created by Vlad on 09/10/18.
//

#ifndef ARCHITECTURE_IMEDIATOR_H
#define ARCHITECTURE_IMEDIATOR_H

#include <string>

#include "Color.h"

class IAbstraction
{
public:
    virtual ~IAbstraction() = default;

    virtual void deleteSelected() = 0;
    virtual void copy() = 0;
    virtual void group() = 0;
    virtual void move(int x, int y) = 0;
    virtual void changeSize(int x, int y) = 0;
    virtual void changeColor(const Color& color) = 0;
    virtual void create(const std::string& primitiveName) = 0;
    virtual void saveWithFilters(const std::string& filters) = 0;
    virtual void onClicked(int x, int y) = 0;
};


#endif //ARCHITECTURE_IMEDIATOR_H
