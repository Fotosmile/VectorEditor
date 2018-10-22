//
// Created by margo on 18.10.18.
//

#ifndef ARCHITECTURE_LINUXWINDOW_H
#define ARCHITECTURE_LINUXWINDOW_H

#include "Controls/Window.hpp"

class LinuxWindow : public Window
{
public:
    explicit LinuxWindow(Mediator * guiMediator);
    ~LinuxWindow() override = default;

    void onClicked(int x, int y) override;
};


#endif //ARCHITECTURE_LINUXWINDOW_H
