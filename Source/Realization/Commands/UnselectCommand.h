//
// Created by Vlad on 20/10/18.
//

#ifndef ARCHITECTURE_UNSELECTCOMMAND_H
#define ARCHITECTURE_UNSELECTCOMMAND_H

#include <memory>

#include "Command.h"

class Primitive;
class Editor;

class UnselectCommand : public Command
{
public:
    UnselectCommand(std::shared_ptr<Editor> editor, int x, int y);
    ~UnselectCommand() override = default;

    void undo() override;
    void execute() override;

private:
    bool m_commandWasExecuted;
    std::shared_ptr<Editor> m_editor;
    std::shared_ptr<Primitive> m_unselectedPrimitive;
    const int m_unselectedXCoordinate;
    const int m_unselectedYCoordinate;
};

#endif //ARCHITECTURE_UNSELECTCOMMAND_H
