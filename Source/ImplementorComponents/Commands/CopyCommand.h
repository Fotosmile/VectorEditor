//
// Created by Vlad on 17/10/18.
//

#ifndef ARCHITECTURE_COPYCOMMAND_H
#define ARCHITECTURE_COPYCOMMAND_H

#include <memory>
#include <list>

#include "ICommand.h"

class IPrimitive;
class IImplementor;

class CopyCommand : public ICommand
{
public:
    explicit CopyCommand(std::shared_ptr<IImplementor> editor);

    void undo() override;
    void execute() override;

private:
    bool m_commandWasExecuted;
    std::shared_ptr<IImplementor> m_editor;
    std::list<std::shared_ptr<IPrimitive>> m_copiedPrimitives;
};


#endif //ARCHITECTURE_COPYCOMMAND_H
