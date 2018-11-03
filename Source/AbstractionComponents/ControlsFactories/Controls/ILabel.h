//
// Created by margo on 18.10.18.
//

#ifndef ARCHITECTURE_LABEL_H
#define ARCHITECTURE_LABEL_H

class ILabel
{
public:
    virtual ~ILabel() = default;

    virtual void onClicked() = 0;
};

#endif //ARCHITECTURE_LABEL_H
