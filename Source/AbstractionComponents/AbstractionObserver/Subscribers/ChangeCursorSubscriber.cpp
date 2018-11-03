//
// Created by Vlad on 09/10/18.
//

#include <iostream>

#include "ChangeCursorSubscriber.h"
#include "AbstractionState/AbstractionState.h"

void ChangeCursorSubscriber::update(AbstractionState::StateType stateType)
{
    if (stateType == AbstractionState::StateType::Creating)
    {
        std::cout << "Now the cursor is in creating state" << std::endl;
    }
    else if (stateType == AbstractionState::StateType::Editing)
    {
        std::cout << "Now the cursor is in editing state" << std::endl;
    }
}