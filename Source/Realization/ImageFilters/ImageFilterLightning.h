//
// Created by Vlad on 21/10/18.
//

#ifndef ARCHITECTURE_IMAGEFILTERLIGHTNING_H
#define ARCHITECTURE_IMAGEFILTERLIGHTNING_H

#include <memory>

#include "ImageFilterDecorator.hpp"

class ImageFilterLightning : public ImageFilterDecorator
{
public:
    explicit ImageFilterLightning(std::unique_ptr<ImageFilterComponent> component);
    ~ImageFilterLightning() override = default;

    std::unique_ptr<RasterImage> getImprovedImage(std::unique_ptr<RasterImage> image) override;
};


#endif //ARCHITECTURE_IMAGEFILTERLIGHTNING_H
