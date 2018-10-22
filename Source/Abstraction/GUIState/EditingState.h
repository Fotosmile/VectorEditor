//
// Created by Vlad on 09/10/18.
//

#ifndef ARCHITECTURE_EDITINGSTATE_H
#define ARCHITECTURE_EDITINGSTATE_H

#include <memory>

#include "GUIState.h"

class Editor;

class EditingState : public GUIState
{
public:
    explicit EditingState(const std::shared_ptr<Editor>& editor);

    StateType getCurrentState() override;

    void select(int x, int y) override;
    void unselect(int x, int y) override;
    void move(int x, int y) override;
    void changeSize(int x, int y) override;
    void changeColor(const Color& newColor) override;
    void deleteSelected() override;

private:
    std::shared_ptr<Editor> m_editor;
};


#endif //ARCHITECTURE_EDITINGSTATE_H
