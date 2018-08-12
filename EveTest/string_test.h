#include <gmock/gmock.h>

#include <eve.h>

using testing::Eq;

TEST(EveString, LTrim)
{
    std::string s = " test string ";
    EXPECT_THAT(eve::LTrim(s, ' '),
        Eq("test string "));

    std::wstring ws = L" test wide string ";
    EXPECT_THAT(eve::LTrim(ws, L' '),
        Eq(L"test wide string "));
}

TEST(EveString, RTim)
{
    std::string s = " test string ";
    EXPECT_THAT(eve::RTrim(s, ' '),
        Eq(" test string"));

    std::wstring ws = L" test wide string ";
    EXPECT_THAT(eve::RTrim(ws, L' '),
        Eq(L" test wide string"));
}

TEST(EveString, Trim)
{
    std::string s = " test string ";
    EXPECT_THAT(eve::Trim(s, ' '),
        Eq("test string"));

    std::wstring ws = L" test wide string ";
    EXPECT_THAT(eve::Trim(ws, L' '),
        Eq(L"test wide string"));
}