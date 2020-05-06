//
// Created by Vlad on 21/10/18.
//

#ifndef ARCHITECTURE_IMAGEFILTERLIGHTNING_H
#define ARCHITECTURE_IMAGEFILTERLIGHTNING_H

#include <memory>

#include "IImageFilterComponent.h"

class ImageFilterLightning : public IImageFilterComponent
{
public:
    explicit ImageFilterLightning(std::unique_ptr<IImageFilterComponent> component);

    std::unique_ptr<RasterImage> getImprovedImage(std::unique_ptr<RasterImage> image) override;

private:
    std::unique_ptr<IImageFilterComponent> m_component;
};

#endif //ARCHITECTURE_IMAGEFILTERLIGHTNING_H
