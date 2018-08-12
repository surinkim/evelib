// EveTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "string_test.h"
#include "directory_test.h"

int main(int argc, char** argv)
{
    testing::InitGoogleMock(&argc, argv);
    RUN_ALL_TESTS();
    getchar();
    return 0;
}

