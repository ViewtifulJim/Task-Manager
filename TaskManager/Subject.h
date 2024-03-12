#pragma once
#include "Observer.h"
#include <vector>

class Observer;

class Subject
{
public:
	virtual void addObserver(Observer* observer) = 0;
	virtual void removeObserver(Observer* observer) = 0;
	virtual void notifyObservers() = 0;
};
