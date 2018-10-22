//
// Created by Vlad on 09/10/18.
//

#ifndef ARCHITECTURE_CONTROLELEMENT_H
#define ARCHITECTURE_CONTROLELEMENT_H

class Mediator;

class ControlElement
{
public:
    explicit ControlElement(Mediator* guiMediator)
            : m_guiMediator(guiMediator)
    {
    }

    virtual ~ControlElement() = default;

protected:
    Mediator* getGUIMediator()
    {
        return m_guiMediator;
    }

private:
    Mediator* m_guiMediator;
};


#endif //ARCHITECTURE_CONTROLELEMENT_H
