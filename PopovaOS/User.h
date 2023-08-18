#pragma once
#include "IUser.h"
#include "UI.h"
#include <iostream>
#include <string>

class User : public IUser
{
public:
    virtual ~User() {}

    //конструктор класса User 
    User(User_data* user_data, UI* ui): IUser(ui)                  
    {
        std::cout << "The constructor of User" << std::endl;

        name_ = user_data->name_;
        login_ = user_data->login_;
        password_ = user_data->password_;
        ID_ = user_data->ID_;
    }

    const std::string& get_name() const override {return name_;};
    const std::string& get_login() const override {return login_;};
    const std::string& get_password() const override {return password_;};
    const int get_ID() const override {return ID_;};

    //получение указателя на конкретного посредника (Action_users) и код содытия, который выбрал пользователь в функции run
    void action_from_UI(UI* ui, char event) override
    {
        std::cout << "User action_from_UI, event = " << event << std::endl;
        if (event == '2')                       //авторизация пользователя
        {
            //...что-то сделать...
            //вывести логин на экран
            this->ui_->print_login_window(this);
        }
        else if (event == '3')                 //отправить сообщение
        {
            //Чтобы отправить сообщение
            //выбрать пользователя User* some_user;
            //проверить, что пользователь уже авторизован
            //bool flag = false;
            /*
            for (auto user : this->ui_->get_autorizate_Users())
            {
                if ((some_user->get_login()) == login)
                {
                    std::cout << "\nThis user is autorizated!";
                    flag = true;
                }
            }
            if (!flag)
            {
                std::cout << "\nThis user isn't autorizated!";
                return;
            }
            */

            std::string msg;
            std::cout << "\nEnter your message: ";
            std::cin >> msg;

            //вывести сообщение на экран
            this->ui_->print_input_msg_window (this, msg); //через эту функцию передается сообщение в класс Action Users
                                                           //создается новый объект - вызывается конструктор класса Message
        }
        else if (event == '4')                    //выйти из чата
        {
            //проверяем является ли пользователь авторизованным
            bool flag = false;
            std::vector <IUser*> vec = ui_->get_autorizate_Users();
            std::vector <IUser*>::iterator it = vec.begin();
            for (it; it != vec.end(); ++it)
            {
                if ((this->login_ == dynamic_cast<User*> (*it)->get_login()) 
                    && (this->password_ == dynamic_cast<User*> (*it)->get_password()))
                {
                    std::cout << "\nYou are leaved the chat!\n";
                    vec.erase(it);
                    return;
                }
            }
            if (!flag)
            {
                std::cout << "\nThis user isn't autorizated!";
            }
        }
        else
        {
            std::cout << "Try agan!" << std::endl;
        }
    };

private:
    std::string name_;
    std::string login_;
    std::string password_;
    int ID_;   
};