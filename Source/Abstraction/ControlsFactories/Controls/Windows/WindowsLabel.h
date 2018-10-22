//
// Created by margo on 18.10.18.
//

#ifndef ARCHITECTURE_WINDOWSLABEL_H
#define ARCHITECTURE_WINDOWSLABEL_H

#include <memory>

#include "Controls/Label.hpp"

class WindowsLabel : public Label
{
public:
    explicit WindowsLabel(Mediator * guiMediator);
    ~WindowsLabel() override = default;

    void onClicked() override;
};


#endif //ARCHITECTURE_WINDOWSLABEL_H
