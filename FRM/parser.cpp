#include "stdafx.h"
#include "FRM.h"
#include <fstream>
#include <filesystem>

inline void endian_swap(unsigned int& x)
{
    x = (x >> 24) |
        ((x << 8) & 0x00FF0000) |
        ((x >> 8) & 0x0000FF00) |
        (x << 24);
}

FRM loadFile(std::filesystem::path path)
{
    std::ifstream stream;

    stream.open(path, std::ifstream::binary);

    if (not stream.is_open())
        throw std::filesystem::filesystem_error("Can't open file " + path.string(), std::make_error_code(std::io_errc::stream));
    
    FRM file;

    stream.read(reinterpret_cast<char*>(&file.header.version), 4);
    endian_swap(file.header.version);

#if false
    char version[4];
    stream.read(version, 4);

    file.header.version = (int)version[3] | (int)version[2] << 8 | (int)version[1] << 16 | (int)version[0] << 24;
#endif

    return file;
}
