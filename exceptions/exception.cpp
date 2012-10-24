#include "exception.h"

Exception::Exception() : message(NULL), type(0)
{
}

Exception::Exception(QString message) : type(0)
{
    this->message = new QString(message);
}

Exception::Exception(int code) : message(NULL)
{
    Exception::Exception("", code);
}

Exception::Exception(QString message, int type)
{
    this->message = new QString(message);
    this->type = type;
}
