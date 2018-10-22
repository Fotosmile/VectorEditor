//
// Created by margo on 18.10.18.
//

#include "LinuxLabel.h"
#include "Mock/MockControlElements.h"
#include "GUIMediator/GUIMediator.h"

#include <iostream>

LinuxLabel::LinuxLabel(Mediator* guiMediator)
        : Label(guiMediator)
{
    MockControlElements::Instance().registerLabelClick( [this]() { onClicked(); });
}

void LinuxLabel::onClicked()
{
    std::cout << "[LINUX] Specific OnClicked of label" << std::endl;
    getGUIMediator()->notify(this);
}