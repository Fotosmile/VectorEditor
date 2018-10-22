//
// Created by margo on 18.10.18.
//

#include "WindowsWindow.h"
#include "GUIMediator/GUIMediator.h"
#include "Mock/MockControlElements.h"

#include <iostream>

WindowsWindow::WindowsWindow(Mediator* guiMediator)
        : Window(guiMediator)
{
    MockControlElements::Instance().registerWindowClick(
            [this](int x, int y) {onClicked(x, y); });
}

void WindowsWindow::onClicked(int x, int y)
{
    std::cout << "[WINDOWS] Specific OnClicked of window" << std::endl;
    setLastClickCoordinates(std::make_pair(x, y));
    getGUIMediator()->notify(this);
}