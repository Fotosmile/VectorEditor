//
// Created by margo on 18.10.18.
//

#ifndef ARCHITECTURE_WINDOW_H
#define ARCHITECTURE_WINDOW_H

class IWindow
{
public:
    virtual ~IWindow() = default;

    virtual void onClicked(int x, int y) = 0;
};


#endif //ARCHITECTURE_WINDOW_H
