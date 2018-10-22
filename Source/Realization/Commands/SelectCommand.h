//
// Created by Vlad on 17/10/18.
//

#ifndef ARCHITECTURE_SELECTCOMMAND_H
#define ARCHITECTURE_SELECTCOMMAND_H

#include <memory>

#include "Command.h"

class Primitive;
class Editor;

class SelectCommand : public Command
{
public:
    SelectCommand(std::shared_ptr<Editor> editor, int x, int y);
    ~SelectCommand() override = default;

    void undo() override;
    void execute() override;

private:
    bool m_commandWasExecuted;
    std::shared_ptr<Editor> m_editor;
    std::shared_ptr<Primitive> m_selectedPrimitive;
    const int m_selectedXCoordinate;
    const int m_selectedYCoordinate;
};


#endif //ARCHITECTURE_SELECTCOMMAND_H
