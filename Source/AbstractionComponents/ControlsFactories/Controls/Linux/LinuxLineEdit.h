//
// Created by margo on 18.10.18.
//

#ifndef ARCHITECTURE_LINUXLINEEDIT_H
#define ARCHITECTURE_LINUXLINEEDIT_H

#include <functional>

#include "Controls/ILineEdit.h"

class LinuxLineEdit : public ILineEdit
{
public:
    explicit LinuxLineEdit(const std::function<void(const std::string&)>& trigger);

    void onFired(const std::string& input) override;

private:
    std::function<void(const std::string&)> m_trigger;
};


#endif //ARCHITECTURE_LINUXLINEEDIT_H
