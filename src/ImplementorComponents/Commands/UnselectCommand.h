//
// Created by Vlad on 20/10/18.
//

#ifndef ARCHITECTURE_UNSELECTCOMMAND_H
#define ARCHITECTURE_UNSELECTCOMMAND_H

#include <memory>

#include "ICommand.h"

class IPrimitive;
class IImplementor;

class UnselectCommand : public ICommand
{
public:
    UnselectCommand(std::shared_ptr<IImplementor> editor, int x, int y);

    void undo() override;
    void execute() override;

private:
    bool m_commandWasExecuted;
    std::shared_ptr<IImplementor> m_editor;
    std::shared_ptr<IPrimitive> m_unselectedPrimitive;
    const int m_unselectedXCoordinate;
    const int m_unselectedYCoordinate;
};

#endif //ARCHITECTURE_UNSELECTCOMMAND_H
