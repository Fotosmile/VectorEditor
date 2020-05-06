//
// Created by margo on 18.10.18.
//

#include "WindowsLineEdit.h"
#include "Mock/MockControlElements.h"

#include <iostream>

WindowsLineEdit::WindowsLineEdit(const std::function<void(const std::string &)> &trigger)
        : m_trigger(trigger)
{
    MockControlElements::Instance().registerLineEditInput(
            [this](const std::string &input) { onFired(input); });
}

void WindowsLineEdit::onFired(const std::string &input)
{
    std::cout << "[WINDOWS] Specific OnFired of lineEdit" << std::endl;
    m_trigger(input);
}