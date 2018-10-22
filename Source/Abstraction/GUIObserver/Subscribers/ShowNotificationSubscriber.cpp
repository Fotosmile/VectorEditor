//
// Created by Vlad on 09/10/18.
//

#include <iostream>

#include "ShowNotificationSubscriber.h"
#include "GUIState/GUIState.h"

void ShowNotificationSubscriber::update(GUIState::StateType stateType)
{
    if (stateType == GUIState::StateType::Creating)
    {
        std::cout << "System notification: you are running in the creating state" << std::endl;
    }
    else if (stateType == GUIState::StateType::Editing)
    {
        std::cout << "System notification: you are running in the editing state" << std::endl;
    }
}