#ifndef TASK1COMMAND_H
#define TASK1COMMAND_H
#include "command.h"
#include "receiver.h"

class Task1Command : public Command
{
public:
    Task1Command(Receiver* r);
    void execute() override;
private:
    Receiver* receiver_;
};

#endif // TASK1COMMAND_H
