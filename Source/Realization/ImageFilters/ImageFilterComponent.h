//
// Created by Vlad on 21/10/18.
//

#ifndef ARCHITECTURE_IMAGEFILTERCOMPONENT_H
#define ARCHITECTURE_IMAGEFILTERCOMPONENT_H

#include <memory>

class RasterImage;

class ImageFilterComponent
{
public:
    virtual ~ImageFilterComponent() = default;

    virtual std::unique_ptr<RasterImage> getImprovedImage(std::unique_ptr<RasterImage> image) = 0;
};


#endif //ARCHITECTURE_IMAGEFILTERCOMPONENT_H
