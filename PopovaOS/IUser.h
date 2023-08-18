#pragma once
#include <string>
//#include "UI.h"

class UI;

//абстрактный класс пользователя, который связывает отдельного пользователя и посредника
//в данном случае - это Action_Users
class IUser 
{
    public:
        virtual ~IUser() {};
        IUser(UI* ui);
        
        //void set_ui(UI* ui) { ui_ = ui; }

        virtual const std::string& get_name() const = 0;
        virtual const std::string& get_login() const = 0;
        virtual const std::string& get_password() const = 0;
        virtual const int get_ID() const = 0;

        virtual void action_from_UI(UI* ui, char event) = 0;
    protected:
         UI* ui_ ;      //указатель на посредника для данного пользователя (Action Users)
                        //через абстрактный класс UI можем взаимодействовать с посредником
};
