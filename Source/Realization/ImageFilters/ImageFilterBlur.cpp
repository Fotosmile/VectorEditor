//
// Created by Vlad on 21/10/18.
//

#include "ImageFilterBlur.h"
#include "Common/RasterImage.h"

#include <iostream>

ImageFilterBlur::ImageFilterBlur(std::unique_ptr<ImageFilterComponent> component)
        : ImageFilterDecorator(std::move(component))
{
}

std::unique_ptr<RasterImage> ImageFilterBlur::getImprovedImage(std::unique_ptr<RasterImage> image)
{
    std::cout << "The image improved with a blur filter" << std::endl;
    return ImageFilterDecorator::getImprovedImage(std::move(image));
}
