//
// Created by Vlad on 09/10/18.
//

#include "Implementor/Implementor.h"
#include "CreatingState.h"

#include "Commands/CreateCommand.h"
#include "Commands/GroupCommand.h"
#include "Commands/CopyCommand.h"

#include "Primitive/IPrimitive.h"

CreatingState::CreatingState(const std::shared_ptr<IImplementor>& editor)
        : m_implementor(editor)
{
}

AbstractionState::StateType CreatingState::getCurrentState()
{
    return StateType::Creating;
}

void CreatingState::create(const std::string& primitiveType)
{
    m_implementor->executeCommand(std::make_unique<CreateCommand>(m_implementor, primitiveType));
}

void CreatingState::group()
{
    m_implementor->executeCommand(std::make_unique<GroupCommand>(m_implementor));
}

void CreatingState::copy()
{
    m_implementor->executeCommand(std::make_unique<CopyCommand>(m_implementor));
}