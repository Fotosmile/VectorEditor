//
// Created by Vlad on 21/10/18.
//

#include "ImageFilterContrastIncrease.h"
#include "Common/RasterImage.h"

#include <iostream>

ImageFilterContrastIncrease::ImageFilterContrastIncrease(std::unique_ptr<IImageFilterComponent> component)
        : m_component(std::move(component))
{
}

std::unique_ptr<RasterImage> ImageFilterContrastIncrease::getImprovedImage(std::unique_ptr<RasterImage> image)
{
    std::cout << "The image improved with a contrast increase filter" << std::endl;
    return m_component->getImprovedImage(std::move(image));
}
