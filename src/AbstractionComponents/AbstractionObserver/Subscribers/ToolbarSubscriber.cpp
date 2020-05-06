//
// Created by Vlad on 09/10/18.
//

#include <iostream>

#include "ToolbarSubscriber.h"
#include "AbstractionState/AbstractionState.h"

void ToolbarSubscriber::update(AbstractionState::StateType stateType)
{
    if (stateType == AbstractionState::StateType::Creating)
    {
        std::cout << "Now your toolbar is in creating state" << std::endl;
    }
    else if (stateType == AbstractionState::StateType::Editing)
    {
        std::cout << "Now your toolbar is in editing state" << std::endl;
    }
}