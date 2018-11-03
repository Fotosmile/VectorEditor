//
// Created by margo on 18.10.18.
//

#ifndef ARCHITECTURE_WINDOWSWINDOW_H
#define ARCHITECTURE_WINDOWSWINDOW_H

#include <functional>

#include "Controls/IWindow.h"

class WindowsWindow : public IWindow
{
public:
    explicit WindowsWindow(const std::function<void(int, int)>& trigger);

    void onClicked(int x, int y) override;

private:
    std::function<void(int, int)> m_trigger;
};


#endif //ARCHITECTURE_WINDOWSWINDOW_H
