//
// Created by Vlad on 10.10.18.
//

#ifndef ARCHITECTURE_COMMAND_H
#define ARCHITECTURE_COMMAND_H

class ICommand
{
public:
    virtual ~ICommand() = default;

    virtual void undo() = 0;
    virtual void execute() = 0;
};


#endif //ARCHITECTURE_COMMAND_H
