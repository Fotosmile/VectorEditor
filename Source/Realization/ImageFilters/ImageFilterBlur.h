//
// Created by Vlad on 21/10/18.
//

#ifndef ARCHITECTURE_IMAGEFILTERBLUR_H
#define ARCHITECTURE_IMAGEFILTERBLUR_H

#include <memory>

#include "ImageFilterDecorator.hpp"


class ImageFilterBlur : public ImageFilterDecorator
{
public:
    explicit ImageFilterBlur(std::unique_ptr<ImageFilterComponent> component);
    ~ImageFilterBlur() override = default;

    std::unique_ptr<RasterImage> getImprovedImage(std::unique_ptr<RasterImage> image) override;
};


#endif //ARCHITECTURE_IMAGEFILTERBLUR_H
