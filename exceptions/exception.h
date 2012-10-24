#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <QString>

class Exception
{
private:
    QString *message;
    int type;

public:
    Exception();
    Exception(QString message);
    Exception(int code);
    Exception(QString message, int type);

    QString getMessage();
    int getType();
};

#endif // EXCEPTION_H
