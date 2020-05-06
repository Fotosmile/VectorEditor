//
// Created by margo on 18.10.18.
//

#ifndef ARCHITECTURE_WINDOWSLINEEDIT_H
#define ARCHITECTURE_WINDOWSLINEEDIT_H

#include <functional>

#include "Controls/ILineEdit.h"

class WindowsLineEdit : public ILineEdit
{
public:
    explicit WindowsLineEdit(const std::function<void(const std::string&)>& trigger);

    void onFired(const std::string& input) override;

private:
    std::function<void(const std::string&)> m_trigger;
};


#endif //ARCHITECTURE_WINDOWSLINEEDIT_H
