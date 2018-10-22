//
// Created by Vlad on 12/10/18.
//

#include <list>
#include <memory>
#include <algorithm>

#include "ChangeSizeCommand.h"
#include "Editor.h"
#include "Primitive/Primitive.h"

ChangeSizeCommand::ChangeSizeCommand(std::shared_ptr<Editor> editor, int x, int y)
        : m_commandWasExecuted(false),
          m_editor(std::move(editor)),
          m_x(x),
          m_y(y)
{
}

void ChangeSizeCommand::undo()
{
    if (!m_commandWasExecuted)
    {
        throw std::runtime_error("Failed to undo a not executed command");
    }

    changeSizeForSelectedPrimitives(-m_x, -m_y);

    m_commandWasExecuted = false;
}

void ChangeSizeCommand::execute()
{
    changeSizeForSelectedPrimitives(m_x, m_y);

    m_commandWasExecuted = true;
}

void ChangeSizeCommand::changeSizeForSelectedPrimitives(int x, int y)
{
    for (const std::shared_ptr<Primitive>& selectedPrimitive : m_editor->getSelectedPrimitives())
    {
        selectedPrimitive->changeSize(x, y);
    }
}