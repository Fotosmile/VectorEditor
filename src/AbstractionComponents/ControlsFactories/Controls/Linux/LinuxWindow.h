//
// Created by margo on 18.10.18.
//

#ifndef ARCHITECTURE_LINUXWINDOW_H
#define ARCHITECTURE_LINUXWINDOW_H

#include <functional>

#include "Controls/IWindow.h"

class LinuxWindow : public IWindow
{
public:
    explicit LinuxWindow(const std::function<void(int, int)>& trigger);

    void onClicked(int x, int y) override;

private:
    std::function<void(int, int)> m_trigger;
};


#endif //ARCHITECTURE_LINUXWINDOW_H
