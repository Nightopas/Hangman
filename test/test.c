#define CTEST_MAIN

<<<<<<< HEAD
#include <ctest.h>
=======
#include "HangFileRead.h"
#include <ctest.h>
#include <stdio.h>
#include <stdlib.h>

CTEST(filenametest, Emptyfilename)
{
    char* filename = "";
    ASSERT_NULL(read_file(filename, 10));
}
>>>>>>> issue-1

int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}
