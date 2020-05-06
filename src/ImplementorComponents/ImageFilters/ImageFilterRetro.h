//
// Created by Vlad on 21/10/18.
//

#ifndef ARCHITECTURE_IMAGEFILTERRETRO_H
#define ARCHITECTURE_IMAGEFILTERRETRO_H

#include <memory>

#include "IImageFilterComponent.h"

class ImageFilterRetro : public IImageFilterComponent
{
public:
    explicit ImageFilterRetro(std::unique_ptr<IImageFilterComponent> component);

    std::unique_ptr<RasterImage> getImprovedImage(std::unique_ptr<RasterImage> image) override;

private:
    std::unique_ptr<IImageFilterComponent> m_component;
};

#endif //ARCHITECTURE_IMAGEFILTERRETRO_H
