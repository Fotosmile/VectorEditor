//
// Created by Vlad on 17/10/18.
//

#include <list>
#include <memory>
#include <algorithm>

#include "GroupCommand.h"
#include "Editor.h"
#include <Primitive/Primitive.h>

#include "Primitive/Primitives/Composite.h"

GroupCommand::GroupCommand(std::shared_ptr<Editor> editor)
        : m_commandWasExecuted(false),
          m_editor(std::move(editor)),
          m_groupedPrimitive(nullptr),
          m_selectedPrimitives()
{
}

void GroupCommand::undo()
{
    if (!m_commandWasExecuted)
    {
        throw std::runtime_error("Failed to undo a not executed command");
    }

    m_editor->deleteSelectedPrimitive(m_groupedPrimitive);
    m_editor->deletePrimitive(m_groupedPrimitive);

    for (const std::shared_ptr<Primitive>& primitive: m_selectedPrimitives)
    {
        m_editor->addPrimitive(primitive);
        m_editor->addSelectedPrimitive(primitive);
    }

    m_groupedPrimitive = nullptr;
    m_selectedPrimitives.clear();
    m_commandWasExecuted = false;
}

void GroupCommand::execute()
{
    m_selectedPrimitives = m_editor->getSelectedPrimitives();
    m_groupedPrimitive = std::make_shared<Composite>(m_selectedPrimitives);
    for (const std::shared_ptr<Primitive>& primitive: m_selectedPrimitives)
    {
        m_editor->deleteSelectedPrimitive(primitive);
        m_editor->deletePrimitive(primitive);
    }

    m_editor->addPrimitive(m_groupedPrimitive);
    m_editor->addSelectedPrimitive(m_groupedPrimitive);

    m_commandWasExecuted = true;
}