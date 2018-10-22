//
// Created by Vlad on 09/10/18.
//

#include "ControlsFactory.h"

#include "Controls/Linux/LinuxButton.h"
#include "Controls/Linux/LinuxLabel.h"
#include "Controls/Linux/LinuxLineEdit.h"
#include "Controls/Linux/LinuxWindow.h"

#include "Controls/Windows/WindowsButton.h"
#include "Controls/Windows/WindowsLabel.h"
#include "Controls/Windows/WindowsLineEdit.h"
#include "Controls/Windows/WindowsWindow.h"

std::unique_ptr<Button> LinuxControlsFactory::createButton(Mediator * guiMediator)
{
    return std::make_unique<LinuxButton>(guiMediator);
}

std::unique_ptr<Label> LinuxControlsFactory::createLabel(Mediator *guiMediator)
{
    return std::make_unique<LinuxLabel>(guiMediator);
}

std::unique_ptr<LineEdit> LinuxControlsFactory::createLineEdit(Mediator *guiMediator)
{
    return std::make_unique<LinuxLineEdit>(guiMediator);
}

std::unique_ptr<Window> LinuxControlsFactory::createWindow(Mediator *guiMediator)
{
    return std::make_unique<LinuxWindow>(guiMediator);
}

std::unique_ptr<Button> WindowsControlsFactory::createButton(Mediator * guiMediator)
{
    return std::make_unique<WindowsButton>(guiMediator);
}

std::unique_ptr<Label> WindowsControlsFactory::createLabel(Mediator *guiMediator)
{
    return std::make_unique<WindowsLabel>(guiMediator);
}

std::unique_ptr<LineEdit> WindowsControlsFactory::createLineEdit(Mediator *guiMediator)
{
    return std::make_unique<WindowsLineEdit>(guiMediator);
}

std::unique_ptr<Window> WindowsControlsFactory::createWindow(Mediator *guiMediator)
{
    return std::make_unique<WindowsWindow>(guiMediator);
}