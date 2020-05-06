//
// Created by Vlad on 09/10/18.
//

#ifndef ARCHITECTURE_CREATING_STATE_H
#define ARCHITECTURE_CREATING_STATE_H

#include <memory>

#include "AbstractionState.h"

class IImplementor;

class CreatingState : public AbstractionState
{
public:
    explicit CreatingState(const std::shared_ptr<IImplementor>& editor);

    StateType getCurrentState() override;

    void create(const std::string& primitiveType) override;
    void group() override;
    void copy() override;

private:
    std::shared_ptr<IImplementor> m_implementor;
};


#endif //ARCHITECTURE_CREATING_STATE_H
