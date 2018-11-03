//
// Created by Vlad on 17/10/18.
//

#ifndef ARCHITECTURE_GROUPCOMMAND_H
#define ARCHITECTURE_GROUPCOMMAND_H

#include <memory>
#include <list>

#include "ICommand.h"

class IPrimitive;
class IImplementor;

class GroupCommand : public ICommand
{
public:
    explicit GroupCommand(std::shared_ptr<IImplementor> editor);

    void undo() override;
    void execute() override;

private:
    bool m_commandWasExecuted;
    std::shared_ptr<IImplementor> m_editor;
    std::shared_ptr<IPrimitive> m_groupedPrimitive;
    std::list<std::shared_ptr<IPrimitive>> m_selectedPrimitives;
};


#endif //ARCHITECTURE_GROUPCOMMAND_H
