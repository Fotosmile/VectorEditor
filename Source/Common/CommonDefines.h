//
// Created by Vlad on 20/10/18.
//

#ifndef ARCHITECTURE_COMMON_DEFINES_H
#define ARCHITECTURE_COMMON_DEFINES_H

#include <string>

//#define CUR_OS_WINDOWS
#define CUR_OS_LINUX

static const std::size_t defaultWindowWidth = 100;
static const std::size_t defaultWindowHeight = 100;

static const std::string& getDefaultSavePath()
{
    static const std::string defaultSavePath = "/";
    return defaultSavePath;
}

static const std::string& getDefaultSaveName()
{
    static const std::string defaultSaveName = "rasterImage.img";
    return defaultSaveName;
}

#endif //ARCHITECTURE_COMMON_DEFINES_H
