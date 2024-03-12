#include "View.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
#include <regex>

// Define color escape codes
const string ansi_color_green = "\x1b[32m";
const string ansi_color_red = "\x1b[31m";
const string ansi_color_yellow = "\x1b[33m";
const string ansi_color_cyan = "\x1b[36m";
const string ansi_color_orange = "\x1b[38;5;208m";
const string ansi_color_reset = "\x1b[0m";

int View::displayMainMenu()
{
	int choice;
	displayHeader();
	cout << "------------------ " << ansi_color_yellow << "*Task Management System*" << ansi_color_reset << " ------------------\n" << endl;
	cout << ansi_color_yellow << "  (1)" << ansi_color_reset << " Task Management\n";
	cout << ansi_color_yellow << "  (2)" << ansi_color_reset << " User Management\n";
	cout << ansi_color_red << "  (0)" << ansi_color_reset << " Exit\n";
	cout << "\n--------------------------------------------------------------\n\n" << endl;

	while (true) 
	{
		cout << "Enter your choice: ";
		if (cin >> choice) 
		{
			break;
		}
		else 
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ansi_color_red << "Invalid input. Please enter a number.\n" << ansi_color_reset << endl;
		}
	}

	return choice;
}

int View::displayTaskManagementMenu()
{
	int choice;
	displayHeader();
	cout << "--------------------- " << ansi_color_cyan << "*Task Management*" << ansi_color_reset << " ----------------------\n" << endl;
	cout << ansi_color_cyan << "  (1)" << ansi_color_reset << " Add Task\n";
	cout << ansi_color_cyan << "  (2)" << ansi_color_reset << " Edit Task\n";
	cout << ansi_color_cyan << "  (3)" << ansi_color_reset << " Delete Task\n";
	cout << ansi_color_cyan << "  (4)" << ansi_color_reset << " List Tasks\n";
	cout << ansi_color_orange << "  (5)" << ansi_color_reset << " Back\n";
	cout << ansi_color_red << "  (0)" << ansi_color_reset << " Exit\n";
	cout << "\n--------------------------------------------------------------\n\n" << endl;
	
	while (true)
	{
		cout << "Enter your choice: ";
		if (cin >> choice)
		{
			break;
		}
		else
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ansi_color_red << "Invalid input. Please enter a number.\n" << ansi_color_reset << endl;
		}
	}

	return choice;
}

int View::displayUserManagementMenu()
{
	int choice;
	displayHeader();
	cout << "--------------------- " << ansi_color_green << "*User Management*" << ansi_color_reset << " ----------------------\n" << endl;
	cout << ansi_color_green << "  (1)" << ansi_color_reset << " Add User\n";
	cout << ansi_color_green << "  (2)" << ansi_color_reset << " Edit User\n";
	cout << ansi_color_green << "  (3)" << ansi_color_reset << " Delete User\n";
	cout << ansi_color_green << "  (4)" << ansi_color_reset << " List Users\n";
	cout << ansi_color_orange << "  (5)" << ansi_color_reset << " Back\n";
	cout << ansi_color_red << "  (0)" << ansi_color_reset << " Exit\n";
	cout << "\n--------------------------------------------------------------\n\n" << endl;
	
	while (true)
	{
		cout << "Enter your choice: ";
		if (cin >> choice)
		{
			break;
		}
		else
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ansi_color_red << "Invalid input. Please enter a number.\n" << ansi_color_reset << endl;
		}
	}

	return choice;
}

void View::displayHeader()
{
	cout << "------------------ " << "*NewGen Software Design*" << " ------------------" << endl;
}

void View::displayTaskAddHeader()
{
	cout << "------------------ " << ansi_color_yellow << "*Add Task*" << ansi_color_reset << " ------------------\n" << endl;
}

void View::displayTaskListHeader()
{
	cout << "------------------ " << ansi_color_cyan << "*Task List*" << ansi_color_reset << " ------------------\n" << endl;
}

void View::displaySignature()
{
	cout << "Created by: James Williams - 14048787" << endl;

}

void View::displayInvalidInput()
{
	cout << ansi_color_red << "Invalid choice, please try again." << ansi_color_reset << endl;
}

void View::displayToBeImplemented(string msg)
{
	cout << ansi_color_red << "This feature is yet to be implemented: " << msg << ansi_color_reset << endl;
}

void View::displayGoodbye()
{
	cout << ansi_color_green << "Goodbye!" << ansi_color_reset << endl;
}

void View::displayTaskAddedSuccessfully()
{
	cout << ansi_color_green << "Task added successfully!" << ansi_color_reset << endl;
}

void View::displayTaskRemovedSuccessfully()
{
	cout << ansi_color_green << "Task removed successfully!" << ansi_color_reset << endl;
}

void View::displayTaskEmptyList()
{
	cout << ansi_color_red << "The task list is empty.\n" << ansi_color_reset << endl;
}

void View::displayTaskDoesNotExist()
{
	cout << ansi_color_red << "The task does not exist.\n" << ansi_color_reset << endl;
}

void View::displayUserAddHeader()
{
	cout << "------------------ " << ansi_color_green << "*Add User*" << ansi_color_reset << " ------------------\n" << endl;
}

void View::displayUserAddedSuccessfully()
{
	cout << ansi_color_green << "User added successfully!" << ansi_color_reset << endl;
}

void View::displayUserListHeader()
{
	cout << "------------------ " << ansi_color_green << "*User List*" << ansi_color_reset << " ------------------\n" << endl;
}

void View::displayUserEmptyList()
{
	cout << ansi_color_red << "The user list is empty.\n" << ansi_color_reset << endl;
}

void View::displayUserRemovedSuccessfully()
{
	cout << ansi_color_green << "User removed successfully!" << ansi_color_reset << endl;
}

void View::displayUserDoesNotExist()
{
	cout << ansi_color_red << "The user does not exist.\n" << ansi_color_reset << endl;
}

void View::displayUserAssignedSuccessfully(const std::string& assignee)
{
	cout << ansi_color_green << "User " << assignee << " assigned successfully!" << ansi_color_reset << endl;
}

void View::displayUserEditedSuccessfully()
{
	cout << ansi_color_green << "User edited successfully!" << ansi_color_reset << endl;
}

void View::displayTaskEditedSuccessfully()
{
	cout << ansi_color_green << "Task edited successfully!" << ansi_color_reset << endl;
}

string View::getTaskName() 
{
	string taskName;
	cout << "Enter the task name: ";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, taskName);
	return taskName;
}

string View::getTaskDescription() 
{
	string taskDescription;
	cout << "Enter the task description: ";
	getline(cin, taskDescription);
	return taskDescription;
}

string View::getStartDate()
{
	string startDate;
	cout << "Enter the start date (DD/MM/YYYY): ";
	cin >> startDate;

	std::regex datePattern("([0-2][0-9]|3[0-1])/(0[1-9]|1[0-2])/[0-9]{4}");

	if (!std::regex_match(startDate, datePattern))
	{
		cout << ansi_color_red << "Invalid date format. Please enter the date in the format DD/MM/YYYY." << ansi_color_reset << endl;
		return getStartDate();
	}

	return startDate;
}

string View::getEndDate()
{
	string endDate;
	cout << "Enter the end date (DD/MM/YYYY): ";
	cin >> endDate;
	std::regex datePattern("([0-2][0-9]|3[0-1])/(0[1-9]|1[0-2])/[0-9]{4}");

	if (!std::regex_match(endDate, datePattern))
	{
		cout << ansi_color_red << "Invalid date format. Please enter the date in the format DD/MM/YYYY." << ansi_color_reset << endl;
		return getEndDate();
	}

	return endDate;
}

string View::getPriority() {
	int priority;
	cout << "\nPlease select the priority of the task: " << endl;
	cout << "1." << ansi_color_green << " Low" << ansi_color_reset << endl;
	cout << "2." << ansi_color_yellow << " Medium" << ansi_color_reset << endl;
	cout << "3." << ansi_color_red << " High" << ansi_color_reset << endl;

	// Keep asking for input until a valid option is chosen
	while (true) 
	{
		cout << "Enter your choice: ";
		if (!(cin >> priority)) 
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ansi_color_red << "Invalid input. Please enter a number." << ansi_color_reset << endl;
			continue;
		}
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

		if (priority == 1) 
		{
			return "Low";
		}
		else if (priority == 2) 
		{
			return "Medium";
		}
		else if (priority == 3) 
		{
			return "High";
		}
		else 
		{
			cout << ansi_color_red << "Invalid input. Please enter a valid option." << ansi_color_reset << endl;
		}
	}
}


string View::getStatus() {
	int status;
	cout << "\nPlease select the status of the task: " << endl;
	cout << "1." << ansi_color_cyan << " To Do" << ansi_color_reset << endl;
	cout << "2." << ansi_color_yellow << " In Progress" << ansi_color_reset << endl;
	cout << "3." << ansi_color_green << " Done" << ansi_color_reset << endl;

	// Keep asking for input until a valid option is chosen
	while (true) 
	{
		cout << "Enter your choice: ";
		if (!(cin >> status)) 
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ansi_color_red << "Invalid input. Please enter a number." << ansi_color_reset << endl;
			continue;
		}
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

		if (status == 1) 
		{
			return "To Do";
		}
		else if (status == 2) 
		{
			return "In Progress";
		}
		else if (status == 3) 
		{
			return "Done";
		}
		else 
		{
			cout << ansi_color_red << "Invalid input. Please enter a valid option." << ansi_color_reset << endl;
		}
	}
}

string View::getAssignee()
{
	string assignee;
	cout << "\nEnter the name of the user(s) you would like to assign to this task: ";
	getline(cin, assignee);
	return assignee;
}

int View::getDeleteTaskID() 
{
	int taskID;
	while (true) 
	{
		std::cout << "Enter the ID of the task you would like to delete: ";
		std::cin >> taskID;
		if (std::cin.fail() || taskID <= 0) 
		{
			std::cin.clear(); 
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
			std::cout << "Invalid input. Please enter a positive number.\n";
		}
		else 
		{
			return taskID;
		}
	}
}

string View::getDeleteUser()
{
	string firstName;
	while (true)
	{
		std::cout << "Enter the username of the user you would like to delete: ";
		std::cin >> firstName;
		if (std::cin.fail() || firstName.empty())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
			std::cout << "Invalid input. Please enter a valid username.\n";
		}
		else
		{
			return firstName;
		}
	}
}

int View::getProgress()
{
	int progress;
	while (true)
	{
		std::cout << "Enter the progress of the task (0-100): ";
		std::cin >> progress;
		if (std::cin.fail() || progress < 0 || progress > 100)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
			std::cout << "Invalid input. Please enter a number between 0 and 100.\n";
		}
		else
		{
			return progress;
		}
	}
}

int View::getEditTaskID()
{
	int taskID;
	while (true)
	{
		std::cout << "Enter the ID of the task you would like to edit: ";
		std::cin >> taskID;
		if (std::cin.fail() || taskID <= 0)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please enter a positive number.\n";
		}
		else
		{
			return taskID;
		}
	}
}

bool View::areYouSure(string type)
{
	char choice;
	cout << "Are you sure you want to " << type << "? (y/n): ";
	cin >> choice;
	if (choice == 'y' || choice == 'Y')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool View::assignUsertoTask()
{
	char choice;
	cout << "Would you like to assign a user to this task? (y/n): ";
	cin >> choice;
	if (choice == 'y' || choice == 'Y')
	{
		return true;
	}
	else
	{
		return false;
	}
}

string View::getUsername()
{
	string username;
	cout << "Enter username: ";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, username);
	return username;
}

string View::getFirstName()
{
	string username;
	cout << "Enter first name: ";
	getline(cin, username);
	return username;
}

string View::getLastName()
{
	string lastName;
	cout << "Enter last name: ";
	getline(cin, lastName);
	return lastName;
}

string View::getEditUser()
{
	string username;
	cout << "Enter the username of the user you would like to edit: ";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, username);
	return username;
}