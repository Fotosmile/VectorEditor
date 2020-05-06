//
// Created by Vlad on 10.10.18.
//

#include <iostream>

#include "RasterImage.h"

RasterImage::RasterImage(std::size_t width, std::size_t height)
    : m_width(width),
    m_height(height),
    m_matrix(height)
{
    for(size_t i = 0; i < m_height; ++i)
    {
        m_matrix.at(i) = std::vector<char>(m_width);
    }
}

void RasterImage::saveImage(const std::string& path)
{
    std::cout << "Saving raster image to " << path << std::endl;
}