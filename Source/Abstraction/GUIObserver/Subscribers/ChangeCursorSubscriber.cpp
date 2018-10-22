//
// Created by Vlad on 09/10/18.
//

#include <iostream>

#include "ChangeCursorSubscriber.h"
#include "GUIState/GUIState.h"

void ChangeCursorSubscriber::update(GUIState::StateType stateType)
{
    if (stateType == GUIState::StateType::Creating)
    {
        std::cout << "Now the cursor is in creating state" << std::endl;
    }
    else if (stateType == GUIState::StateType::Editing)
    {
        std::cout << "Now the cursor is in editing state" << std::endl;
    }
}