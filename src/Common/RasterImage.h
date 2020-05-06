//
// Created by Vlad on 10.10.18.
//

#ifndef ARCHITECTURE_RASTER_IMAGE_H
#define ARCHITECTURE_RASTER_IMAGE_H

#include <vector>
#include <string>

class RasterImage
{
public:
    RasterImage(std::size_t width, std::size_t height);
    ~RasterImage() = default;

    void saveImage(const std::string& path);

private:
    std::size_t m_width;
    std::size_t m_height;
    std::vector<std::vector<char>> m_matrix;
};

#endif //ARCHITECTURE_RASTER_IMAGE_H
