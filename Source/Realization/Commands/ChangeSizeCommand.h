//
// Created by Vlad on 12/10/18.
//

#ifndef ARCHITECTURE_CHANGESIZECOMMAND_H
#define ARCHITECTURE_CHANGESIZECOMMAND_H

#include <memory>

#include "Command.h"

class Editor;

class ChangeSizeCommand : public Command
{
public:
    ChangeSizeCommand(std::shared_ptr<Editor> editor, int x, int y);
    ~ChangeSizeCommand() override = default;

    void undo() override;
    void execute() override;

private:
    void changeSizeForSelectedPrimitives(int x, int y);

private:
    bool m_commandWasExecuted;
    std::shared_ptr<Editor> m_editor;
    const int m_x;
    const int m_y;
};


#endif //ARCHITECTURE_CHANGESIZECOMMAND_H
