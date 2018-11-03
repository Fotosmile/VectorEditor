//
// Created by margo on 18.10.18.
//

#ifndef ARCHITECTURE_LINUXLABEL_H
#define ARCHITECTURE_LINUXLABEL_H

#include <functional>

#include "Controls/ILabel.h"

class LinuxLabel : public ILabel
{
public:
    explicit LinuxLabel(const std::function<void()>& trigger);

    void onClicked() override;

private:
    std::function<void()> m_trigger;
};


#endif //ARCHITECTURE_LINUXLABEL_H
