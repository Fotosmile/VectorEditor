//
// Created by Vlad on 09/10/18.
//

#ifndef ARCHITECTURE_CREATING_STATE_H
#define ARCHITECTURE_CREATING_STATE_H

#include <memory>

#include "GUIState.h"

class Editor;

class CreatingState : public GUIState
{
public:
    explicit CreatingState(const std::shared_ptr<Editor>& editor);

    StateType getCurrentState() override;

    void create(const std::string& primitiveType) override;
    void group() override;
    void copy() override;

private:
    std::shared_ptr<Editor> m_editor;
};


#endif //ARCHITECTURE_CREATING_STATE_H
