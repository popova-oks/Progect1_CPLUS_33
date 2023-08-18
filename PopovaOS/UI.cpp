#include "UI.h"
#include <iostream>

void UI::run()
{
    bool flag = true;

    while (flag)
    {
        std::cout << "\nSelect an action:" << std::endl;
        std::cout << "1 - registration, 2 - autorizate, 3 - send messages," << std::endl;
        std::cout << "4 - leave the chat, 5 - exit the programm: " << std::endl;
        char ch;
        std::cin >> ch;

        switch (ch)
        {
        case '1':
        {
            Create_new_user();
            break;
        }
        case '2': case '3': case '4':
        {
            Action(ch);
            break;
        }
        case '5':
        {
            flag = false;
            break;
        }
        default:
        {
            std::cout << "\nTry agan!" << std::endl;
            break;
        }
        }
        //сбросить все символы из потока
        std::cin.clear();
        std::cin.ignore(32767, '\n');
    }
    std::cout << "\nSee you soon! " << std::endl;
}