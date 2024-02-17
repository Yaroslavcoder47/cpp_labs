#ifndef TASK3COMMAND_H
#define TASK3COMMAND_H
#include "command.h"
#include "receiver.h"

class Task3Command : public Command
{
public:
    Task3Command(Receiver* r);
    void execute() override;
private:
    Receiver* receiver_;
};

#endif // TASK3COMMAND_H
