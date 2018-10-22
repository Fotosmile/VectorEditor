//
// Created by Vlad on 10.10.18.
//

#ifndef ARCHITECTURE_MOVECOMMAND_H
#define ARCHITECTURE_MOVECOMMAND_H

#include <memory>

#include "Command.h"

class Primitive;
class Editor;

class MoveCommand : public Command
{
public:
    MoveCommand(std::shared_ptr<Editor> editor, int x, int y);
    ~MoveCommand() override = default;

    void undo() override;
    void execute() override;

private:
    void moveSelectedPrimitives(int x, int y);

private:
    bool m_commandWasExecuted;
    std::shared_ptr<Editor> m_editor;
    const int m_x;
    const int m_y;
};


#endif //ARCHITECTURE_MOVECOMMAND_H
