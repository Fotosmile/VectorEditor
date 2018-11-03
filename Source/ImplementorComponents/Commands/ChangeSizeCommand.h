//
// Created by Vlad on 12/10/18.
//

#ifndef ARCHITECTURE_CHANGESIZECOMMAND_H
#define ARCHITECTURE_CHANGESIZECOMMAND_H

#include <memory>

#include "ICommand.h"

class IImplementor;

class ChangeSizeCommand : public ICommand
{
public:
    ChangeSizeCommand(std::shared_ptr<IImplementor> editor, int x, int y);

    void undo() override;
    void execute() override;

private:
    void changeSizeForSelectedPrimitives(int x, int y);

private:
    bool m_commandWasExecuted;
    std::shared_ptr<IImplementor> m_editor;
    const int m_x;
    const int m_y;
};


#endif //ARCHITECTURE_CHANGESIZECOMMAND_H
