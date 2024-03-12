#include "UserStorage.h"
#include "UserObserver.h"

UserStorage::UserStorage(const std::string& filename)
{
	this->filename = filename;
}

UserStorage::UserStorage()
{
	filename = "users.txt";
}

UserStorage::~UserStorage()
{

}

void UserStorage::loadUsers()
{
	std::ifstream inputFile(filename);
	if (inputFile.is_open())
	{
		std::string username;
		std::string firstName;
		std::string lastName;
		while (inputFile >> username >> firstName >> lastName)
		{
			User user(username, firstName, lastName);
			users.push_back(user);
		}
		inputFile.close();
	}
}

void UserStorage::saveUsers()
{
	std::ofstream outputFile(filename);
	if (outputFile.is_open())
	{
		for (int i = 0; i < users.size(); i++)
		{
			outputFile << users[i].getUsername() << " " << users[i].getFirstName() << " " << users[i].getLastName() << std::endl;
		}
		outputFile.close();
	}
}

void UserStorage::addUser(string username, string firstName, string lastName)
{
	User newUser(username, firstName, lastName);
	users.push_back(newUser);
	addObserver(new UserObserver(newUser));
	saveUsers();
	notifyObservers();
}

void UserStorage::editUser(string username, string firstName, string lastName)
{
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].getUsername() == username)
		{
			users[i].setFirstName(firstName);
			users[i].setLastName(lastName);
			saveUsers();
		}
	}
}

void UserStorage::listUsers()
{
	for (int i = 0; i < users.size(); i++)
	{
		cout << "Username: " << users[i].getUsername() << endl;
		cout << "First Name: " << users[i].getFirstName() << endl;
		cout << "Last Name: " << users[i].getLastName() << "\n" << endl;
	}
}

void UserStorage::listUserFirstNames()
{
	cout << "\nUser Names: " << endl;
	for (int i = 0; i < users.size(); i++)
	{
		cout << "Name: " << users[i].getFirstName() << " " << users[i].getLastName() << endl;
	}
}

bool UserStorage::userListIsEmpty()
{
	if (users.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool UserStorage::userExists(string username)
{
	if (std::find_if(users.begin(), users.end(), [username](const User& user)
		{
			return user.getUsername() == username;
		}) != users.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void UserStorage::removeUser(string username)
{
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].getUsername() == username)
		{
			users.erase(users.begin() + i);
			saveUsers();
		}
	}
}

void UserStorage::addObserver(Observer* observer)
{
	observers.push_back(observer);
}

void UserStorage::removeObserver(Observer* observer)
{
	// Iterate over the list of observers to find the specified observer
	auto it = std::find(observers.begin(), observers.end(), observer);

	// If the observer is found, remove it from the list
	if (it != observers.end())
	{
		observers.erase(it);
	}
}

void UserStorage::notifyObservers()
{
	for (Observer* observer : observers)
	{
		observer->update();
	}
}

