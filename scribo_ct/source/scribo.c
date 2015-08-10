// ---------------------------------------------------------------------------------------------------------------------
// Copyright (c) 2015 Petr Vepřek
// File: scribo.c
// ---------------------------------------------------------------------------------------------------------------------

#include <scribo.h>

#if SCRIBO_SUPPRESS_COUNTER != 1
    // Initialize global message counter
    unsigned long scribo__counter = 0;
#endif

#ifdef SCRIBO_INVOKE_CALLBACK
    #include <stdarg.h>
    // Delegate outputting log message
    void scribo__ouput_message(void (*callback)(const char*), size_t size, const char* format, ...)
    {
        va_list args1; // To get log message length
        va_start(args1, format);
        va_list args2; // To output log message
        va_copy(args2, args1);
        if (0 == size)
        {
            size = vsnprintf(NULL, 0, format, args1);
        }
        va_end(args1);
        char text[1 + size];
        vsnprintf(text, sizeof text, format, args2);
        callback(text); // Delegate
        va_end(args2);
    }
#endif

// End of file ---------------------------------------------------------------------------------------------------------