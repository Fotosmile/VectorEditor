//
// Created by Vlad on 09/10/18.
//

#include <string>
#include <iostream>

#include "Common/CommonDefines.h"
#include "GUIMediator.h"
#include "Controls/ControlElement.hpp"
#include "GUIState/CreatingState.h"
#include "GUIState/EditingState.h"
#include "Editor.h"
#include "GUIObserver/Subscribers/ChangeCursorSubscriber.h"
#include "GUIObserver/Subscribers/ShowNotificationSubscriber.h"
#include "GUIObserver/Subscribers/ToolbarSubscriber.h"
#include "ImageFilters/ImageFilterHelpers.hpp"
#include "Common/RasterImage.h"
#include "Primitive/Primitive.h"

GUIMediator::GUIMediator(const std::shared_ptr<Editor>& editor)
        : m_eventManager(std::make_unique<EventManager>()),
#ifdef CUR_OS_WINDOWS
        m_controlsFactory(std::make_unique<WindowsControlsFactory>()),
#elif defined(CUR_OS_LINUX)
          m_controlsFactory(std::make_unique<LinuxControlsFactory>()),
#else
#error
#endif
          m_state(std::make_unique<CreatingState>(editor)),
          m_editor(editor)
{
    createControlElements();
    createSubscribers();
}

void GUIMediator::createControlElements()
{
    m_changeStateButton = m_controlsFactory->createButton(this);
    m_deleteButton = m_controlsFactory->createButton(this);
    m_copyButton = m_controlsFactory->createButton(this);
    m_groupButton = m_controlsFactory->createButton(this);

    m_moveXLineEdit = m_controlsFactory->createLineEdit(this);
    m_moveYLineEdit = m_controlsFactory->createLineEdit(this);
    m_changeSizeXLineEdit = m_controlsFactory->createLineEdit(this);
    m_changeSizeYLineEdit = m_controlsFactory->createLineEdit(this);
    m_changeColorLineEdit = m_controlsFactory->createLineEdit(this);
    m_createLineEdit = m_controlsFactory->createLineEdit(this);
    m_saveFilteredImageLinEdit = m_controlsFactory->createLineEdit(this);

    m_mainAreaWindow = m_controlsFactory->createWindow(this);
}

void GUIMediator::createSubscribers()
{
    m_eventManager->subscribe(EventManager::EventType::StateChanged, std::make_unique<ChangeCursorSubscriber>());
    m_eventManager->subscribe(EventManager::EventType::StateChanged, std::make_unique<ShowNotificationSubscriber>());
    m_eventManager->subscribe(EventManager::EventType::StateChanged, std::make_unique<ToolbarSubscriber>());
}

void GUIMediator::notify(ControlElement* controlElement)
{
    try
    {
        std::cout << typeid(*this).name() << " : " << __func__ << " : ";
        if (controlElement == m_changeStateButton.get())
        {
            std::cout << "change state button" << std::endl;
            if (m_state->getCurrentState() == GUIState::StateType::Creating)
            {
                m_state = std::make_unique<EditingState>(m_editor);
            }
            else
            {
                m_state = std::make_unique<CreatingState>(m_editor);
            }
            m_eventManager->notifySubscribers(EventManager::EventType::StateChanged, m_state->getCurrentState());
        }
        else if (controlElement == m_deleteButton.get())
        {
            std::cout << "delete button" << std::endl;
            m_state->deleteSelected();
        }
        else if (controlElement == m_copyButton.get())
        {
            std::cout << "copy button" << std::endl;
            m_state->copy();
        }
        else if (controlElement == m_groupButton.get())
        {
            std::cout << "group button" << std::endl;
            m_state->group();
        }
        else if (controlElement == m_moveXLineEdit.get())
        {
            std::cout << "move x coordinate line edit" << std::endl;
            m_state->move(std::stoi(m_moveXLineEdit->getLastInput()), 0);
        }
        else if (controlElement == m_moveYLineEdit.get())
        {
            std::cout << "move y coordinate line edit" << std::endl;
            m_state->move(0, std::stoi(m_moveYLineEdit->getLastInput()));
        }
        else if (controlElement == m_changeSizeXLineEdit.get())
        {
            std::cout << "change size by x coordinate line edit" << std::endl;
            m_state->changeSize(std::stoi(m_changeSizeXLineEdit->getLastInput()), 0);
        }
        else if (controlElement == m_changeSizeYLineEdit.get())
        {
            std::cout << "change size by y coordinate line edit" << std::endl;
            m_state->changeSize(0, std::stoi(m_changeSizeYLineEdit->getLastInput()));
        }
        else if (controlElement == m_changeColorLineEdit.get())
        {
            std::cout << "change color line edit" << std::endl;
            m_state->changeColor(Color(m_changeColorLineEdit->getLastInput()));
        }
        else if (controlElement == m_createLineEdit.get())
        {
            std::cout << "create line edit" << std::endl;
            m_state->create(m_createLineEdit->getLastInput());
        }
        else if (controlElement == m_saveFilteredImageLinEdit.get())
        {
            std::cout << "save filtered image line edit" << std::endl;
            const std::list<std::string> filters = split(m_saveFilteredImageLinEdit->getLastInput(), ';');
            std::unique_ptr<RasterImage> rasterImage = m_editor->getFilteredImage(m_editor->saveToImage(), filters);
            rasterImage->saveImage(getDefaultSavePath() + getDefaultSaveName());
        }
        else if (controlElement == m_mainAreaWindow.get())
        {
            std::cout << "click on window" << std::endl;
            Window::Coordinates_t coordinates = m_mainAreaWindow->getLastClickCoordinates();
            int x = coordinates.first;
            int y = coordinates.second;
            for (const std::shared_ptr<Primitive>& selectedPrimitive: m_editor->getSelectedPrimitives())
            {
                if (selectedPrimitive->containsPoint(x, y))
                {
                    m_state->unselect(x, y);
                    return;
                }
            }
            m_state->select(x, y);
        }
    }
    catch (const std::exception& exc)
    {
        std::cout << exc.what() << std::endl;
    }
}