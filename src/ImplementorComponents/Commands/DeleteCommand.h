//
// Created by Vlad on 12/10/18.
//

#ifndef ARCHITECTURE_DELETECOMMAND_H
#define ARCHITECTURE_DELETECOMMAND_H

#include <memory>
#include <list>

#include "ICommand.h"

class IPrimitive;
class IImplementor;

class DeleteCommand : public ICommand
{
public:
    explicit DeleteCommand(std::shared_ptr<IImplementor> editor);

    void undo() override;
    void execute() override;

private:
    bool m_commandWasExecuted;
    std::shared_ptr<IImplementor> m_editor;
    std::list<std::shared_ptr<IPrimitive>> m_selectedPrimitives;
};


#endif //ARCHITECTURE_DELETECOMMAND_H
