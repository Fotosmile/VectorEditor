//
// Created by Vlad on 20/10/18.
//

#ifndef ARCHITECTURE_PRIMITIVEHELPERS_HPP
#define ARCHITECTURE_PRIMITIVEHELPERS_HPP

#include <algorithm>
#include <string>

#include "Primitive/Primitives/Line.h"
#include "Primitive/Primitives/Rectangle.h"
#include "Primitive/Primitives/Circle.h"

static std::unique_ptr<Primitive> createPrimitive(const std::string& typeName)
{
    std::string lowerType = typeName;
    std::transform(lowerType.begin(), lowerType.end(), lowerType.begin(), ::tolower);

    if (lowerType == "line")
    {
        return std::make_unique<Line>();
    }
    else if (lowerType == "rectangle")
    {
        return std::make_unique<Rectangle>();
    }
    else if (lowerType == "circle")
    {
        return std::make_unique<Circle>();
    }
    throw std::invalid_argument("Got a failed primitive type string");
}

#endif //ARCHITECTURE_PRIMITIVEHELPERS_HPP
