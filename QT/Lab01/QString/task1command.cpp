#include "task1command.h"

Task1Command::Task1Command(Receiver* r)
{
    receiver_ = r;
}

void Task1Command::execute()
{
    receiver_->task1();
}
