// ---------------------------------------------------------------------------------------------------------------------
// Copyright (c) 2015 Petr Vepřek
// File: scribo.h
// ---------------------------------------------------------------------------------------------------------------------

#pragma once

#include <scribo.cfg>

// Detect macro conflicts
#if defined(SCRIBO)
#   error "Macro SCRIBO is already defined!"
#endif
#if defined(SCRIBOF) || defined(SCRIBOE) || defined(SCRIBOW) || defined(SCRIBOL) || \
    defined(SCRIBOI) || defined(SCRIBOD) || defined(SCRIBOM) || defined(SCRIBOT)
#   error "Macro SCRIBOF, SCRIBOE, SCRIBOW, SCRIBOL, SCRIBOI, SCRIBOD, SCRIBOM, or SCRIBOT is already defined!"
#endif

// To scribo or not to scribo
#if SCRIBO_DISABLE_ALL == 1
    
    // Remove scribo when disabled
#   define SCRIBO(...)
#   define SCRIBOF(...)
#   define SCRIBOE(...)
#   define SCRIBOW(...)
#   define SCRIBOL(...)
#   define SCRIBOI(...)
#   define SCRIBOD(...)
#   define SCRIBOM(...)
#   define SCRIBOT(...)
    
#else
    
    // Interpret configuration shorthand
#   if           (SCRIBO_DISABLE_VERBOSITY_FATAL_ETC == 1)
#       ifdef     SCRIBO_DISABLE_VERBOSITY_FATAL
#           undef SCRIBO_DISABLE_VERBOSITY_FATAL
#       endif
#       define    SCRIBO_DISABLE_VERBOSITY_FATAL 1
#   endif
#   if           (SCRIBO_DISABLE_VERBOSITY_FATAL_ETC == 1) || \
                 (SCRIBO_DISABLE_VERBOSITY_ERROR_ETC == 1)
#       ifdef     SCRIBO_DISABLE_VERBOSITY_ERROR
#           undef SCRIBO_DISABLE_VERBOSITY_ERROR
#       endif
#       define    SCRIBO_DISABLE_VERBOSITY_ERROR 1
#   endif
#   if           (SCRIBO_DISABLE_VERBOSITY_FATAL_ETC   == 1) || \
                 (SCRIBO_DISABLE_VERBOSITY_ERROR_ETC   == 1) || \
                 (SCRIBO_DISABLE_VERBOSITY_WARNING_ETC == 1)
#       ifdef     SCRIBO_DISABLE_VERBOSITY_WARNING
#           undef SCRIBO_DISABLE_VERBOSITY_WARNING
#       endif
#       define    SCRIBO_DISABLE_VERBOSITY_WARNING 1
#   endif
#   if           (SCRIBO_DISABLE_VERBOSITY_FATAL_ETC   == 1) || \
                 (SCRIBO_DISABLE_VERBOSITY_ERROR_ETC   == 1) || \
                 (SCRIBO_DISABLE_VERBOSITY_WARNING_ETC == 1) || \
                 (SCRIBO_DISABLE_VERBOSITY_LOG_ETC     == 1)
#       ifdef     SCRIBO_DISABLE_VERBOSITY_LOG
#           undef SCRIBO_DISABLE_VERBOSITY_LOG
#       endif
#       define    SCRIBO_DISABLE_VERBOSITY_LOG 1
#   endif
#   if           (SCRIBO_DISABLE_VERBOSITY_FATAL_ETC   == 1) || \
                 (SCRIBO_DISABLE_VERBOSITY_ERROR_ETC   == 1) || \
                 (SCRIBO_DISABLE_VERBOSITY_WARNING_ETC == 1) || \
                 (SCRIBO_DISABLE_VERBOSITY_LOG_ETC     == 1) || \
                 (SCRIBO_DISABLE_VERBOSITY_INFO_ETC    == 1)
#       ifdef     SCRIBO_DISABLE_VERBOSITY_INFO
#           undef SCRIBO_DISABLE_VERBOSITY_INFO
#       endif
#       define    SCRIBO_DISABLE_VERBOSITY_INFO 1
#   endif
#   if           (SCRIBO_DISABLE_VERBOSITY_FATAL_ETC   == 1) || \
                 (SCRIBO_DISABLE_VERBOSITY_ERROR_ETC   == 1) || \
                 (SCRIBO_DISABLE_VERBOSITY_WARNING_ETC == 1) || \
                 (SCRIBO_DISABLE_VERBOSITY_LOG_ETC     == 1) || \
                 (SCRIBO_DISABLE_VERBOSITY_INFO_ETC    == 1) || \
                 (SCRIBO_DISABLE_VERBOSITY_DEBUG_ETC   == 1)
#       ifdef     SCRIBO_DISABLE_VERBOSITY_DEBUG
#           undef SCRIBO_DISABLE_VERBOSITY_DEBUG
#       endif
#       define    SCRIBO_DISABLE_VERBOSITY_DEBUG 1
#   endif
#   if           (SCRIBO_DISABLE_VERBOSITY_FATAL_ETC   == 1) || \
                 (SCRIBO_DISABLE_VERBOSITY_ERROR_ETC   == 1) || \
                 (SCRIBO_DISABLE_VERBOSITY_WARNING_ETC == 1) || \
                 (SCRIBO_DISABLE_VERBOSITY_LOG_ETC     == 1) || \
                 (SCRIBO_DISABLE_VERBOSITY_INFO_ETC    == 1) || \
                 (SCRIBO_DISABLE_VERBOSITY_DEBUG_ETC   == 1) || \
                 (SCRIBO_DISABLE_VERBOSITY_METHOD_ETC  == 1)
#       ifdef     SCRIBO_DISABLE_VERBOSITY_METHOD
#           undef SCRIBO_DISABLE_VERBOSITY_METHOD
#       endif
#       define    SCRIBO_DISABLE_VERBOSITY_METHOD 1
#   endif
#   if           (SCRIBO_DISABLE_VERBOSITY_FATAL_ETC   == 1) || \
                 (SCRIBO_DISABLE_VERBOSITY_ERROR_ETC   == 1) || \
                 (SCRIBO_DISABLE_VERBOSITY_WARNING_ETC == 1) || \
                 (SCRIBO_DISABLE_VERBOSITY_LOG_ETC     == 1) || \
                 (SCRIBO_DISABLE_VERBOSITY_INFO_ETC    == 1) || \
                 (SCRIBO_DISABLE_VERBOSITY_DEBUG_ETC   == 1) || \
                 (SCRIBO_DISABLE_VERBOSITY_METHOD_ETC  == 1) || \
                 (SCRIBO_DISABLE_VERBOSITY_TRACE_ETC   == 1)
#       ifdef     SCRIBO_DISABLE_VERBOSITY_TRACE
#           undef SCRIBO_DISABLE_VERBOSITY_TRACE
#       endif
#       define    SCRIBO_DISABLE_VERBOSITY_TRACE 1
#   endif
    
    // Interpret usage shorthand
#   define SCRIBOF(...) SCRIBO(FATAL,   __VA_ARGS__)
#   define SCRIBOE(...) SCRIBO(ERROR,   __VA_ARGS__)
#   define SCRIBOW(...) SCRIBO(WARNING, __VA_ARGS__)
#   define SCRIBOL(...) SCRIBO(LOG,     __VA_ARGS__)
#   define SCRIBOI(...) SCRIBO(INFO,    __VA_ARGS__)
#   define SCRIBOD(...) SCRIBO(DEBUG,   __VA_ARGS__)
#   define SCRIBOM(...) SCRIBO(METHOD,  __VA_ARGS__)
#   define SCRIBOT(...) SCRIBO(TRACE,   __VA_ARGS__)
    
    // Define general helpers
#   define SCRIBO__EXPAND_1(_1) _1
#   define SCRIBO__INVOKE_2(   _0, _1, _2)                  _0(_1, _2)
#   define SCRIBO__INVOKE_5ETC(_0, _1, _2, _3, _4, _5, ...) _0(_1, _2, _3, _4, _5, __VA_ARGS__)
#   define SCRIBO__PASTE_2(_1, _2)         _1 ## _2
#   define SCRIBO__PASTE_3(_1, _2, _3)     _1 ## _2 ## _3
#   define SCRIBO__PASTE_4(_1, _2, _3, _4) _1 ## _2 ## _3 ## _4
#   define SCRIBO__PICK_23RD(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, \
        _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, ...) _23
#   define SCRIBO__GET_HAS_COMMA(...) SCRIBO__EXPAND_1(SCRIBO__PICK_23RD(__VA_ARGS__, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0))
#   define SCRIBO__TRIGGER_NIL_TO_COMMA(...) ,
#   define SCRIBO__GET_IS_EMPTY(...) SCRIBO__GET_HAS_NO_COMMA_IS_NOT_EMPTY( \
        SCRIBO__GET_HAS_COMMA(__VA_ARGS__), \
        SCRIBO__GET_HAS_COMMA(SCRIBO__TRIGGER_NIL_TO_COMMA __VA_ARGS__ ()))
#   define SCRIBO__TRIGGER_EMPTY_CASE_0_1 ,
#   define SCRIBO__GET_HAS_NO_COMMA_IS_NOT_EMPTY(_1, _2) \
        SCRIBO__GET_HAS_COMMA(SCRIBO__PASTE_4(SCRIBO__TRIGGER_EMPTY_CASE_, _1, _, _2))
    
    // Initialize default category
#   ifndef     SCRIBO_CATEGORY
#       define SCRIBO_CATEGORY GENERIC
#   endif
    
    // Configure disabling current category
#   define SCRIBO__GET_CATEGORY_DISABLED(CATEGORY) \
        SCRIBO__PASTE_2(SCRIBO_DISABLE_CATEGORY_, CATEGORY)
#   if SCRIBO__GET_CATEGORY_DISABLED(SCRIBO_CATEGORY) == 1
#       define SCRIBO__DISABLE_CATEGORY 1
#   else
#       define SCRIBO__DISABLE_CATEGORY 0
#   endif
    
    // Configure disabling known verbosities
#   if            SCRIBO_DISABLE_VERBOSITY_FATAL != 1
#       ifdef     SCRIBO_DISABLE_VERBOSITY_FATAL
#           undef SCRIBO_DISABLE_VERBOSITY_FATAL
#       endif
#       define    SCRIBO_DISABLE_VERBOSITY_FATAL 0
#   endif
#   if            SCRIBO_DISABLE_VERBOSITY_ERROR != 1
#       ifdef     SCRIBO_DISABLE_VERBOSITY_ERROR
#           undef SCRIBO_DISABLE_VERBOSITY_ERROR
#       endif
#       define    SCRIBO_DISABLE_VERBOSITY_ERROR 0
#   endif
#   if            SCRIBO_DISABLE_VERBOSITY_WARNING != 1
#       ifdef     SCRIBO_DISABLE_VERBOSITY_WARNING
#           undef SCRIBO_DISABLE_VERBOSITY_WARNING
#       endif
#       define    SCRIBO_DISABLE_VERBOSITY_WARNING 0
#   endif
#   if            SCRIBO_DISABLE_VERBOSITY_LOG != 1
#       ifdef     SCRIBO_DISABLE_VERBOSITY_LOG
#           undef SCRIBO_DISABLE_VERBOSITY_LOG
#       endif
#       define    SCRIBO_DISABLE_VERBOSITY_LOG 0
#   endif
#   if            SCRIBO_DISABLE_VERBOSITY_INFO != 1
#       ifdef     SCRIBO_DISABLE_VERBOSITY_INFO
#           undef SCRIBO_DISABLE_VERBOSITY_INFO
#       endif
#       define    SCRIBO_DISABLE_VERBOSITY_INFO 0
#   endif
#   if            SCRIBO_DISABLE_VERBOSITY_DEBUG != 1
#       ifdef     SCRIBO_DISABLE_VERBOSITY_DEBUG
#           undef SCRIBO_DISABLE_VERBOSITY_DEBUG
#       endif
#       define    SCRIBO_DISABLE_VERBOSITY_DEBUG 0
#   endif
#   if            SCRIBO_DISABLE_VERBOSITY_METHOD != 1
#       ifdef     SCRIBO_DISABLE_VERBOSITY_METHOD
#           undef SCRIBO_DISABLE_VERBOSITY_METHOD
#       endif
#       define    SCRIBO_DISABLE_VERBOSITY_METHOD 0
#   endif
#   if            SCRIBO_DISABLE_VERBOSITY_TRACE != 1
#       ifdef     SCRIBO_DISABLE_VERBOSITY_TRACE
#           undef SCRIBO_DISABLE_VERBOSITY_TRACE
#       endif
#       define    SCRIBO_DISABLE_VERBOSITY_TRACE 0
#   endif
    
    // Configure enabling combinations of current category & known verbosities
#   define SCRIBO__GET_COMBO_ENABLED(CATEGORY, VERBOSITY) \
        SCRIBO__PASTE_3(SCRIBO_ENABLE_CATEGORY_, CATEGORY, _VERBOSITY_ ## VERBOSITY)
#   if SCRIBO__GET_COMBO_ENABLED(SCRIBO_CATEGORY, FATAL) == 1
#       define SCRIBO__ENABLE_COMBO_FATAL 1
#   else
#       define SCRIBO__ENABLE_COMBO_FATAL 0
#   endif
#   if SCRIBO__GET_COMBO_ENABLED(SCRIBO_CATEGORY, ERROR) == 1
#       define SCRIBO__ENABLE_COMBO_ERROR 1
#   else
#       define SCRIBO__ENABLE_COMBO_ERROR 0
#   endif
#   if SCRIBO__GET_COMBO_ENABLED(SCRIBO_CATEGORY, WARNING) == 1
#       define SCRIBO__ENABLE_COMBO_WARNING 1
#   else
#       define SCRIBO__ENABLE_COMBO_WARNING 0
#   endif
#   if SCRIBO__GET_COMBO_ENABLED(SCRIBO_CATEGORY, LOG) == 1
#       define SCRIBO__ENABLE_COMBO_LOG 1
#   else
#       define SCRIBO__ENABLE_COMBO_LOG 0
#   endif
#   if SCRIBO__GET_COMBO_ENABLED(SCRIBO_CATEGORY, INFO) == 1
#       define SCRIBO__ENABLE_COMBO_INFO 1
#   else
#       define SCRIBO__ENABLE_COMBO_INFO 0
#   endif
#   if SCRIBO__GET_COMBO_ENABLED(SCRIBO_CATEGORY, DEBUG) == 1
#       define SCRIBO__ENABLE_COMBO_DEBUG 1
#   else
#       define SCRIBO__ENABLE_COMBO_DEBUG 0
#   endif
#   if SCRIBO__GET_COMBO_ENABLED(SCRIBO_CATEGORY, METHOD) == 1
#       define SCRIBO__ENABLE_COMBO_METHOD 1
#   else
#       define SCRIBO__ENABLE_COMBO_METHOD 0
#   endif
#   if SCRIBO__GET_COMBO_ENABLED(SCRIBO_CATEGORY, TRACE) == 1
#       define SCRIBO__ENABLE_COMBO_TRACE 1
#   else
#       define SCRIBO__ENABLE_COMBO_TRACE 0
#   endif
    
    // Setup default verbosity and auto-fill values
#   define SCRIBO__DEFAULT_VERBOSITY_0
#   define SCRIBO__DEFAULT_VERBOSITY_1 TRACE
#   define SCRIBO__AUTO_FILL_FATAL_0
#   define SCRIBO__AUTO_FILL_ERROR_0
#   define SCRIBO__AUTO_FILL_WARNING_0
#   define SCRIBO__AUTO_FILL_LOG_0
#   define SCRIBO__AUTO_FILL_INFO_0
#   define SCRIBO__AUTO_FILL_DEBUG_0
#   define SCRIBO__AUTO_FILL_METHOD_0
#   define SCRIBO__AUTO_FILL_TRACE_0
#   if SCRIBO_SUPPRESS_AUTO_FILL == 1
#       define SCRIBO__AUTO_FILL_FATAL_1   ""
#       define SCRIBO__AUTO_FILL_ERROR_1   ""
#       define SCRIBO__AUTO_FILL_WARNING_1 ""
#       define SCRIBO__AUTO_FILL_LOG_1     ""
#       define SCRIBO__AUTO_FILL_INFO_1    ""
#       define SCRIBO__AUTO_FILL_DEBUG_1   ""
#       define SCRIBO__AUTO_FILL_METHOD_1  ""
#       define SCRIBO__AUTO_FILL_TRACE_1   ""
#   else
#       define SCRIBO__AUTO_FILL_FATAL_1   "%s", "GAME OVER!"
#       define SCRIBO__AUTO_FILL_ERROR_1   "%s", "D'oh!"
#       define SCRIBO__AUTO_FILL_WARNING_1 "%s", "Oops"
#       define SCRIBO__AUTO_FILL_LOG_1     "%s", "Fiat lux"
#       define SCRIBO__AUTO_FILL_INFO_1    "%s", "Et cetera"
#       define SCRIBO__AUTO_FILL_DEBUG_1   "%s", "Eureka"
#       define SCRIBO__AUTO_FILL_METHOD_1  "%s", __func__
#       define SCRIBO__AUTO_FILL_TRACE_1   "\"%s\" : %d", __FILE__, __LINE__
#   endif
#   if defined(_MSC_VER)
#       define __func__ __FUNCTION__
#   endif
    
    // Prepare scribo parameters
#   define SCRIBO(...) SCRIBO__EXPAND_1(SCRIBO__LOOKUP_ARGUMENTS( \
        SCRIBO__INVOKE_2(SCRIBO__PASTE_2, SCRIBO__DEFAULT_VERBOSITY_, SCRIBO__GET_IS_EMPTY(__VA_ARGS__))__VA_ARGS__))
#   define SCRIBO__LOOKUP_ARGUMENTS(...) SCRIBO__EXPAND_1(SCRIBO__INJECT_ARGUMENTS(__VA_ARGS__))
#   define SCRIBO__INJECT_ARGUMENTS(VERBOSITY, ...) SCRIBO__INVOKE_5ETC( \
        SCRIBO__LOOK_UP_CONFIGURATION, \
        SCRIBO__DISABLE_CATEGORY, \
        SCRIBO_DISABLE_VERBOSITY_ ## VERBOSITY, \
        SCRIBO__ENABLE_COMBO_ ## VERBOSITY, \
        SCRIBO_CATEGORY, \
        #VERBOSITY, \
        __VA_ARGS__ SCRIBO__INVOKE_2(SCRIBO__PASTE_2, SCRIBO__AUTO_FILL_ ## VERBOSITY ## _, SCRIBO__GET_IS_EMPTY(__VA_ARGS__)))
#   define SCRIBO__LOOK_UP_CONFIGURATION(DISABLE_CATEGORY, DISABLE_VERBOSITY, ENABLE_COMBO, CATEGORY, VERBOSITY, ...) \
        SCRIBO__CONFIGURE_ ## DISABLE_CATEGORY ## _ ## DISABLE_VERBOSITY ## _ ## ENABLE_COMBO( \
        #CATEGORY, VERBOSITY, __VA_ARGS__)
    
    // Enable or disable scribo
#   define SCRIBO__CONFIGURE_1_0_0(...) // Category disabled, no combo override
#   define SCRIBO__CONFIGURE_0_1_0(...) // Verbosity disabled, no combo override
#   define SCRIBO__CONFIGURE_1_1_0(...) // Category and verbosity disabled, no combo override
#   define SCRIBO__CONFIGURE_0_0_0(CATEGORY, VERBOSITY, ...) SCRIBO__LOG_THIS(CATEGORY, VERBOSITY, __VA_ARGS__)
#   define SCRIBO__CONFIGURE_0_0_1(CATEGORY, VERBOSITY, ...) SCRIBO__LOG_THIS(CATEGORY, VERBOSITY, __VA_ARGS__)
#   define SCRIBO__CONFIGURE_1_0_1(CATEGORY, VERBOSITY, ...) SCRIBO__LOG_THIS(CATEGORY, VERBOSITY, __VA_ARGS__)
#   define SCRIBO__CONFIGURE_0_1_1(CATEGORY, VERBOSITY, ...) SCRIBO__LOG_THIS(CATEGORY, VERBOSITY, __VA_ARGS__)
#   define SCRIBO__CONFIGURE_1_1_1(CATEGORY, VERBOSITY, ...) SCRIBO__LOG_THIS(CATEGORY, VERBOSITY, __VA_ARGS__)
    
    // Prepare scribo prerequisites
#   include <stdio.h>
    
    // Implement scribo message category
#   if SCRIBO_SUPPRESS_CATEGORY != 1
#       define SCRIBO__CATEGORY_FORMAT "%-7.7s "
#   else
#       define SCRIBO__CATEGORY_FORMAT "%.0s"
#   endif
    
    // Implement scribo message verbosity
#   if SCRIBO_SUPPRESS_VERBOSITY != 1
#       define SCRIBO__VERBOSITY_FORMAT "%-7.7s "
#   else
#       define SCRIBO__VERBOSITY_FORMAT "%.0s"
#   endif
    
    // Implement scribo message header/text separator
#   if (SCRIBO_SUPPRESS_CATEGORY != 1) || \
       (SCRIBO_SUPPRESS_VERBOSITY != 1)
#       define SCRIBO__SEPARATOR ": "
#   else
#       define SCRIBO__SEPARATOR
#   endif
    
    // Implement scribo message newline
#   if SCRIBO_SUPPRESS_NEWLINE != 1
#       define SCRIBO__NEWLINE "\n"
#       define SCRIBO__APPEND_NEWLINE 1
#   else
#       define SCRIBO__NEWLINE
#       define SCRIBO__APPEND_NEWLINE 0
#   endif
    
    // Implement scribo message outputting callback and flushing
#   ifdef SCRIBO_INVOKE_CALLBACK
        extern void scribo__ouput_message(
            void (*callback)(const char*),
            size_t size,
            int newline,
            const char* format,
            ...);
#       ifndef SCRIBO_SET_MAX_LENGTH
#           define SCRIBO_SET_MAX_LENGTH 0
#       endif
#       define SCRIBO__DO_OUTPUT(...) scribo__ouput_message( \
            SCRIBO_INVOKE_CALLBACK, \
            SCRIBO_SET_MAX_LENGTH, \
            SCRIBO__APPEND_NEWLINE, \
            __VA_ARGS__);
#       define SCRIBO__DO_FLUSH
#   else
#       define SCRIBO__DO_OUTPUT printf
#       if SCRIBO_SUPPRESS_FLUSH != 1
#           define SCRIBO__DO_FLUSH fflush(stdout)
#       else
#           define SCRIBO__DO_FLUSH
#       endif
#   endif
    
    // Implement scribo logging
#   define SCRIBO__LOG_THIS(CATEGORY, VERBOSITY, ...) \
        SCRIBO__EXPAND_1(SCRIBO__LOG_THIS_WITH_FORMAT(CATEGORY, VERBOSITY, __VA_ARGS__, ""))
#   define SCRIBO__LOG_THIS_WITH_FORMAT(CATEGORY, VERBOSITY, FORMAT, ...) \
        do { \
            SCRIBO__DO_OUTPUT( \
                SCRIBO__CATEGORY_FORMAT SCRIBO__VERBOSITY_FORMAT SCRIBO__SEPARATOR FORMAT "%s" SCRIBO__NEWLINE, \
                        CATEGORY,               VERBOSITY,                         __VA_ARGS__); \
            SCRIBO__DO_FLUSH; \
        } while (0)
    
#endif

// End of file ---------------------------------------------------------------------------------------------------------