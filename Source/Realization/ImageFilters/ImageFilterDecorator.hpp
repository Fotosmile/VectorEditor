//
// Created by Vlad on 21/10/18.
//

#ifndef ARCHITECTURE_IMAGEFILTERDECORATOR_HPP
#define ARCHITECTURE_IMAGEFILTERDECORATOR_HPP

#include <memory>

#include "ImageFilterComponent.h"

class ImageFilterDecorator : public ImageFilterComponent
{
public:
    explicit ImageFilterDecorator(std::unique_ptr<ImageFilterComponent> component)
            : m_component(std::move(component))
    {
    }

    std::unique_ptr<RasterImage> getImprovedImage(std::unique_ptr<RasterImage> image) override
    {
        return m_component->getImprovedImage(std::move(image));
    }

private:
    std::unique_ptr<ImageFilterComponent> m_component;
};


#endif //ARCHITECTURE_IMAGEFILTERDECORATOR_HPP
