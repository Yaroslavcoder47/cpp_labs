#include "task2command.h"

Task2Command::Task2Command(Receiver* r)
{
    receiver_ = r;
}

void Task2Command::execute()
{
    receiver_->task2();
}
