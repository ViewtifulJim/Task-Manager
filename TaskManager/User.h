#pragma once
#include "Observer.h"
#include "TaskNode.h"
#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;

class User
{
private:
	string username;
	string firstName;
	string lastName;
public:
	User(string userName, string firstName, string lastName);
	~User();

	// Getters
	string getUsername() const;
	string getFirstName() const;
	string getLastName() const;

	// Setters
	void setUsername(string username);
	void setFirstName(string firstName);
	void setLastName(string lastName);

};