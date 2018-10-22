//
// Created by Vlad on 12/10/18.
//

#ifndef ARCHITECTURE_DELETECOMMAND_H
#define ARCHITECTURE_DELETECOMMAND_H

#include <memory>
#include <list>

#include "Command.h"

class Primitive;
class Editor;

class DeleteCommand : public Command
{
public:
    explicit DeleteCommand(std::shared_ptr<Editor> editor);
    ~DeleteCommand() override = default;

    void undo() override;
    void execute() override;

private:
    bool m_commandWasExecuted;
    std::shared_ptr<Editor> m_editor;
    std::list<std::shared_ptr<Primitive>> m_selectedPrimitives;
};


#endif //ARCHITECTURE_DELETECOMMAND_H
