//
// Created by margo on 18.10.18.
//

#include "LinuxWindow.h"
#include "Mock/MockControlElements.h"

#include <iostream>

LinuxWindow::LinuxWindow(const std::function<void(int, int)> &trigger)
        : m_trigger(trigger)
{
    MockControlElements::Instance().registerWindowClick(
            [this](int x, int y) { onClicked(x, y); });
}


void LinuxWindow::onClicked(int x, int y)
{
    std::cout << "[LINUX] Specific OnClicked of window" << std::endl;
    m_trigger(x, y);
}