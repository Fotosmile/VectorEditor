//
// Created by Vlad on 21/10/18.
//

#include "ImageFilterLightning.h"
#include "Common/RasterImage.h"

#include <iostream>

ImageFilterLightning::ImageFilterLightning(std::unique_ptr<ImageFilterComponent> component)
        : ImageFilterDecorator(std::move(component))
{
}

std::unique_ptr<RasterImage> ImageFilterLightning::getImprovedImage(std::unique_ptr<RasterImage> image)
{
    std::cout << "The image improved with a lightning filter" << std::endl;
    return ImageFilterDecorator::getImprovedImage(std::move(image));
}