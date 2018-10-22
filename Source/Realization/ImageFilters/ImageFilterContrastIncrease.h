//
// Created by Vlad on 21/10/18.
//

#ifndef ARCHITECTURE_IMAGEFILTERCONTRASTINCREASE_H
#define ARCHITECTURE_IMAGEFILTERCONTRASTINCREASE_H

#include <memory>

#include "ImageFilterDecorator.hpp"


class ImageFilterContrastIncrease : public ImageFilterDecorator
{
public:
    explicit ImageFilterContrastIncrease(std::unique_ptr<ImageFilterComponent> component);
    ~ImageFilterContrastIncrease() override = default;

    std::unique_ptr<RasterImage> getImprovedImage(std::unique_ptr<RasterImage> image) override;
};


#endif //ARCHITECTURE_IMAGEFILTERCONTRASTINCREASE_H
