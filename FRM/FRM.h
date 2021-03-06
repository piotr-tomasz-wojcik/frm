#pragma once

#include "resource.h"
#include <vector>
#include <filesystem>

using u8 = unsigned char;
using u16 = unsigned short;
using u32 = unsigned int;
using i16 = short int;

constexpr unsigned NUMBER_OF_DIRECTIONS = 6;

struct Frame
{
    u16 width;
    u16 height;
    u32 size;
    i16 offsetX;
    i16 offsetY;

    std::vector<u8> colorIndex;
};


struct Header
{
    uint32_t version;

    u16 fps;
    u16 actionFrame;
    u16 numberOfFramesPerDirection;

    i16 frameShiftX[NUMBER_OF_DIRECTIONS];
    i16 frameShiftY[NUMBER_OF_DIRECTIONS];

    u32 offsetOfFirstFrame[NUMBER_OF_DIRECTIONS];
    u32 frameAreaSize;
};

struct FRM
{
    Header header;
    std::vector<Frame> frames;
};

FRM loadFile(std::filesystem::path path);
