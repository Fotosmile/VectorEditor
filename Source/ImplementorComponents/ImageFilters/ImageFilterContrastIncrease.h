//
// Created by Vlad on 21/10/18.
//

#ifndef ARCHITECTURE_IMAGEFILTERCONTRASTINCREASE_H
#define ARCHITECTURE_IMAGEFILTERCONTRASTINCREASE_H

#include <memory>

#include "IImageFilterComponent.h"

class ImageFilterContrastIncrease : public IImageFilterComponent
{
public:
    explicit ImageFilterContrastIncrease(std::unique_ptr<IImageFilterComponent> component);

    std::unique_ptr<RasterImage> getImprovedImage(std::unique_ptr<RasterImage> image) override;

private:
    std::unique_ptr<IImageFilterComponent> m_component;
};

#endif //ARCHITECTURE_IMAGEFILTERCONTRASTINCREASE_H
