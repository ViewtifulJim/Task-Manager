#include "User.h"

User::User(string username, string firstName, string lastName)
{
	this->username = username;
	this->firstName = firstName;
	this->lastName = lastName;
}

User::~User()
{


}

string User::getUsername() const
{
	return username;
}

string User::getFirstName() const
{
	return firstName;
}

string User::getLastName() const
{
	return lastName;
}

void User::setUsername(string username)
{
	this->username = username;
}

void User::setFirstName(string firstName)
{
	this->firstName = firstName;
}

void User::setLastName(string lastName)
{
	this->lastName = lastName;
}