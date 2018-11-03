//
// Created by Vlad on 30/10/18.
//

#ifndef ARCHITECTURE_IIMPLEMENTOR_H
#define ARCHITECTURE_IIMPLEMENTOR_H

#include <memory>
#include <list>

#include "Commands/ICommand.h"

class IPrimitive;

class IImplementor
{
public:
    virtual ~IImplementor() = default;

    virtual void addPrimitive(std::shared_ptr<IPrimitive> primitive) = 0;
    virtual void deletePrimitive(std::shared_ptr<IPrimitive> primitive) = 0;

    virtual void addSelectedPrimitive(std::shared_ptr<IPrimitive> primitive) = 0;
    virtual void deleteSelectedPrimitive(std::shared_ptr<IPrimitive> primitive) = 0;

    virtual std::shared_ptr<IPrimitive> getPrimitiveByCoordinates(int x, int y) = 0;
    virtual const std::list<std::shared_ptr<IPrimitive>> getSelectedPrimitives() = 0;

    virtual void undo() = 0;
    virtual void executeCommand(std::unique_ptr<ICommand> command) = 0;

    virtual void saveWithFilters(const std::string& filtersStr) = 0;
};


#endif //ARCHITECTURE_IIMPLEMENTOR_H
