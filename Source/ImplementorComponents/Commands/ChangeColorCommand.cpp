//
// Created by Vlad on 12/10/18.
//

#include <list>
#include <memory>
#include <algorithm>

#include "ChangeColorCommand.h"
#include "Implementor/IImplementor.h"
#include "Primitive/IPrimitive.h"

ChangeColorCommand::ChangeColorCommand(std::shared_ptr<IImplementor> editor, const Color& newColor)
        : m_commandWasExecuted(false),
          m_editor(std::move(editor)),
          m_primitivesWithOldColors(),
          m_newColor(newColor)
{
}

void ChangeColorCommand::undo()
{
    if (!m_commandWasExecuted)
    {
        throw std::runtime_error("Failed to undo a not executed command");
    }

    for (const auto& primitiveWithPrevColor: m_primitivesWithOldColors)
    {
        primitiveWithPrevColor.first->setColor(primitiveWithPrevColor.second);
    }

    m_primitivesWithOldColors.clear();
    m_commandWasExecuted = false;
}

void ChangeColorCommand::execute()
{
    for (const std::shared_ptr<IPrimitive>& selectedPrimitive: m_editor->getSelectedPrimitives())
    {
        m_primitivesWithOldColors.insert(std::make_pair(selectedPrimitive, selectedPrimitive->getColor()));
        selectedPrimitive->setColor(m_newColor);
    }

    m_commandWasExecuted = true;
}