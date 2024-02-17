#include <QCoreApplication>
#include <iostream>
#include <QTextStream>
#include <string>
#include <QTextCodec>
#include <QStringList>
#include "command.h"
#include "receiver.h"
#include "invoker.h"
#include "task1command.h"


int main()
{
    Invoker* invoker = new Invoker();
    Receiver* receiver = new Receiver();
    Task1Command* task1 = new Task1Command(receiver);
    invoker->SetCommand(task1);
    invoker->Run();
    return 0;
}
