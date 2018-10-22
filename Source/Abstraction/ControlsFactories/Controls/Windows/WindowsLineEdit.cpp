//
// Created by margo on 18.10.18.
//

#include "WindowsLineEdit.h"
#include "GUIMediator/GUIMediator.h"
#include "Mock/MockControlElements.h"

#include <iostream>

WindowsLineEdit::WindowsLineEdit(Mediator* guiMediator)
        : LineEdit(guiMediator)
{
    MockControlElements::Instance().registerLineEditInput(
            [this](const std::string& input) {onFired(input); });
}

void WindowsLineEdit::onFired(const std::string& input)
{
    std::cout << "[WINDOWS] Specific OnFired of lineEdit" << std::endl;
    setLastInput(input);
    getGUIMediator()->notify(this);
}