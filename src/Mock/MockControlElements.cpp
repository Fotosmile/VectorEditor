//
// Created by Vlad on 20/10/18.
//

#include <iostream>

#include "MockControlElements.h"
#include "Common/CommonDefines.h"
#include "Common/RasterImage.h"
#include "Primitive/IPrimitive.h"

MockControlElements& MockControlElements::Instance()
{
    static MockControlElements mockLinuxControlElements;
    return mockLinuxControlElements;
}

void MockControlElements::registerButtonClick(const std::function<void()>& callback)
{
    m_buttons.push_back(callback);
}

void MockControlElements::registerLabelClick(const std::function<void()>& callback)
{
    m_labels.push_back(callback);
}

void MockControlElements::registerLineEditInput(const std::function<void(const std::string&)>& callback)
{
    m_lineEdits.push_back(callback);
}

void MockControlElements::registerWindowClick(const std::function<void(int, int)>& callback)
{
    m_windows.push_back(callback);
}

void MockControlElements::runButtonClick(std::size_t index)
{
    m_buttons.at(index)();
}

void MockControlElements::runLabelClick(std::size_t index)
{
    m_labels.at(index)();
}

void MockControlElements::runLineEditInput(std::size_t index, const std::string& input)
{
    m_lineEdits.at(index)(input);
}

void MockControlElements::runWindowClick(std::size_t index, int x, int y)
{
    m_windows.at(index)(x, y);
}

std::unique_ptr<RasterImage> MockControlElements::getRasterImageFromPrimitives(
        const std::list<std::shared_ptr<IPrimitive>>& primitives)
{
    std::unique_ptr<RasterImage> image = std::make_unique<RasterImage>(defaultWindowWidth, defaultWindowHeight);
    std::cout << "Specific actions of converting promitives to the raster image" << std::endl;

    return std::move(image);
}