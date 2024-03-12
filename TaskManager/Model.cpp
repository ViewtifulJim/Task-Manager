#include "Model.h"
#include <stdexcept>

Model::Model()
{
	taskFileDecorator = new TaskFileDecorator(&taskLinkedList);
	UserStorage userStorage("users.txt");
}

Model::~Model()
{
	delete taskFileDecorator;
}

void Model::addTask(std::string taskName, std::string description, std::string startDate, std::string endDate, string priority, std::string status, std::string assignee)
{
	taskLinkedList.addTask(taskName, description, priority, startDate, endDate, status, assignee);
}

void Model::editTask(int taskID, std::string taskName, std::string description, std::string startDate, std::string endDate, string priority, std::string status, std::string assignee)
{
	taskLinkedList.editTask(taskID, taskName, description, priority, startDate, endDate, status, assignee);
}

void Model::addUser (string username, string firstName, string lastName)
{
	userStorage.addUser(username, firstName, lastName);
}

void Model::listTasks()
{
	taskLinkedList.printTaskList();
}

void Model::listUsers()
{
	userStorage.listUsers();
}

void Model::listUserFirstNames()
{
	userStorage.listUserFirstNames();
}

bool Model::taskListIsEmpty()
{
	bool emptyCheck = taskLinkedList.isEmpty();
	return emptyCheck;
}

bool Model::userListIsEmpty()
{
	return userStorage.userListIsEmpty();
}

bool Model::taskExists(int taskID)
{
	if (taskLinkedList.taskExists(taskID))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Model::userExists(string username)
{
	return userStorage.userExists(username);
}

void Model::removeUser(string username)
{
	userStorage.removeUser(username);
}

void Model::editUser(string username, string firstName, string lastName)
{
	userStorage.editUser(username, firstName, lastName);
}

void Model::removeTask(int taskID)
{
	taskLinkedList.removeTask(taskID);
}


void Model::saveToFile()
{
	taskFileDecorator->writeToFile("tasks.txt");
	userStorage.saveUsers();
}

void Model::loadFromFile()
{
	taskFileDecorator->readFromFile("tasks.txt");
	userStorage.loadUsers();
}



