#pragma once
#include "View.h"
#include "Model.h"
#include "LinkedList.h"
#include "TaskFileDecorator.h"

enum class MainMenuOption
{
	TASK_MANAGEMENT = 1,
	USER_MANAGEMENT,
	EXIT = 0
};

enum class UserManagementOption
{
	ADD_USER = 1,
	EDIT_USER,
	DELETE_USER,
	LIST_USERS,
	BACK,
	EXIT = 0
};

enum class TaskManagementOption
{
	ADD_TASK = 1,
	EDIT_TASK,
	DELETE_TASK,
	LIST_TASKS,
	BACK,
	EXIT = 0
};

class Controller
{
private:
	View view;
	Model model;

public:
	Controller();
	~Controller();
	void run();

	// Menu functions
	void mainMenu();
	void taskManagementMenu();
	void userManagementMenu();

	// Task management functions
	void addTask();
	void editTask();
	void deleteTask();
	void listTasks();

	// User management functions
	void addUser();
	void deleteUser();
	void listUsers();
	void editUser();
};