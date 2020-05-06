//
// Created by margo on 18.10.18.
//

#include "WindowsWindow.h"
#include "Mock/MockControlElements.h"

#include <iostream>

WindowsWindow::WindowsWindow(const std::function<void(int, int)> &trigger)
        : m_trigger(trigger)
{
    MockControlElements::Instance().registerWindowClick(
            [this](int x, int y) { onClicked(x, y); });
}

void WindowsWindow::onClicked(int x, int y)
{
    std::cout << "[WINDOWS] Specific OnClicked of window" << std::endl;
    m_trigger(x, y);
}