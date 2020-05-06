//
// Created by margo on 18.10.18.
//

#ifndef ARCHITECTURE_LINEEDIT_H
#define ARCHITECTURE_LINEEDIT_H

#include <string>

class ILineEdit
{
public:
    virtual ~ILineEdit() = default;

    virtual void onFired(const std::string& input) = 0;
};


#endif //ARCHITECTURE_LINEEDIT_H
