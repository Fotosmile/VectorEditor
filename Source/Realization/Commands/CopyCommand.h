//
// Created by Vlad on 17/10/18.
//

#ifndef ARCHITECTURE_COPYCOMMAND_H
#define ARCHITECTURE_COPYCOMMAND_H

#include <memory>
#include <list>

#include "Command.h"

class Primitive;
class Editor;

class CopyCommand : public Command
{
public:
    explicit CopyCommand(std::shared_ptr<Editor> editor);
    ~CopyCommand() override = default;

    void undo() override;
    void execute() override;

private:
    bool m_commandWasExecuted;
    std::shared_ptr<Editor> m_editor;
    std::list<std::shared_ptr<Primitive>> m_copiedPrimitives;
};


#endif //ARCHITECTURE_COPYCOMMAND_H
