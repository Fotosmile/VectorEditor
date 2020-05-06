//
// Created by Vlad on 17/10/18.
//

#ifndef ARCHITECTURE_SELECTCOMMAND_H
#define ARCHITECTURE_SELECTCOMMAND_H

#include <memory>

#include "ICommand.h"

class IPrimitive;
class IImplementor;

class SelectCommand : public ICommand
{
public:
    SelectCommand(std::shared_ptr<IImplementor> editor, int x, int y);

    void undo() override;
    void execute() override;

private:
    bool m_commandWasExecuted;
    std::shared_ptr<IImplementor> m_editor;
    std::shared_ptr<IPrimitive> m_selectedPrimitive;
    const int m_selectedXCoordinate;
    const int m_selectedYCoordinate;
};


#endif //ARCHITECTURE_SELECTCOMMAND_H
