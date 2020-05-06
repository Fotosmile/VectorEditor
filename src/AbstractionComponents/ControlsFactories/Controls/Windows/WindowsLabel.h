//
// Created by margo on 18.10.18.
//

#ifndef ARCHITECTURE_WINDOWSLABEL_H
#define ARCHITECTURE_WINDOWSLABEL_H

#include <functional>

#include "Controls/ILabel.h"

class WindowsLabel : public ILabel
{
public:
    explicit WindowsLabel(const std::function<void()>& trigger);

    void onClicked() override;

private:
    std::function<void()> m_trigger;
};


#endif //ARCHITECTURE_WINDOWSLABEL_H
