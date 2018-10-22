//
// Created by Vlad on 09/10/18.
//

#include "Editor.h"
#include "CreatingState.h"

#include "Commands/CreateCommand.h"
#include "Commands/GroupCommand.h"
#include "Commands/CopyCommand.h"

#include "Primitive/Primitive.h"

CreatingState::CreatingState(const std::shared_ptr<Editor>& editor)
        : m_editor(editor)
{
}

GUIState::StateType CreatingState::getCurrentState()
{
    return StateType::Creating;
}

void CreatingState::create(const std::string& primitiveType)
{
    m_editor->executeCommand(std::make_unique<CreateCommand>(m_editor, primitiveType));
}

void CreatingState::group()
{
    m_editor->executeCommand(std::make_unique<GroupCommand>(m_editor));
}

void CreatingState::copy()
{
    m_editor->executeCommand(std::make_unique<CopyCommand>(m_editor));
}