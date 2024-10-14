#pragma once

#include <stdio.h>

/// @brief A calssic (or not) String comparer
/// @param A String A
/// @param B String B
/// @param StopAt Optional argument. It will stop checking at possition when it will hit this digit. Just put -1 or smaller than zero digit and it will be ignored. 
/// @return 1 - if the string is equal in range. 0 - if not. 
int strcomp(const char * A, const char *  B, int StopAt);
