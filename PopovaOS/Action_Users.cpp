#include "Action_Users.h"
#include "UI.h"
#include "User.h"
#include "Message.h"
#include <string>
#include <vector>

Action_Users::~Action_Users() 
{
    std::cout << "\nDestructor Action Users";

}

void Action_Users::Create_new_user()
{    
    std::cout << "\nThe function Action_Users::Create_new_user" << std::endl;

    User_data user_data_{};                             //создаем структуру для передачи в конструктор класса User
    std::cout << "\nEnter name: ";
	std::cin >> user_data_.name_;    
	std::cout << "Enter login: ";
	std::cin >> user_data_.login_;
	std::cout << "Enter password: ";
	std::cin >> user_data_.password_;	
	user_data_.ID_ = ++static_counter;
    //сохраняем конкретного пользователя в списке пользователей и передаем данные в конструктор User
    all_users_.emplace_back(new User(&user_data_, this));
    std::cout << "You are registrated!" << std::endl;
}

void Action_Users::Action(char ch)
{
    std::cout << "\nThe function Action_Users::Action, ch: " << ch << std::endl;

    std::string login;
    std::cout << "\nEnter login: ";
	std::cin >> login;

    std::string password;
	std::cout << "Enter password: ";
	std::cin >> password;

    for (auto i : all_users_)
    {
        if (i->get_login() == login && i->get_password() == password)
        {
            //сохраняем конкретного пользователя в списке авторизованных пользователей
            //проходят авторизацию только пользователи, которые хотят авторизоваться или отправить сообщение
            if (ch == '2' || ch == '3')
            {
                autorizate_users_.emplace_back(i);
                std::cout << "You are autorisated!" << std::endl;
            }
            i->action_from_UI (this, ch);            
            return;
        }        
    }
    std::cout << "This user is not registered!" << std::endl;
}

void Action_Users::print_login_window(IUser* user)
{
    std::cout << "User ID - " << user->get_ID() << ", login - " << user->get_login() << std::endl;
}

void Action_Users::print_input_msg_window(IUser* user, std::string msg)
{
    std::cout << "\nMessage: " << msg << std::endl;
    std::cout << "User ID - " << user->get_ID() << ", name - " << user->get_name() << std::endl;
    Message* message = new Message(user, msg);             //создаем новый объект класса Message
    messages_.insert({user, msg});                         //сохраняем сообщение в классе Message c указателем на отправителя
}

int Action_Users::static_counter = 0;                     //глобальная переменная для генерации ID user