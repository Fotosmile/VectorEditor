//
// Created by Vlad on 09/10/18.
//

#ifndef ARCHITECTURE_CONTROLSFACTORY_H
#define ARCHITECTURE_CONTROLSFACTORY_H

#include <memory>

class Mediator;
class Button;
class Label;
class LineEdit;
class Window;

class ControlsFactory
{
public:
    virtual ~ControlsFactory() = default;

    virtual std::unique_ptr<Button> createButton(Mediator * guiMediator) = 0;
    virtual std::unique_ptr<Label> createLabel(Mediator * guiMediator) = 0;
    virtual std::unique_ptr<LineEdit> createLineEdit(Mediator * guiMediator) = 0;
    virtual std::unique_ptr<Window> createWindow(Mediator * guiMediator) = 0;
};

class LinuxControlsFactory : public ControlsFactory
{
public:
    std::unique_ptr<Button> createButton(Mediator * guiMediator) override;
    std::unique_ptr<Label> createLabel(Mediator * guiMediator) override;
    std::unique_ptr<LineEdit> createLineEdit(Mediator * guiMediator) override;
    std::unique_ptr<Window> createWindow(Mediator * guiMediator) override;
};

class WindowsControlsFactory : public ControlsFactory
{
public:
    std::unique_ptr<Button> createButton(Mediator * guiMediator) override;
    std::unique_ptr<Label> createLabel(Mediator * guiMediator) override;
    std::unique_ptr<LineEdit> createLineEdit(Mediator * guiMediator) override;
    std::unique_ptr<Window> createWindow(Mediator * guiMediator) override;
};


#endif //ARCHITECTURE_CONTROLSFACTORY_H
