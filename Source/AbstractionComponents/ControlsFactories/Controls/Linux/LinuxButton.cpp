//
// Created by Vlad on 09/10/18.
//

#include "LinuxButton.h"
#include "Mock/MockControlElements.h"

#include <iostream>

LinuxButton::LinuxButton(const std::function<void()> &trigger)
        : m_trigger(trigger)
{
    MockControlElements::Instance().registerButtonClick([this]() { onClicked(); });
}

void LinuxButton::onClicked()
{
    std::cout << "[LINUX] Specific OnClicked of button" << std::endl;
    m_trigger();
}