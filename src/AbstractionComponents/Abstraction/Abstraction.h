//
// Created by Vlad on 09/10/18.
//

#ifndef ARCHITECTURE_GUIMEDIATOR_H
#define ARCHITECTURE_GUIMEDIATOR_H

#include <memory>

#include "IAbstraction.h"
#include "AbstractionObserver/EventManager.h"
#include "Controls/IButton.h"
#include "Controls/ILineEdit.h"
#include "Controls/IWindow.h"
#include "ControlsFactories/ControlsFactory.h"
#include "Color.h"

class IImplementor;
class AbstractionState;

class Abstraction : public IAbstraction
{
public:
    explicit Abstraction(const std::shared_ptr<IImplementor>& editor);

    void deleteSelected() override;
    void copy() override;
    void group() override;
    void move(int x, int y) override;
    void changeSize(int x, int y) override;
    void changeColor(const Color& color) override;
    void create(const std::string& primitiveName) override;
    void saveWithFilters(const std::string& filters) override;
    void onClicked(int x, int y) override;

private:
    void createControlElements();
    void createSubscribers();

    void changeState();

private:
    std::unique_ptr<IEventManager> m_eventManager;
    std::unique_ptr<IControlsFactory> m_controlsFactory;
    std::unique_ptr<AbstractionState> m_state;
    std::shared_ptr<IImplementor> m_editor;

    std::unique_ptr<IButton> m_changeStateButton;
    std::unique_ptr<IButton> m_deleteButton;
    std::unique_ptr<IButton> m_copyButton;
    std::unique_ptr<IButton> m_groupButton;
    std::unique_ptr<ILineEdit> m_moveXLineEdit;
    std::unique_ptr<ILineEdit> m_moveYLineEdit;
    std::unique_ptr<ILineEdit> m_changeSizeXLineEdit;
    std::unique_ptr<ILineEdit> m_changeSizeYLineEdit;
    std::unique_ptr<ILineEdit> m_changeColorLineEdit;
    std::unique_ptr<ILineEdit> m_createLineEdit;
    std::unique_ptr<ILineEdit> m_saveFilteredImageLinEdit;
    std::unique_ptr<IWindow> m_mainAreaWindow;
};


#endif //ARCHITECTURE_GUIMEDIATOR_H
