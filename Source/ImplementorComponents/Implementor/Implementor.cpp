
//
// Created by Vlad on 10.10.18.
//
#include <stdexcept>
#include <memory>
#include <iostream>
#include <algorithm>
#include <string>

#include "Implementor.h"
#include "Common/CommonDefines.h"
#include "Common/RasterImage.h"
#include "ImageFilters/ImageFilterGetter.hpp"
#include "ImageFilters/ImageFilterHelpers.hpp"
#include "Primitive/IPrimitive.h"
#include "Mock/MockControlElements.h"

void Implementor::addPrimitive(std::shared_ptr<IPrimitive> primitive)
{
    m_primitives.push_back(primitive);
}

void Implementor::deletePrimitive(std::shared_ptr<IPrimitive> primitive)
{
    m_selectedPrimitives.erase(std::remove(m_selectedPrimitives.begin(), m_selectedPrimitives.end(), primitive),
                               m_selectedPrimitives.end());
    m_primitives.erase(std::remove(m_primitives.begin(), m_primitives.end(), primitive),
                       m_primitives.end());
}

void Implementor::addSelectedPrimitive(std::shared_ptr<IPrimitive> primitive)
{
    if (std::find(m_primitives.begin(), m_primitives.end(), primitive) == m_primitives.end())
    {
        throw std::runtime_error("Failed to select not a familiar primitive");
    }
    m_selectedPrimitives.push_back(primitive);
}

void Implementor::deleteSelectedPrimitive(std::shared_ptr<IPrimitive> primitive)
{
    if (std::find(m_primitives.begin(), m_primitives.end(), primitive) == m_primitives.end())
    {
        throw std::runtime_error("Failed to remove not a familiar primitive");
    }
    m_selectedPrimitives.erase(std::remove(m_selectedPrimitives.begin(), m_selectedPrimitives.end(), primitive),
                               m_selectedPrimitives.end());
}

std::shared_ptr<IPrimitive> Implementor::getPrimitiveByCoordinates(int x, int y)
{
    auto it = std::find_if(m_primitives.begin(), m_primitives.end(),
                           [x, y](const std::shared_ptr<IPrimitive>& primitive)
                           { return primitive->containsPoint(x, y); });
    if (it == m_primitives.end())
    {
        throw std::range_error("Failed to find a primitive with coordinates " +
                               std::to_string(x) + ", " + std::to_string(y));
    }

    return *it;
}

const std::list<std::shared_ptr<IPrimitive>> Implementor::getSelectedPrimitives()
{
    return m_selectedPrimitives;
}

void Implementor::undo()
{
    std::unique_ptr<ICommand> command = std::move(m_commandHistory.top());
    m_commandHistory.pop();

    try
    {
        command->undo();
    }
    catch (const std::exception& exc)
    {
        std::cout << "Failed to undo the command: " << exc.what() << std::endl;
    }
}

void Implementor::executeCommand(std::unique_ptr<ICommand> command)
{
    try
    {
        command->execute();
        m_commandHistory.push(std::move(command));
        std::cout << "Number of primitives: " << m_primitives.size() << std::endl;
        std::cout << "Number of selected primitives: " << m_selectedPrimitives.size() << std::endl;
    }
    catch (const std::exception& exc)
    {
        std::cout << "Failed to execute the command: " << exc.what() << std::endl;
    }
}

std::unique_ptr<RasterImage> Implementor::saveToImage()
{
    return MockControlElements::Instance().getRasterImageFromPrimitives(m_primitives);
}

std::unique_ptr<RasterImage> Implementor::getFilteredImage(std::unique_ptr<RasterImage> image,
                                                      const std::list<std::string>& filters)
{
    std::unique_ptr<IImageFilterComponent> source = std::make_unique<ImageFilterGetter>();

    for (const std::string& filter : filters)
    {
        source = createDecorator(filter, std::move(source));
    }
    return source->getImprovedImage(std::move(image));
}


void Implementor::saveWithFilters(const std::string &filtersStr)
{
    const std::list<std::string> filters = split(filtersStr, ';');
    std::unique_ptr<RasterImage> rasterImage = getFilteredImage(saveToImage(), filters);
    rasterImage->saveImage(getDefaultSavePath() + getDefaultSaveName());
}