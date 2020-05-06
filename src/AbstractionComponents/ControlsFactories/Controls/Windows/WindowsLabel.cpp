//
// Created by margo on 18.10.18.
//

#include "WindowsLabel.h"
#include "Mock/MockControlElements.h"

#include <iostream>

WindowsLabel::WindowsLabel(const std::function<void()> &trigger)
        : m_trigger(trigger)
{
    MockControlElements::Instance().registerLabelClick( [this]() { onClicked(); });
}

void WindowsLabel::onClicked()
{
    std::cout << "[WINDOWS] Specific OnClicked of label" << std::endl;
    m_trigger();
}