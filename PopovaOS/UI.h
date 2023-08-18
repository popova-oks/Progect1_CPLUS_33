#pragma once
#include "IUser.h"
#include <iostream>
#include <vector>

//абстрактный класс посредника, который связан с абстрактным классом пользователя
class UI
{
    public:
        virtual ~UI() {}
        void run ();

        //функции, которые вызывает конкретный User
        virtual const std::vector<IUser*>& get_autorizate_Users() const = 0;
        virtual void print_login_window(IUser* user) = 0;
        virtual void print_input_msg_window(IUser* user, std::string msg) = 0;
        
    private:        
        virtual void Create_new_user() = 0;               //вызываем функцию в конкретном посреднике (User_Action)            
        virtual void Action(const char ch) = 0;           //вызываем функцию в конкретном посреднике (User_Action)
};

//структура для сохранения данных о новом пользователе и передачи их в конструктор класса User
struct User_data
{
    std::string name_;
    std::string login_;
    std::string password_;
    int ID_ = 0;
};
