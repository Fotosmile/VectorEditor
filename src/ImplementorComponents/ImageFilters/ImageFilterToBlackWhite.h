//
// Created by Vlad on 21/10/18.
//

#ifndef ARCHITECTURE_IMAGEFILTERTOBLACKWHITE_H
#define ARCHITECTURE_IMAGEFILTERTOBLACKWHITE_H

#include <memory>

#include "IImageFilterComponent.h"

class ImageFilterToBlackWhite : public IImageFilterComponent
{
public:
    explicit ImageFilterToBlackWhite(std::unique_ptr<IImageFilterComponent> component);

    std::unique_ptr<RasterImage> getImprovedImage(std::unique_ptr<RasterImage> image) override;

private:
    std::unique_ptr<IImageFilterComponent> m_component;
};

#endif //ARCHITECTURE_IMAGEFILTERTOBLACKWHITE_H
