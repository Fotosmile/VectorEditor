//
// Created by Vlad on 21/10/18.
//

#include "ImageFilterRetro.h"
#include "Common/RasterImage.h"

#include <iostream>

ImageFilterRetro::ImageFilterRetro(std::unique_ptr<IImageFilterComponent> component)
        : m_component(std::move(component))
{
}

std::unique_ptr<RasterImage> ImageFilterRetro::getImprovedImage(std::unique_ptr<RasterImage> image)
{
    std::cout << "The image improved with a retro filter" << std::endl;
    return m_component->getImprovedImage(std::move(image));
}
