//
// Created by Vlad on 10.10.18.
//

#include <list>
#include <memory>
#include <algorithm>

#include "MoveCommand.h"
#include "ImplementorComponents/Implementor/IImplementor.h"
#include "Primitive/IPrimitive.h"

MoveCommand::MoveCommand(std::shared_ptr<IImplementor> editor, int x, int y)
        : m_commandWasExecuted(false),
          m_editor(std::move(editor)),
          m_x(x),
          m_y(y)
{
}

void MoveCommand::undo()
{
    if (!m_commandWasExecuted)
    {
        throw std::runtime_error("Failed to undo a not executed command");
    }

    moveSelectedPrimitives(-m_x, -m_y);

    m_commandWasExecuted = false;
}

void MoveCommand::execute()
{
    moveSelectedPrimitives(m_x, m_y);

    m_commandWasExecuted = true;
}

void MoveCommand::moveSelectedPrimitives(int x, int y)
{
    for (const std::shared_ptr<IPrimitive>& selectedPrimitive : m_editor->getSelectedPrimitives())
    {
        selectedPrimitive->move(x, y);
    }
}