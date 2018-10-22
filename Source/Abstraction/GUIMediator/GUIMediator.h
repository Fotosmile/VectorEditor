//
// Created by Vlad on 09/10/18.
//

#ifndef ARCHITECTURE_GUIMEDIATOR_H
#define ARCHITECTURE_GUIMEDIATOR_H

#include <memory>

#include "Mediator.h"
#include "GUIObserver/EventManager.h"
#include "Controls/Button.hpp"
#include "Controls/LineEdit.hpp"
#include "Controls/Window.hpp"
#include "ControlsFactories/ControlsFactory.h"

class Editor;
class GUIState;

class GUIMediator : public Mediator
{
public:
    explicit GUIMediator(const std::shared_ptr<Editor>& editor);
    ~GUIMediator() override = default;

    void notify(ControlElement * controlElement) override;

private:
    void createControlElements();
    void createSubscribers();

private:
    std::unique_ptr<EventManager> m_eventManager;
    std::unique_ptr<ControlsFactory> m_controlsFactory;
    std::unique_ptr<GUIState> m_state;
    std::shared_ptr<Editor> m_editor;

    std::unique_ptr<Button> m_changeStateButton;
    std::unique_ptr<Button> m_deleteButton;
    std::unique_ptr<Button> m_copyButton;
    std::unique_ptr<Button> m_groupButton;
    std::unique_ptr<LineEdit> m_moveXLineEdit;
    std::unique_ptr<LineEdit> m_moveYLineEdit;
    std::unique_ptr<LineEdit> m_changeSizeXLineEdit;
    std::unique_ptr<LineEdit> m_changeSizeYLineEdit;
    std::unique_ptr<LineEdit> m_changeColorLineEdit;
    std::unique_ptr<LineEdit> m_createLineEdit;
    std::unique_ptr<LineEdit> m_saveFilteredImageLinEdit;
    std::unique_ptr<Window> m_mainAreaWindow;
};


#endif //ARCHITECTURE_GUIMEDIATOR_H
