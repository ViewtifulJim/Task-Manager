#pragma once
#include "User.h"

// Observer interface

class User;

class Observer
{
public:
	virtual void update() = 0;
};
