//
// Created by Vlad on 09/10/18.
//

#include "WindowsButton.h"
#include "GUIMediator/GUIMediator.h"
#include "Mock/MockControlElements.h"

#include <iostream>

WindowsButton::WindowsButton(Mediator* guiMediator)
        : Button(guiMediator)
{
    MockControlElements::Instance().registerButtonClick( [this]() {onClicked(); });
}

void WindowsButton::onClicked()
{
    std::cout << "[WINDOWS] Specific OnClicked of button" << std::endl;
    getGUIMediator()->notify(this);
}