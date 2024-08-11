/*Выведите на экран строку “What’s your name”. После того, как пользователь введет
свое имя (например, Sasha), выведите: «Nice to meet you, Sasha”*/
#include <iostream>
#include <string>

int main()
{
    std::cout << "What is your name? ";
    std::string name;
    std::cin >> name;
    std::cout << "Nice to meet you, " << name << '\n';
    return 0;
}