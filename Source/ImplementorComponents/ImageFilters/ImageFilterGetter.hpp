//
// Created by Vlad on 21/10/18.
//

#ifndef ARCHITECTURE_IMAGEFILTERGETTER_HPP
#define ARCHITECTURE_IMAGEFILTERGETTER_HPP

#include "IImageFilterComponent.h"
#include "Common/RasterImage.h"

class ImageFilterGetter : public IImageFilterComponent
{
public:
    std::unique_ptr<RasterImage> getImprovedImage(std::unique_ptr<RasterImage> image) override;
};

std::unique_ptr<RasterImage> ImageFilterGetter::getImprovedImage(std::unique_ptr<RasterImage> image)
{
    return image;
}


#endif //ARCHITECTURE_IMAGEFILTERGETTER_HPP
