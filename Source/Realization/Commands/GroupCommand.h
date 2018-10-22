//
// Created by Vlad on 17/10/18.
//

#ifndef ARCHITECTURE_GROUPCOMMAND_H
#define ARCHITECTURE_GROUPCOMMAND_H

#include <memory>
#include <list>

#include "Command.h"

class Primitive;
class Editor;

class GroupCommand : public Command
{
public:
    explicit GroupCommand(std::shared_ptr<Editor> editor);
    ~GroupCommand() override = default;

    void undo() override;
    void execute() override;

private:
    bool m_commandWasExecuted;
    std::shared_ptr<Editor> m_editor;
    std::shared_ptr<Primitive> m_groupedPrimitive;
    std::list<std::shared_ptr<Primitive>> m_selectedPrimitives;
};


#endif //ARCHITECTURE_GROUPCOMMAND_H
