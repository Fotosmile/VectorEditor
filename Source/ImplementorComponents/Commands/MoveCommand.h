//
// Created by Vlad on 10.10.18.
//

#ifndef ARCHITECTURE_MOVECOMMAND_H
#define ARCHITECTURE_MOVECOMMAND_H

#include <memory>

#include "ICommand.h"

class IImplementor;

class MoveCommand : public ICommand
{
public:
    MoveCommand(std::shared_ptr<IImplementor> editor, int x, int y);

    void undo() override;
    void execute() override;

private:
    void moveSelectedPrimitives(int x, int y);

private:
    bool m_commandWasExecuted;
    std::shared_ptr<IImplementor> m_editor;
    const int m_x;
    const int m_y;
};


#endif //ARCHITECTURE_MOVECOMMAND_H
