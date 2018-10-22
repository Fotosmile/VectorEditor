//
// Created by Vlad on 09/10/18.
//

#ifndef ARCHITECTURE_WINDOWSBUTTON_H
#define ARCHITECTURE_WINDOWSBUTTON_H

#include <memory>

#include "Controls/Button.hpp"

class WindowsButton : public Button
{
public:
    explicit WindowsButton(Mediator * guiMediator);
    ~WindowsButton() override = default;

    void onClicked() override;
};


#endif //ARCHITECTURE_WINDOWSBUTTON_H
