//
// Created by Vlad on 09/10/18.
//

#include "ControlsFactory.h"
#include "Common/CommonDefines.h"

#include "Controls/Linux/LinuxButton.h"
#include "Controls/Linux/LinuxLabel.h"
#include "Controls/Linux/LinuxLineEdit.h"
#include "Controls/Linux/LinuxWindow.h"

#include "Controls/Windows/WindowsButton.h"
#include "Controls/Windows/WindowsLabel.h"
#include "Controls/Windows/WindowsLineEdit.h"
#include "Controls/Windows/WindowsWindow.h"

std::unique_ptr<IButton> LinuxControlsFactory::createButton(const std::function<void()> &trigger)
{
    return std::make_unique<LinuxButton>(trigger);
}

std::unique_ptr<ILabel> LinuxControlsFactory::createLabel(const std::function<void()> &trigger)
{
    return std::make_unique<LinuxLabel>(trigger);
}

std::unique_ptr<ILineEdit> LinuxControlsFactory::createLineEdit(const std::function<void(const std::string&)> &trigger)
{
    return std::make_unique<LinuxLineEdit>(trigger);
}

std::unique_ptr<IWindow> LinuxControlsFactory::createWindow(const std::function<void(int, int)> &trigger)
{
    return std::make_unique<LinuxWindow>(trigger);
}

std::unique_ptr<IButton> WindowsControlsFactory::createButton(const std::function<void()> &trigger)
{
    return std::make_unique<WindowsButton>(trigger);
}

std::unique_ptr<ILabel> WindowsControlsFactory::createLabel(const std::function<void()> &trigger)
{
    return std::make_unique<WindowsLabel>(trigger);
}

std::unique_ptr<ILineEdit> WindowsControlsFactory::createLineEdit(const std::function<void(const std::string&)> &trigger)
{
    return std::make_unique<WindowsLineEdit>(trigger);
}

std::unique_ptr<IWindow> WindowsControlsFactory::createWindow(const std::function<void(int, int)> &trigger)
{
    return std::make_unique<WindowsWindow>(trigger);
}

std::unique_ptr<IControlsFactory> createControlsFactory()
{
#ifdef CUR_OS_WINDOWS
    return std::make_unique<WindowsControlsFactory>();
#elif defined(CUR_OS_LINUX)
    return std::make_unique<LinuxControlsFactory>();
#else
#error
#endif
}