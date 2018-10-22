//
// Created by margo on 18.10.18.
//

#include "LinuxLineEdit.h"
#include "Mock/MockControlElements.h"
#include "GUIMediator/GUIMediator.h"

#include <iostream>

LinuxLineEdit::LinuxLineEdit(Mediator* guiMediator)
        : LineEdit(guiMediator)
{
    MockControlElements::Instance().registerLineEditInput(
            [this](const std::string& input) { onFired(input); });
}

void LinuxLineEdit::onFired(const std::string& input)
{
    std::cout << "[LINUX] Specific OnFired of lineEdit" << std::endl;
    setLastInput(input);
    getGUIMediator()->notify(this);
}