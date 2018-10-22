//
// Created by Vlad on 21/10/18.
//

#include "ImageFilterToBlackWhite.h"
#include "Common/RasterImage.h"

#include <iostream>

ImageFilterToBlackWhite::ImageFilterToBlackWhite(std::unique_ptr<ImageFilterComponent> component)
        : ImageFilterDecorator(std::move(component))
{
}

std::unique_ptr<RasterImage> ImageFilterToBlackWhite::getImprovedImage(std::unique_ptr<RasterImage> image)
{
    std::cout << "The image improved with a black-white filter" << std::endl;
    return ImageFilterDecorator::getImprovedImage(std::move(image));
}