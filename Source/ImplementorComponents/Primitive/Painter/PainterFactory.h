//
// Created by Vlad on 03/11/18.
//

#ifndef ARCHITECTURE_PAINTERFACTORY_H
#define ARCHITECTURE_PAINTERFACTORY_H

#include <memory>

#include "IPainter.h"

std::unique_ptr<IPainter> createPainter();

#endif //ARCHITECTURE_PAINTERFACTORY_H
