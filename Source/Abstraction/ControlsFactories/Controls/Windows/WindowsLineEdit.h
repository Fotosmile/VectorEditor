//
// Created by margo on 18.10.18.
//

#ifndef ARCHITECTURE_WINDOWSLINEEDIT_H
#define ARCHITECTURE_WINDOWSLINEEDIT_H

#include <memory>

#include "Controls/LineEdit.hpp"

class WindowsLineEdit : public LineEdit
{
public:
    explicit WindowsLineEdit(Mediator * guiMediator);
    ~WindowsLineEdit() override = default;

    void onFired(const std::string& input) override;
};


#endif //ARCHITECTURE_WINDOWSLINEEDIT_H
