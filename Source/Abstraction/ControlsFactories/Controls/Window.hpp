//
// Created by margo on 18.10.18.
//

#ifndef ARCHITECTURE_WINDOW_H
#define ARCHITECTURE_WINDOW_H

#include <utility>

#include "Controls/ControlElement.hpp"

class Window : public ControlElement
{
public:
    using Coordinates_t = std::pair<int, int>;

    explicit Window(Mediator* guiMediator)
            : ControlElement(guiMediator)
    {
    }

    virtual void onClicked(int x, int y) = 0;

    void setLastClickCoordinates(const Coordinates_t& coordinates)
    {
        m_lastClickCoordinates = coordinates;
    }

    Coordinates_t getLastClickCoordinates()
    {
        return m_lastClickCoordinates;
    }

private:
    Coordinates_t m_lastClickCoordinates;
};


#endif //ARCHITECTURE_WINDOW_H
