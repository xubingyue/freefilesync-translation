// *****************************************************************************
// * This file is part of the FreeFileSync project. It is distributed under    *
// * GNU General Public License: http://www.gnu.org/licenses/gpl-3.0           *
// * Copyright (C) Zenju (zenju AT freefilesync DOT org) - All Rights Reserved *
// *****************************************************************************

#ifndef BUILD_INFO_H_5928539285603428657
#define BUILD_INFO_H_5928539285603428657

namespace zen
{
//determine build info: defines ZEN_BUILD_32BIT or ZEN_BUILD_64BIT

#ifdef ZEN_WIN
    #ifdef _WIN64 //_WIN32 is defined by the compiler for both 32 and 64 bit builds, unlike _WIN64
        #define ZEN_BUILD_64BIT
    #else
        #define ZEN_BUILD_32BIT
    #endif

#else
    #ifdef __LP64__
        #define ZEN_BUILD_64BIT
    #else
        #define ZEN_BUILD_32BIT
    #endif
#endif

#ifdef ZEN_BUILD_32BIT
    static_assert(sizeof(void*) == 4, "");
#endif

#ifdef ZEN_BUILD_64BIT
    static_assert(sizeof(void*) == 8, "");
#endif
}

#endif //BUILD_INFO_H_5928539285603428657
