//
// Created by Vlad on 17/10/18.
//

#include <stdexcept>

#include "SelectCommand.h"
#include "ImplementorComponents/Implementor/IImplementor.h"

SelectCommand::SelectCommand(std::shared_ptr<IImplementor> editor, int x, int y)
        : m_commandWasExecuted(false),
          m_editor(std::move(editor)),
          m_selectedPrimitive(nullptr),
          m_selectedXCoordinate(x),
          m_selectedYCoordinate(y)
{
}

void SelectCommand::undo()
{
    if (!m_commandWasExecuted)
    {
        throw std::runtime_error("Failed to undo a not executed command");
    }

    m_editor->deleteSelectedPrimitive(m_selectedPrimitive);

    m_selectedPrimitive = nullptr;
    m_commandWasExecuted = false;
}

void SelectCommand::execute()
{
    m_selectedPrimitive = m_editor->getPrimitiveByCoordinates(m_selectedXCoordinate, m_selectedYCoordinate);
    m_editor->addSelectedPrimitive(m_selectedPrimitive);

    m_commandWasExecuted = true;
}