//
// Created by margo on 18.10.18.
//

#ifndef ARCHITECTURE_WINDOWSWINDOW_H
#define ARCHITECTURE_WINDOWSWINDOW_H

#include <memory>

#include "Controls/Window.hpp"

class WindowsWindow : public Window
{
public:
    explicit WindowsWindow(Mediator * guiMediator);
    ~WindowsWindow() override = default;

    void onClicked(int x, int y) override;
};


#endif //ARCHITECTURE_WINDOWSWINDOW_H
