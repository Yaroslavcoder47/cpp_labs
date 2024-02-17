#ifndef TASK2COMMAND_H
#define TASK2COMMAND_H
#include "command.h"
#include "receiver.h"

class Task2Command : public Command
{
public:
    Task2Command(Receiver* r);
    void execute() override;

private:
    Receiver* receiver_;
};

#endif // TASK2COMMAND_H
