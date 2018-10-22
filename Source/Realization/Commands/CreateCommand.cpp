//
// Created by Vlad on 17/10/18.
//

#include <list>
#include <memory>
#include <algorithm>

#include "CreateCommand.h"
#include "Editor.h"
#include "Primitive/Primitive.h"
#include "Primitive/PrimitiveHelpers.hpp"

CreateCommand::CreateCommand(std::shared_ptr<Editor> editor, const std::string& primitiveType)
        : m_commandWasExecuted(false),
          m_editor(std::move(editor)),
          m_createdPrimitive(nullptr),
          m_primitiveType(primitiveType)
{
}

void CreateCommand::undo()
{
    if (!m_commandWasExecuted)
    {
        throw std::runtime_error("Failed to undo a not executed command");
    }

    m_editor->deletePrimitive(m_createdPrimitive);

    m_createdPrimitive = nullptr;
    m_commandWasExecuted = false;
}

void CreateCommand::execute()
{
    m_createdPrimitive = createPrimitive(m_primitiveType);
    m_editor->addPrimitive(m_createdPrimitive);

    m_commandWasExecuted = true;
}