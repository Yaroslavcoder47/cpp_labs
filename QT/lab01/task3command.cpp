#include "task3command.h"

Task3Command::Task3Command(Receiver* r)
{
    receiver_ = r;
}

void Task3Command::execute()
{
    receiver_->task3();
}
