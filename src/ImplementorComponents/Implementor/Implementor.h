//
// Created by Vlad on 10.10.18.
//

#ifndef ARCHITECTURE_EDITOR_H
#define ARCHITECTURE_EDITOR_H

#include <list>
#include <memory>
#include <stack>

#include "IImplementor.h"

class RasterImage;
class IPrimitive;

class Implementor : public IImplementor
{
public:
    void addPrimitive(std::shared_ptr<IPrimitive> primitive) override;
    void deletePrimitive(std::shared_ptr<IPrimitive> primitive) override;

    void addSelectedPrimitive(std::shared_ptr<IPrimitive> primitive) override;
    void deleteSelectedPrimitive(std::shared_ptr<IPrimitive> primitive) override;

    std::shared_ptr<IPrimitive> getPrimitiveByCoordinates(int x, int y) override;
    const std::list<std::shared_ptr<IPrimitive>> getSelectedPrimitives() override;

    void undo() override;
    void executeCommand(std::unique_ptr<ICommand> command) override;

    void saveWithFilters(const std::string& filtersStr) override;

private:
    std::unique_ptr<RasterImage> saveToImage();
    std::unique_ptr<RasterImage> getFilteredImage(std::unique_ptr<RasterImage> image,
                                                  const std::list<std::string>& filters);

private:
    std::list<std::shared_ptr<IPrimitive>> m_primitives;
    std::list<std::shared_ptr<IPrimitive>> m_selectedPrimitives;
    std::stack<std::unique_ptr<ICommand>> m_commandHistory;
};


#endif //ARCHITECTURE_EDITOR_H
