//
// Created by margo on 18.10.18.
//

#ifndef ARCHITECTURE_LINUXLINEEDIT_H
#define ARCHITECTURE_LINUXLINEEDIT_H

#include "Controls/LineEdit.hpp"

class LinuxLineEdit : public LineEdit
{
public:
    explicit LinuxLineEdit(Mediator * guiMediator);
    ~LinuxLineEdit() override = default;

    void onFired(const std::string& input) override;
};


#endif //ARCHITECTURE_LINUXLINEEDIT_H
