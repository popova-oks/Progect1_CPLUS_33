#pragma once
#include <list>
#include <vector>
#include <map>
#include "UI.h"
#include "Message.h"

//класс конкретного посредника для работы с пользователями
class Action_Users : public UI
{
    public:
        Action_Users() {}
        virtual ~Action_Users();

        void Create_new_user() override; 
        void Action(char ch) override;

        //функции, которые вызывает конкретный User
        const std::vector<IUser*>& get_autorizate_Users() const override { return autorizate_users_; }
        void print_login_window(IUser* user) override;
        void print_input_msg_window(IUser* user, std::string msg) override;

    private:        
        std::vector <IUser*> all_users_ {};
        std::vector <IUser*> autorizate_users_{};
        std::multimap <IUser*, std::string&> messages_{};
        static int static_counter;          //если нежен ID для пользователя, 
                                            //то можно использовать глобальную переменную static_counter
        Message* msg_ = nullptr;
};


