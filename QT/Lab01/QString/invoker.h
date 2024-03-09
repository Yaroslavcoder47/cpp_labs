#ifndef INVOKER_H
#define INVOKER_H
#include "command.h"

class Invoker
{
public:
    Invoker() = default;
    void SetCommand(Command* command);
    void Run();
private:
    Command* command_;
};

#endif // INVOKER_H
