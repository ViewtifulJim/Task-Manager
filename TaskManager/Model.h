#pragma once
#include "LinkedList.h"
#include "TaskFileDecorator.h"
#include "UserStorage.h"
#include "User.h"

#include <map>
using std::map;

#include <string>
using std::string;

#include <vector>
using std::vector;

class Model
{
private:
	LinkedList taskLinkedList;
	TaskFileDecorator* taskFileDecorator;
	UserStorage userStorage;
	map<string, string> taskAssignments;
public:
	
	Model();
	~Model();

	// TaskNode methods
	void addTask(string taskName, string description, string startDate, string endDate, string priority, string status, string assignee);
	void editTask(int taskID, string taskName, string description, string startDate, string endDate, string priority, string status, string assignee);
	void listTasks();
	bool taskListIsEmpty();
	bool taskExists(int taskID);
	void removeTask(int taskID);

	// File methods for tasks and users
	void saveToFile();
	void loadFromFile();


	// User methods - move to UserStorage
	void addUser(string username, string firstName, string lastName);
	void listUsers();
	void listUserFirstNames();
	bool userListIsEmpty();
	bool userExists(string username);
	void removeUser(string username);
	void editUser(string username, string firstName, string lastName);

};
