#ifndef IOEXCEPTION_H
#define IOEXCEPTION_H

#include "exception.h"

enum IOExceptionId
{
    FILE_DOES_NOT_EXIST = 0,
    FEX_ERROR
};

class IOException : Exception
{
public:
    IOException();
};

#endif // IOEXCEPTION_H
