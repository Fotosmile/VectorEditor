//
// Created by Vlad on 09/10/18.
//

#ifndef ARCHITECTURE_BUTTON_H
#define ARCHITECTURE_BUTTON_H

class IButton
{
public:
    virtual ~IButton() = default;

    virtual void onClicked() = 0;
};

#endif //ARCHITECTURE_BUTTON_H
