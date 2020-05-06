//
// Created by Vlad on 09/10/18.
//

#include <string>
#include <iostream>

#include "Abstraction.h"
#include "AbstractionState/CreatingState.h"
#include "AbstractionState/EditingState.h"
#include "ImplementorComponents/Implementor/Implementor.h"
#include "AbstractionObserver/Subscribers/ChangeCursorSubscriber.h"
#include "AbstractionObserver/Subscribers/ShowNotificationSubscriber.h"
#include "AbstractionObserver/Subscribers/ToolbarSubscriber.h"
#include "ImageFilters/ImageFilterHelpers.hpp"
#include "Common/RasterImage.h"

Abstraction::Abstraction(const std::shared_ptr<IImplementor>& editor)
        : m_eventManager(std::make_unique<EventManager>()),
          m_controlsFactory(createControlsFactory()),
          m_state(std::make_unique<CreatingState>(editor)),
          m_editor(editor)
{
    createControlElements();
    createSubscribers();
}

void Abstraction::createControlElements()
{
    m_changeStateButton = m_controlsFactory->createButton(
            [this]()
            { changeState(); });

    m_deleteButton = m_controlsFactory->createButton(
            [this]()
            { deleteSelected(); });

    m_copyButton = m_controlsFactory->createButton(
            [this]()
            { copy(); });

    m_groupButton = m_controlsFactory->createButton(
            [this]()
            { group(); });

    m_moveXLineEdit = m_controlsFactory->createLineEdit(
            [this](const std::string& input)
            { move(std::stoi(input), 0); });

    m_moveYLineEdit = m_controlsFactory->createLineEdit(
            [this](const std::string& input)
            { move(0, std::stoi(input)); });

    m_changeSizeXLineEdit = m_controlsFactory->createLineEdit(
            [this](const std::string& input)
            { changeSize(std::stoi(input), 0); });

    m_changeSizeYLineEdit = m_controlsFactory->createLineEdit(
            [this](const std::string& input)
            { changeSize(0, std::stoi(input)); });

    m_changeColorLineEdit = m_controlsFactory->createLineEdit(
            [this](const std::string& input)
            { changeColor(Color(input)); });

    m_createLineEdit = m_controlsFactory->createLineEdit(
            [this](const std::string& input)
            { create(input); });

    m_saveFilteredImageLinEdit = m_controlsFactory->createLineEdit(
            [this](const std::string& input)
            { saveWithFilters(input); });

    m_mainAreaWindow = m_controlsFactory->createWindow(
            [this](int x, int y)
            { onClicked(x, y); });
}

void Abstraction::createSubscribers()
{
    m_eventManager->subscribe(IEventManager::EventType::StateChanged, std::make_unique<ChangeCursorSubscriber>());
    m_eventManager->subscribe(IEventManager::EventType::StateChanged, std::make_unique<ShowNotificationSubscriber>());
    m_eventManager->subscribe(IEventManager::EventType::StateChanged, std::make_unique<ToolbarSubscriber>());
}


void Abstraction::changeState()
{
    if (m_state->getCurrentState() == AbstractionState::StateType::Creating)
    {
        m_state = std::make_unique<EditingState>(m_editor);
    }
    else
    {
        m_state = std::make_unique<CreatingState>(m_editor);
    }
    m_eventManager->notifySubscribers(IEventManager::EventType::StateChanged, m_state->getCurrentState());
}

void Abstraction::deleteSelected()
{
    m_state->deleteSelected();
}

void Abstraction::copy()
{
    m_state->copy();
}

void Abstraction::group()
{
    m_state->group();
}

void Abstraction::move(int x, int y)
{
    m_state->move(x, y);
}

void Abstraction::changeSize(int x, int y)
{
    m_state->changeSize(x, y);
}

void Abstraction::changeColor(const Color& color)
{
    m_state->changeColor(color);
}

void Abstraction::create(const std::string& primitiveName)
{
    m_state->create(primitiveName);
}

void Abstraction::saveWithFilters(const std::string& filters)
{
    m_editor->saveWithFilters(filters);
}

void Abstraction::onClicked(int x, int y)
{
    try
    {
        m_editor->getPrimitiveByCoordinates(x, y);
        m_state->unselect(x, y);
    }
    catch (const std::exception&) //throws if does not have a primitive under the point == nothing to unselect
    {
        m_state->select(x, y);
    }
}