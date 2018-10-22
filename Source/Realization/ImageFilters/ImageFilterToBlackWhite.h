//
// Created by Vlad on 21/10/18.
//

#ifndef ARCHITECTURE_IMAGEFILTERTOBLACKWHITE_H
#define ARCHITECTURE_IMAGEFILTERTOBLACKWHITE_H

#include <memory>

#include "ImageFilterDecorator.hpp"


class ImageFilterToBlackWhite : public ImageFilterDecorator
{
public:
    explicit ImageFilterToBlackWhite(std::unique_ptr<ImageFilterComponent> component);
    ~ImageFilterToBlackWhite() override = default;

    std::unique_ptr<RasterImage> getImprovedImage(std::unique_ptr<RasterImage> image) override;
};


#endif //ARCHITECTURE_IMAGEFILTERTOBLACKWHITE_H
