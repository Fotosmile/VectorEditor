//
// Created by Vlad on 21/10/18.
//

#ifndef ARCHITECTURE_IMAGEFILTERHELPERS_H
#define ARCHITECTURE_IMAGEFILTERHELPERS_H

#include <algorithm>
#include <string>
#include <memory>
#include <list>

#include "IImageFilterComponent.h"
#include "ImageFilterBlur.h"
#include "ImageFilterContrastIncrease.h"
#include "ImageFilterLightning.h"
#include "ImageFilterRetro.h"
#include "ImageFilterToBlackWhite.h"

static std::unique_ptr<IImageFilterComponent> createDecorator(const std::string& filterName,
                                                      std::unique_ptr<IImageFilterComponent> source)
{
    std::string lowerFilter = filterName;
    std::transform(lowerFilter.begin(), lowerFilter.end(), lowerFilter.begin(), ::tolower);

    if (lowerFilter == "blur")
    {
        return std::make_unique<ImageFilterBlur>(std::move(source));
    }
    else if (lowerFilter == "contrast")
    {
        return std::make_unique<ImageFilterContrastIncrease>(std::move(source));
    }
    else if (lowerFilter == "lightning")
    {
        return std::make_unique<ImageFilterLightning>(std::move(source));
    }
    else if (lowerFilter == "retro")
    {
        return std::make_unique<ImageFilterRetro>(std::move(source));
    }
    else if (lowerFilter == "blackwhite")
    {
        return std::make_unique<ImageFilterToBlackWhite>(std::move(source));
    }
    return std::move(source);
}

static std::list<std::string> split(const std::string& s, char seperator)
{
    std::list<std::string> output;

    std::string::size_type prev_pos = 0, pos = 0;

    while ((pos = s.find(seperator, pos)) != std::string::npos)
    {
        std::string substring(s.substr(prev_pos, pos - prev_pos));

        output.push_back(substring);

        prev_pos = ++pos;
    }

    output.push_back(s.substr(prev_pos, pos - prev_pos)); // Last word

    return output;
}

#endif //ARCHITECTURE_IMAGEFILTERHELPERS_H
