#pragma once
#include <string>
using std::string;

class View
{
private:

public:

	// Display
	void displayHeader();
	void displayTaskAddHeader();
	void displayTaskListHeader();
	void displayTaskEmptyList();
	void displayUserAddHeader();
	void displayUserListHeader();
	void displayUserEmptyList();
	int displayMainMenu();
	void displaySignature();
	int displayTaskManagementMenu();
	int displayUserManagementMenu();
	void displayInvalidInput();
	void displayToBeImplemented(string msg);
	void displayGoodbye();
	void displayTaskAddedSuccessfully();
	void displayTaskRemovedSuccessfully();
	void displayUserRemovedSuccessfully();
	void displayTaskDoesNotExist();
	void displayUserDoesNotExist();
	void displayUserAddedSuccessfully();
	void displayUserAssignedSuccessfully(const std::string& assignee);
	void displayUserEditedSuccessfully();
	void displayTaskEditedSuccessfully();


	// User input
	bool areYouSure(string type);
	string getTaskName();
	string getTaskDescription();
	string getStartDate();
	string getEndDate();
	string getPriority();
	string getStatus();
	string getAssignee();
	bool assignUsertoTask();
	int getDeleteTaskID();
	int getProgress();
	int getEditTaskID();

	// User input
	string getUsername();
	string getFirstName();
	string getLastName();
	string getDeleteUser();
	string getEditUser();


};
