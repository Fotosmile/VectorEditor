//
// Created by margo on 18.10.18.
//

#include "LinuxWindow.h"
#include "Mock/MockControlElements.h"
#include "GUIMediator/GUIMediator.h"

#include <iostream>

LinuxWindow::LinuxWindow(Mediator* guiMediator)
        : Window(guiMediator)
{
    MockControlElements::Instance().registerWindowClick(
            [this](int x, int y) {onClicked(x, y);});
}

void LinuxWindow::onClicked(int x, int y)
{
    std::cout << "[LINUX] Specific OnClicked of window" << std::endl;
    setLastClickCoordinates(std::make_pair(x, y));
    getGUIMediator()->notify(this);
}