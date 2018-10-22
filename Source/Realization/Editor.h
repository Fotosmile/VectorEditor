//
// Created by Vlad on 10.10.18.
//

#ifndef ARCHITECTURE_EDITOR_H
#define ARCHITECTURE_EDITOR_H

#include <list>
#include <memory>
#include <stack>

#include "Commands/Command.h"

class RasterImage;
class Primitive;

class Editor
{
public:
    void addPrimitive(std::shared_ptr<Primitive> primitive);
    void deletePrimitive(std::shared_ptr<Primitive> primitive);

    void addSelectedPrimitive(std::shared_ptr<Primitive> primitive);
    void deleteSelectedPrimitive(std::shared_ptr<Primitive> primitive);

    std::shared_ptr<Primitive> getPrimitiveByCoordinates(int x, int y);
    const std::list<std::shared_ptr<Primitive>> getSelectedPrimitives();

    void undo();
    void executeCommand(std::unique_ptr<Command> command);

    std::unique_ptr<RasterImage> saveToImage();
    std::unique_ptr<RasterImage> getFilteredImage(std::unique_ptr<RasterImage> image,
                                                  const std::list<std::string>& filters);

private:
    std::list<std::shared_ptr<Primitive>> m_primitives;
    std::list<std::shared_ptr<Primitive>> m_selectedPrimitives;
    std::stack<std::unique_ptr<Command>> m_commandHistory;
};


#endif //ARCHITECTURE_EDITOR_H
