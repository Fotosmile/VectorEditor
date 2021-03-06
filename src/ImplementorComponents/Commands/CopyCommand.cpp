//
// Created by Vlad on 17/10/18.
//

#include <list>
#include <memory>
#include <algorithm>

#include "CopyCommand.h"
#include "ImplementorComponents/Implementor/IImplementor.h"
#include <Primitive/IPrimitive.h>

CopyCommand::CopyCommand(std::shared_ptr<IImplementor> editor)
        : m_commandWasExecuted(false),
          m_editor(std::move(editor)),
          m_copiedPrimitives()
{
}

void CopyCommand::undo()
{
    if (!m_commandWasExecuted)
    {
        throw std::runtime_error("Failed to undo a not executed command");
    }

    for (const std::shared_ptr<IPrimitive>& primitive: m_copiedPrimitives)
    {
        m_editor->deletePrimitive(primitive);
    }

    m_copiedPrimitives.clear();
    m_commandWasExecuted = false;
}

void CopyCommand::execute()
{
    for (const std::shared_ptr<IPrimitive>& primitive: m_editor->getSelectedPrimitives())
    {
        std::shared_ptr<IPrimitive> copiedPrimitive(primitive->clone().release());
        m_copiedPrimitives.push_back(copiedPrimitive);
        m_editor->addPrimitive(copiedPrimitive);
    }

    m_commandWasExecuted = true;
}