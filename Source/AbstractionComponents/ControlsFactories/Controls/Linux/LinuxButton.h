//
// Created by Vlad on 09/10/18.
//

#ifndef ARCHITECTURE_LINUXBUTTON_H
#define ARCHITECTURE_LINUXBUTTON_H

#include <functional>

#include "Controls/IButton.h"

class LinuxButton : public IButton
{
public:
    explicit LinuxButton(const std::function<void()>& trigger);

    void onClicked() override;

private:
    std::function<void()> m_trigger;
};


#endif //ARCHITECTURE_LINUXBUTTON_H
