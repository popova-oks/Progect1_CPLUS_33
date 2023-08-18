#pragma once
#include <string>
#include "IUser.h"

class Message
{
public:
	Message(IUser* user, std::string msg) : user_(user), msg_(msg) {};
	void set_msg(std::string msg) { msg_ = msg; }




private:
	std::string msg_;
	IUser* user_;
};
