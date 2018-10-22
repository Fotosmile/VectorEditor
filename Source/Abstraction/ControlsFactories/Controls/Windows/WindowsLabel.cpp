//
// Created by margo on 18.10.18.
//

#include "WindowsLabel.h"
#include "GUIMediator/GUIMediator.h"
#include "Mock/MockControlElements.h"

#include <iostream>

WindowsLabel::WindowsLabel(Mediator* guiMediator)
        : Label(guiMediator)
{
    MockControlElements::Instance().registerLabelClick( [this]() {onClicked(); });
}

void WindowsLabel::onClicked()
{
    std::cout << "[WINDOWS] Specific OnClicked of label" << std::endl;
    getGUIMediator()->notify(this);
}