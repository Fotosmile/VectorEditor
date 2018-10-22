//
// Created by margo on 18.10.18.
//

#ifndef ARCHITECTURE_LINUXLABEL_H
#define ARCHITECTURE_LINUXLABEL_H

#include "Controls/Label.hpp"

class LinuxLabel : public Label
{
public:
    explicit LinuxLabel(Mediator * guiMediator);
    ~LinuxLabel() override = default;

    void onClicked() override;
};


#endif //ARCHITECTURE_LINUXLABEL_H
