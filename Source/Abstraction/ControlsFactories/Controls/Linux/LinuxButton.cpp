//
// Created by Vlad on 09/10/18.
//

#include "LinuxButton.h"
#include "Mock/MockControlElements.h"
#include "GUIMediator/GUIMediator.h"

#include <iostream>

LinuxButton::LinuxButton(Mediator* guiMediator)
        : Button(guiMediator)
{
    MockControlElements::Instance().registerButtonClick( [this]() { onClicked(); });
}

void LinuxButton::onClicked()
{
    std::cout << "[LINUX] Specific OnClicked of button" << std::endl;
    getGUIMediator()->notify(this);
}
