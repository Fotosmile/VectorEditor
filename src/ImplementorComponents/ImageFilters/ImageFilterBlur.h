//
// Created by Vlad on 21/10/18.
//

#ifndef ARCHITECTURE_IMAGEFILTERBLUR_H
#define ARCHITECTURE_IMAGEFILTERBLUR_H

#include <memory>

#include "IImageFilterComponent.h"

class ImageFilterBlur : public IImageFilterComponent
{
public:
    explicit ImageFilterBlur(std::unique_ptr<IImageFilterComponent> component);

    std::unique_ptr<RasterImage> getImprovedImage(std::unique_ptr<RasterImage> image) override;

private:
    std::unique_ptr<IImageFilterComponent> m_component;
};

#endif //ARCHITECTURE_IMAGEFILTERBLUR_H
