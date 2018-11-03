//
// Created by margo on 18.10.18.
//

#include "LinuxLabel.h"
#include "Mock/MockControlElements.h"

#include <iostream>

LinuxLabel::LinuxLabel(const std::function<void()> &trigger)
        : m_trigger(trigger)
{
    MockControlElements::Instance().registerLabelClick( [this]() { onClicked(); });
}

void LinuxLabel::onClicked()
{
    std::cout << "[LINUX] Specific OnClicked of label" << std::endl;
    m_trigger();
}