//
// Created by Vlad on 10.10.18.
//

#ifndef ARCHITECTURE_COLOR_H
#define ARCHITECTURE_COLOR_H

#include <string>

class Color
{
public:
    Color();
    explicit Color(const std::string& color);
    Color(int r, int g, int b);

    int getR() const;
    int getG()const;
    int getB()const;

    void setColor(int r, int g, int b);

private:
    int m_r;
    int m_g;
    int m_b;
};


#endif //ARCHITECTURE_COLOR_H
