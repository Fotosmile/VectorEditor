//
// Created by Vlad on 20/10/18.
//

#include <stdexcept>

#include "UnselectCommand.h"
#include "Editor.h"

UnselectCommand::UnselectCommand(std::shared_ptr<Editor> editor, int x, int y)
        : m_commandWasExecuted(false),
          m_editor(std::move(editor)),
          m_unselectedPrimitive(nullptr),
          m_unselectedXCoordinate(x),
          m_unselectedYCoordinate(y)
{
}

void UnselectCommand::undo()
{
    if (!m_commandWasExecuted)
    {
        throw std::runtime_error("Failed to undo a not executed command");
    }

    m_editor->addSelectedPrimitive(m_unselectedPrimitive);

    m_unselectedPrimitive = nullptr;
    m_commandWasExecuted = false;
}

void UnselectCommand::execute()
{
    m_unselectedPrimitive = m_editor->getPrimitiveByCoordinates(m_unselectedXCoordinate, m_unselectedYCoordinate);
    m_editor->deleteSelectedPrimitive(m_unselectedPrimitive);

    m_commandWasExecuted = true;
}