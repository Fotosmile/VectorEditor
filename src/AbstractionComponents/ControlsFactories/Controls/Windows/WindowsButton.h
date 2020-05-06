//
// Created by Vlad on 09/10/18.
//

#ifndef ARCHITECTURE_WINDOWSBUTTON_H
#define ARCHITECTURE_WINDOWSBUTTON_H

#include <functional>

#include "Controls/IButton.h"

class WindowsButton : public IButton
{
public:
    explicit WindowsButton(const std::function<void()>& trigger);

    void onClicked() override;

private:
    std::function<void()> m_trigger;
};


#endif //ARCHITECTURE_WINDOWSBUTTON_H
