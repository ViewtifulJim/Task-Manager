#pragma once
#include <vector>
#include <fstream>
#include "User.h"
#include "TaskNode.h"

class UserStorage : public Subject
{
private:
	std::vector<Observer*> observers;
	std::vector<User> users;
	std::string filename;
	TaskNode taskNode;
public:
	UserStorage(const std::string& filename);
	UserStorage();
	~UserStorage();

	void loadUsers();
	void saveUsers();
	void addUser(string username, string firstName, string lastName);
	void editUser(string username, string firstName, string lastName);
	void listUsers();
	void listUserFirstNames();
	bool userListIsEmpty();
	bool userExists(string username);
	void removeUser(string username);

	void addObserver(Observer* observer) override;
	void removeObserver(Observer* observer) override;
	void notifyObservers() override;
};
