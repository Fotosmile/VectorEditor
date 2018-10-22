//
// Created by margo on 18.10.18.
//

#ifndef ARCHITECTURE_LINEEDIT_H
#define ARCHITECTURE_LINEEDIT_H

#include <string>

#include "Controls/ControlElement.hpp"

class LineEdit : public ControlElement
{
public:
    explicit LineEdit(Mediator* guiMediator)
            : ControlElement(guiMediator)
    {
    }

    virtual void onFired(const std::string& input) = 0;

    void setLastInput(const std::string& lastInput)
    {
        m_lastInput = lastInput;
    }

    const std::string& getLastInput()
    {
        return m_lastInput;
    }

private:
    std::string m_lastInput;
};


#endif //ARCHITECTURE_LINEEDIT_H
