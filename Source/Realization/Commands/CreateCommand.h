//
// Created by Vlad on 17/10/18.
//

#ifndef ARCHITECTURE_CREATECOMMAND_H
#define ARCHITECTURE_CREATECOMMAND_H

#include <memory>
#include <string>

#include "Command.h"

class Primitive;
class Editor;

class CreateCommand : public Command
{
public:
    CreateCommand(std::shared_ptr<Editor> editor, const std::string& primitiveType);
    ~CreateCommand() override = default;

    void undo() override;
    void execute() override;

private:
    bool m_commandWasExecuted;
    std::shared_ptr<Editor> m_editor;
    std::shared_ptr<Primitive> m_createdPrimitive;
    const std::string m_primitiveType;
};


#endif //ARCHITECTURE_CREATECOMMAND_H
