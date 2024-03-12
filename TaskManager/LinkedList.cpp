#include "LinkedList.h"
#include "TaskNode.h"
#include <iostream>
using std::cout;
using std::endl;

// Constructor
// This function should initialize the head and tail pointers to nullptr and the size to 0
LinkedList::LinkedList()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

// Destructor
// This function should delete all of the TaskNodes in the list
LinkedList::~LinkedList()
{
	TaskNode* current = head;
	while (current != nullptr)
	{
		TaskNode* next = current->next;
		delete current;
		current = next;
	}
}

// Add a task to the end of the list
// This function should create a new TaskNode and add it to the end of the list
// Parameters: taskName - the name of the task, description - the description of the task, priority - the priority of the task, status - the status of the task
void LinkedList::addTask(string taskName, string description, string startDate, string endDate, string priority, string status, string assignee)
{
	TaskNode* newTask = new TaskNode(taskName, description, startDate, endDate, priority, status, assignee);
	if (head == nullptr)
	{
		head = newTask;
		tail = newTask;
	}
	else
	{
		tail->next = newTask;
		newTask->prev = tail;
		tail = newTask;
	}
	size++;
}

// Edit a task in the list
void LinkedList::editTask(int taskID, string taskName, string description, string startDate, string endDate, string priority, string status, string assignee)
{
	TaskNode* current = head;
	while (current != nullptr)
	{
		if (current->taskID == taskID)
		{
			current->taskName = taskName;
			current->description = description;
			current->startDate = startDate;
			current->endDate = endDate;
			current->priority = priority;
			current->status = status;
			current->assignedUser = assignee;
			return;
		}
		current = current->next;
	}
}

// Remove a task from the list
void LinkedList::removeTask(int taskID)
{
	TaskNode* current = head;
	while (current != nullptr)
	{
		if (current->taskID == taskID)
		{
			if (current->prev != nullptr)
			{
				current->prev->next = current->next;
			}
			else
			{
				head = current->next;
			}
			if (current->next != nullptr)
			{
				current->next->prev = current->prev;
			}
			else
			{
				tail = current->prev;
			}
			delete current;
			size--;
			return;
		}
		current = current->next;
	}
}


// Print the list of tasks
// This function should print the name of each task in the list, in order from the first task to the last
// Each task name should be printed on a new line
void LinkedList::printTaskList()
{
	TaskNode* current = head;
	while (current != nullptr)
	{
		cout << "Task ID: " << current->getTaskID() << endl;
		cout << "Task Name: " << current->getTaskName() << endl;
		cout << "Description: " << current->getDescription() << endl;
		cout << "Start Date: " << current->getStartDate() << endl;
		cout << "End Date: " << current->getEndDate() << endl;
		cout << "Priority: " << current->getPriority() << endl;
		cout << "Status: " << current->getStatus() << endl;
		cout << "Assigned User(s): " << current->getAssignedUser() << endl;
		cout << std::endl;
		current = current->next;
	}
}

// Print the list of tasks in reverse order
// This function should print the name of each task in the list, in order from the last task to the first
// Each task name should be printed on a new line
void LinkedList::printTaskListReverse()
{
	TaskNode* current = tail;
	while (current != nullptr)
	{
		cout << "Task ID: " << current->taskID << endl;
		cout << "Task Name: " << current->taskName << endl;
		cout << "Description: " << current->description << endl;
		cout << "Start Date: " << current->startDate << endl;
		cout << "End Date: " << current->endDate << endl;
		cout << "Priority: " << current->priority << endl;
		cout << "Status: " << current->status << endl;
		cout << "Assigned User(s): " << current->assignedUser << endl;
		cout << endl;
		current = current->prev;
	}
}

// Get the number of tasks in the list
// This function returns the number of tasks in the list
int LinkedList::getSize() const
{
	return size;
}

// Check if the list is empty
bool LinkedList::isEmpty() const
{
	return size == 0;
}

bool LinkedList::taskExists(int taskID)
{
	TaskNode* current = head;
	while (current != nullptr)
	{
		if (current->taskID == taskID)
		{
			return true;
		}
		current = current->next;
	}
	return false;
}

TaskNode* LinkedList::getHead() const
{
	return head;
}

void LinkedList::clear()
{
	TaskNode* current = head;
	while (current != nullptr)
	{
		TaskNode* next = current->next;
		delete current;
		current = next;
	}
	head = nullptr;
	tail = nullptr;
	size = 0;
}