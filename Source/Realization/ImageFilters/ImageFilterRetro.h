//
// Created by Vlad on 21/10/18.
//

#ifndef ARCHITECTURE_IMAGEFILTERRETRO_H
#define ARCHITECTURE_IMAGEFILTERRETRO_H

#include <memory>

#include "ImageFilterDecorator.hpp"


class ImageFilterRetro : public ImageFilterDecorator
{
public:
    explicit ImageFilterRetro(std::unique_ptr<ImageFilterComponent> component);
    ~ImageFilterRetro() override = default;

    std::unique_ptr<RasterImage> getImprovedImage(std::unique_ptr<RasterImage> image) override;
};


#endif //ARCHITECTURE_IMAGEFILTERRETRO_H
