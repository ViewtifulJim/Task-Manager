#pragma once
#include "Observer.h"
#include "User.h"

class UserObserver : public Observer
{
private:
	User user;
public:
	UserObserver(const User& user);

	void update() override;
};