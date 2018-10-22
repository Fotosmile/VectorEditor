//
// Created by Vlad on 09/10/18.
//

#include "Editor.h"
#include "EditingState.h"

#include "Commands/SelectCommand.h"
#include "Commands/UnselectCommand.h"
#include "Commands/MoveCommand.h"
#include "Commands/ChangeSizeCommand.h"
#include "Commands/ChangeColorCommand.h"
#include "Commands/DeleteCommand.h"

EditingState::EditingState(const std::shared_ptr<Editor>& editor)
        : m_editor(editor)
{
}

void EditingState::select(int x, int y)
{
    m_editor->executeCommand(std::make_unique<SelectCommand>(m_editor, x, y));
}

void EditingState::unselect(int x, int y)
{
    m_editor->executeCommand(std::make_unique<UnselectCommand>(m_editor, x, y));
}

void EditingState::move(int x, int y)
{
    m_editor->executeCommand(std::make_unique<MoveCommand>(m_editor, x, y));
}

void EditingState::changeSize(int x, int y)
{
    m_editor->executeCommand(std::make_unique<ChangeSizeCommand>(m_editor, x, y));
}

void EditingState::changeColor(const Color& newColor)
{
    m_editor->executeCommand(std::make_unique<ChangeColorCommand>(m_editor, newColor));
}

void EditingState::deleteSelected()
{
    m_editor->executeCommand(std::make_unique<DeleteCommand>(m_editor));
}

GUIState::StateType EditingState::getCurrentState()
{
    return StateType::Editing;
}
