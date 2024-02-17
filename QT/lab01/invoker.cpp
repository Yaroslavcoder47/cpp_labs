#include "invoker.h"


void Invoker::SetCommand(Command* command){
    command_ = command;
}

void Invoker::Run()
{
    command_->execute();
}
