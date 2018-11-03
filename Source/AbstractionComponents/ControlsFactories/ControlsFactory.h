//
// Created by Vlad on 09/10/18.
//

#ifndef ARCHITECTURE_CONTROLSFACTORY_H
#define ARCHITECTURE_CONTROLSFACTORY_H

#include <memory>
#include <functional>
#include <string>

class IAbstraction;
class IButton;
class ILabel;
class ILineEdit;
class IWindow;

class IControlsFactory
{
public:
    virtual ~IControlsFactory() = default;

    virtual std::unique_ptr<IButton> createButton(const std::function<void()> &trigger) = 0;
    virtual std::unique_ptr<ILabel> createLabel(const std::function<void()> &trigger) = 0;
    virtual std::unique_ptr<ILineEdit> createLineEdit(const std::function<void(const std::string&)> &trigger) = 0;
    virtual std::unique_ptr<IWindow> createWindow(const std::function<void(int, int)> &trigger) = 0;
};

class LinuxControlsFactory : public IControlsFactory
{
public:
    std::unique_ptr<IButton> createButton(const std::function<void()> &trigger) override;
    std::unique_ptr<ILabel> createLabel(const std::function<void()> &trigger) override;
    std::unique_ptr<ILineEdit> createLineEdit(const std::function<void(const std::string&)> &trigger) override;
    std::unique_ptr<IWindow> createWindow(const std::function<void(int, int)> &trigger) override;
};

class WindowsControlsFactory : public IControlsFactory
{
public:
    std::unique_ptr<IButton> createButton(const std::function<void()> &trigger) override;
    std::unique_ptr<ILabel> createLabel(const std::function<void()> &trigger) override;
    std::unique_ptr<ILineEdit> createLineEdit(const std::function<void(const std::string&)> &trigger) override;
    std::unique_ptr<IWindow> createWindow(const std::function<void(int, int)> &trigger) override;
};

std::unique_ptr<IControlsFactory> createControlsFactory();


#endif //ARCHITECTURE_CONTROLSFACTORY_H
