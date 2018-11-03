//
// Created by Vlad on 09/10/18.
//

#include "WindowsButton.h"
#include "Mock/MockControlElements.h"

#include <iostream>

WindowsButton::WindowsButton(const std::function<void()> &trigger)
        : m_trigger(trigger)
{
    MockControlElements::Instance().registerButtonClick([this]() { onClicked(); });
}

void WindowsButton::onClicked()
{
    std::cout << "[WINDOWS] Specific OnClicked of button" << std::endl;
    m_trigger();
}