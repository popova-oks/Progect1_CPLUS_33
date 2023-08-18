#include <iostream>
#include "Action_Users.h"

int main ()
{    
    setlocale(LC_ALL, "");
    UI* users_interface = new Action_Users();   //создаем эксземпляр класса, который отвечает за действия пользователя
    users_interface->run();
    delete users_interface;

    return 0;
}
