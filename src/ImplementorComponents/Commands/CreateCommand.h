//
// Created by Vlad on 17/10/18.
//

#ifndef ARCHITECTURE_CREATECOMMAND_H
#define ARCHITECTURE_CREATECOMMAND_H

#include <memory>
#include <string>

#include "ICommand.h"

class IPrimitive;
class IImplementor;

class CreateCommand : public ICommand
{
public:
    CreateCommand(std::shared_ptr<IImplementor> editor, const std::string& primitiveType);

    void undo() override;
    void execute() override;

private:
    bool m_commandWasExecuted;
    std::shared_ptr<IImplementor> m_editor;
    std::shared_ptr<IPrimitive> m_createdPrimitive;
    const std::string m_primitiveType;
};


#endif //ARCHITECTURE_CREATECOMMAND_H
