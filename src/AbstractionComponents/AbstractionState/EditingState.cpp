//
// Created by Vlad on 09/10/18.
//

#include "ImplementorComponents/Implementor/Implementor.h"
#include "EditingState.h"

#include "Commands/SelectCommand.h"
#include "Commands/UnselectCommand.h"
#include "Commands/MoveCommand.h"
#include "Commands/ChangeSizeCommand.h"
#include "Commands/ChangeColorCommand.h"
#include "Commands/DeleteCommand.h"

EditingState::EditingState(const std::shared_ptr<IImplementor>& editor)
        : m_implementor(editor)
{
}

void EditingState::select(int x, int y)
{
    m_implementor->executeCommand(std::make_unique<SelectCommand>(m_implementor, x, y));
}

void EditingState::unselect(int x, int y)
{
    m_implementor->executeCommand(std::make_unique<UnselectCommand>(m_implementor, x, y));
}

void EditingState::move(int x, int y)
{
    m_implementor->executeCommand(std::make_unique<MoveCommand>(m_implementor, x, y));
}

void EditingState::changeSize(int x, int y)
{
    m_implementor->executeCommand(std::make_unique<ChangeSizeCommand>(m_implementor, x, y));
}

void EditingState::changeColor(const Color& newColor)
{
    m_implementor->executeCommand(std::make_unique<ChangeColorCommand>(m_implementor, newColor));
}

void EditingState::deleteSelected()
{
    m_implementor->executeCommand(std::make_unique<DeleteCommand>(m_implementor));
}

AbstractionState::StateType EditingState::getCurrentState()
{
    return StateType::Editing;
}
