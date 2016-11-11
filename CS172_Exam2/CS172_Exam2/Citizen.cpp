#include "Citizen.h"

void Citizen::setFavoriteColor(string color) 
{
	this->favoriteColor = color; // sets the favorite color of the citizen to the specified color
}

Citizen::Citizen(int id, string firstName, string lastName, string color) // this creates a citizen with specified attributes
{
	this->id = id;
	this->firstName = firstName;
	this->lastName = lastName;
	this->favoriteColor = color;
}

Citizen::Citizen(Citizen * citizen) // this creates a citizen to be added to a city
{
	/*this->id = citizen->id;
	this->firstName = citizen->firstName;
	this->lastName = citizen->lastName;
	this->favoriteColor = citizen->favoriteColor;*/

	id = citizen->getId();
	firstName = citizen->getFirstName();
	lastName = citizen->getLastName();
	favoriteColor = citizen->getFavoriteColor();
}

string Citizen::getFirstName() { return firstName; }

string Citizen::getLastName() { return lastName; }

int Citizen::getId() { return id; }

string Citizen::getFavoriteColor() { return favoriteColor; }
