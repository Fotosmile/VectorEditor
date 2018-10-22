//
// Created by Vlad on 12/10/18.
//

#include <list>
#include <memory>
#include <algorithm>

#include "DeleteCommand.h"
#include "Editor.h"
#include <Primitive/Primitive.h>

DeleteCommand::DeleteCommand(std::shared_ptr<Editor> editor)
        : m_commandWasExecuted(false),
          m_editor(std::move(editor))
{
}

void DeleteCommand::undo()
{
    if (!m_commandWasExecuted)
    {
        throw std::runtime_error("Failed to undo a not executed command");
    }

    for(const std::shared_ptr<Primitive>& primitive: m_selectedPrimitives)
    {
        m_editor->addPrimitive(primitive);
        m_editor->addSelectedPrimitive(primitive);
    }

    m_selectedPrimitives.clear();
    m_commandWasExecuted = false;
}

void DeleteCommand::execute()
{
    m_selectedPrimitives = m_editor->getSelectedPrimitives();
    for(const std::shared_ptr<Primitive>& primitive: m_selectedPrimitives)
    {
        m_editor->deleteSelectedPrimitive(primitive);
        m_editor->deletePrimitive(primitive);
    }

    m_commandWasExecuted = true;
}