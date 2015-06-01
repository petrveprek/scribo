// ---------------------------------------------------------------------------------------------------------------------
// Copyright (c) 2015 Petr Vepřek
// File: main.c
// ---------------------------------------------------------------------------------------------------------------------

#define SCRIBO_CATEGORY MAIN_APP
#include "scribo.h"

int main(int argc, char* argv[])
{
    if (argc >= 1)
    {
        SCRIBO(LOG, "Running %s", argv[0]);
    }
    return 0;
}

// End of file ---------------------------------------------------------------------------------------------------------