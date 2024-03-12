#include "Controller.h"
#include <Windows.h>
#include <iostream>
#include "Observer.h"
using std::cout;
using std::endl;

Controller::Controller()
{

}

Controller::~Controller()
{
	model.saveToFile();
}

void Controller::run()
{
	model.loadFromFile();
	mainMenu();
}

void Controller::mainMenu()
{
	MainMenuOption option = MainMenuOption::TASK_MANAGEMENT;

	while (option != MainMenuOption::EXIT)
	{
		option = static_cast<MainMenuOption>(view.displayMainMenu());
		switch (option)
		{
		case MainMenuOption::TASK_MANAGEMENT:
			system("cls");
			taskManagementMenu();
			break;
		case MainMenuOption::USER_MANAGEMENT:
			system("cls");
			userManagementMenu();
			break;
		case MainMenuOption::EXIT:
			model.saveToFile();
			view.displayGoodbye();
			exit(0);
			break;
		default:
			view.displayInvalidInput();
			break;
		}
		system("cls");
	}
}

void Controller::taskManagementMenu()
{
	TaskManagementOption option = TaskManagementOption::ADD_TASK;

	while (option != TaskManagementOption::EXIT)
	{
		option = static_cast<TaskManagementOption>(view.displayTaskManagementMenu());
		switch (option)
		{
		case TaskManagementOption::ADD_TASK:
			system("cls");
			addTask();
			break;
		case TaskManagementOption::EDIT_TASK:
			system("cls");
			editTask();
			break;
		case TaskManagementOption::DELETE_TASK:
			system("cls");
			deleteTask();
			break;
		case TaskManagementOption::LIST_TASKS:
			system("cls");
			listTasks();
			system("pause");
			break;
		case TaskManagementOption::BACK:
			system("cls");
			mainMenu();
			break;
		case TaskManagementOption::EXIT:
			model.saveToFile();
			view.displayGoodbye();
			exit(0);
			break;
		default:
			view.displayInvalidInput();
			break;
		}
		system("cls");
	}
}

void Controller::userManagementMenu()
{
	UserManagementOption option = UserManagementOption::ADD_USER;

	while (option != UserManagementOption::EXIT)
	{
		option = static_cast<UserManagementOption>(view.displayUserManagementMenu());
		switch (option)
		{
		case UserManagementOption::ADD_USER:
			system("cls");
			addUser();
			break;
		case UserManagementOption::EDIT_USER:
			system("cls");
			editUser();
			break;
		case UserManagementOption::DELETE_USER:
			system("cls");
			deleteUser();
			break;
		case UserManagementOption::LIST_USERS:
			system("cls");
			listUsers();
			system("pause");
			break;
		case UserManagementOption::BACK:
			system("cls");
			mainMenu();
			break;
		case UserManagementOption::EXIT:
			model.saveToFile();
			view.displayGoodbye();
			exit(0);
			break;
		default:
			view.displayInvalidInput();
			break;
		}
		system("cls");
	}
}

void Controller::addTask()
{
	bool sure = view.areYouSure("add a task");
	if (!sure)
	{
		return;
	}
	else
	{
		view.displayTaskAddHeader();
		string taskName = view.getTaskName();
		string taskDescription = view.getTaskDescription();
		string startDate = view.getStartDate();
		string endDate = view.getEndDate();
		string priority = view.getPriority();
		string status = view.getStatus();
		model.listUserFirstNames();
		string assignee = view.getAssignee();
		model.addTask(taskName, taskDescription, startDate, endDate, priority, status, assignee);
		view.displayTaskAddedSuccessfully();
		Sleep(2000);
		
	}
}

void Controller::editTask()
{
	bool sure = view.areYouSure("edit a task");
	if (!sure)
	{
		return;
	}
	else
	{
		listTasks();
		int taskID = view.getEditTaskID();
		if (!model.taskExists(taskID))
		{
			view.displayTaskDoesNotExist();
			return;
		}
		else
		{
			string taskName = view.getTaskName();
			string taskDescription = view.getTaskDescription();
			string startDate = view.getStartDate();
			string endDate = view.getEndDate();
			string priority = view.getPriority();
			string status = view.getStatus();
			model.listUserFirstNames();
			string assignee = view.getAssignee();
			model.editTask(taskID, taskName, taskDescription, startDate, endDate, priority, status, assignee);
			view.displayTaskEditedSuccessfully();
			Sleep(2000);
		}
	}
}

void Controller::deleteTask()
{
	bool sure = view.areYouSure("delete a task");
	if (!sure)
	{
		return;
	}
	else
	{
		listTasks();
		int taskID = view.getDeleteTaskID();
		if (!model.taskExists(taskID))
		{
			view.displayTaskDoesNotExist();
			return;
		}
		else
		{ 
			model.removeTask(taskID);
			view.displayTaskRemovedSuccessfully();
			Sleep(2000);
		}
		
	}
}

void Controller::listTasks()
{
	view.displayTaskListHeader();

	if (model.taskListIsEmpty())
	{
		view.displayTaskEmptyList();
	}
	else
	{
		model.listTasks();
	}
}

void Controller::addUser()
{
	bool sure = view.areYouSure("add a user");

	if (!sure)
	{
		return;
	}
	else
	{
		view.displayUserAddHeader();
		string username = view.getUsername();
		string firstName = view.getFirstName();
		string lastName = view.getLastName();
		model.addUser(username, firstName, lastName);
		view.displayUserAddedSuccessfully();
		Sleep(2000);
	}
	
}

void Controller::listUsers()
{
	view.displayUserListHeader();

	if (model.userListIsEmpty())
	{
		view.displayUserEmptyList();
	}
	else
	{
		model.listUsers();
	}
	
}

void Controller::editUser()
{
	bool sure = view.areYouSure("edit a user");
	if (!sure)
	{
		return;
	}
	else
	{
		listUsers();
		string username = view.getEditUser();
		if (!model.userExists(username))
		{
			view.displayUserDoesNotExist();
			return;
		}
		else
		{
			string firstName = view.getFirstName();
			string lastName = view.getLastName();
			model.editUser(username, firstName, lastName);
			view.displayUserEditedSuccessfully();
			Sleep(2000);
		}
	}
	
}

void Controller::deleteUser()
{
	bool sure = view.areYouSure("delete a user");
	if (!sure)
	{
		return;
	}
	else
	{
		listUsers();
		string username = view.getDeleteUser();
		if (!model.userExists(username))
		{
			view.displayUserDoesNotExist();
			return;
		}
		else
		{
			model.removeUser(username);
			view.displayUserRemovedSuccessfully();
			Sleep(2000);
		}
	}
}




