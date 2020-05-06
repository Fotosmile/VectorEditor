//
// Created by Vlad on 09/10/18.
//

#include <iostream>

#include "ShowNotificationSubscriber.h"
#include "AbstractionState/AbstractionState.h"

void ShowNotificationSubscriber::update(AbstractionState::StateType stateType)
{
    if (stateType == AbstractionState::StateType::Creating)
    {
        std::cout << "System notification: you are running in the creating state" << std::endl;
    }
    else if (stateType == AbstractionState::StateType::Editing)
    {
        std::cout << "System notification: you are running in the editing state" << std::endl;
    }
}