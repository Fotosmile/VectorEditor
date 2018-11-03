//
// Created by margo on 18.10.18.
//

#include "LinuxLineEdit.h"
#include "Mock/MockControlElements.h"

#include <iostream>

LinuxLineEdit::LinuxLineEdit(const std::function<void(const std::string&)> &trigger)
        : m_trigger(trigger)
{
    MockControlElements::Instance().registerLineEditInput(
            [this](const std::string &input) { onFired(input); });
}

void LinuxLineEdit::onFired(const std::string &input)
{
    std::cout << "[LINUX] Specific OnFired of lineEdit" << std::endl;
    m_trigger(input);
}