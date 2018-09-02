#include "pch.h"
#include "../FRM/FRM.h"
#include <filesystem>

struct FRMTests : public ::testing::Test
{

};

TEST(Loader, LoadFile) {
    std::filesystem::path p = "../FRMTests/MAINMENU.FRM";
    std::filesystem::path absPath = std::filesystem::absolute(p);
    FRM file = loadFile(absPath);

    ASSERT_EQ(file.header.version, 0x04);
}
