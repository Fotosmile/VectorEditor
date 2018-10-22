//
// Created by margo on 18.10.18.
//

#ifndef ARCHITECTURE_LABEL_H
#define ARCHITECTURE_LABEL_H

#include "Controls/ControlElement.hpp"

class Label : public ControlElement
{
public:
    explicit Label(Mediator* guiMediator)
            : ControlElement(guiMediator)
    {
    }

    virtual void onClicked() = 0;
};

#endif //ARCHITECTURE_LABEL_H
