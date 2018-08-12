#include <gmock/gmock.h>

#include <eve.h>

using testing::Eq;

TEST(EveDirectory, Create)
{
    fs::path curPath = fs::current_path();
    eve::Result ret = eve::CreateDirectory(curPath / "Temp");
    EXPECT_TRUE(ret.first);
}

TEST(EveDirectory, Remove)
{
    fs::path curPath = fs::current_path();
    eve::Result ret = eve::RemoveDirectory(curPath / "Temp");
    EXPECT_TRUE(ret.first);
}

TEST(EveDirectory, Enumerate)
{
    fs::path curPath = fs::current_path();
    eve::Result ret = 
        eve::EnumerateDirectory(curPath / "Temp",
            [](const std::string& name) 
                { std::cout << name.c_str() 
                    << " is directory."
                    << std::endl; },
            [](const std::string& name) 
                { std::cout << name.c_str()
                    << " is file."
                    << std::endl; });

    EXPECT_FALSE(ret.first);
    EXPECT_EQ(ret.second, 
              fs::current_path() / 
              "Temp is not a directory.");
}