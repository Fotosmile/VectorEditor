//
// Created by Vlad on 09/10/18.
//

#ifndef ARCHITECTURE_LINUXBUTTON_H
#define ARCHITECTURE_LINUXBUTTON_H

#include "Controls/Button.hpp"

class LinuxButton : public Button
{
public:
    explicit LinuxButton(Mediator * guiMediator);
    ~LinuxButton() override = default;

    void onClicked() override;
};


#endif //ARCHITECTURE_LINUXBUTTON_H
