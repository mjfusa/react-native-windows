#pragma once

#define QUOTEME(M)       #M
#define INCLUDE_FILE(M)  QUOTEME(M##.h)
#define INCLUDE_FILE_X(X) STRINGIFY2(X)    
#define STRINGIFY2(X) #X

#define STR_VALUE(arg)      L###arg
#define CLASS_NAME(name) STR_VALUE(name)

#define PPCAT_NX(A, B) A ## B
#define PPCAT(A, B) PPCAT_NX(A, B)
