//
// Created by Vlad on 09/10/18.
//

#ifndef ARCHITECTURE_BUTTON_H
#define ARCHITECTURE_BUTTON_H

#include "Controls/ControlElement.hpp"

class Button : public ControlElement
{
public:
    explicit Button(Mediator* guiMediator)
            : ControlElement(guiMediator)
    {
    }

    virtual void onClicked() = 0;
};

#endif //ARCHITECTURE_BUTTON_H
