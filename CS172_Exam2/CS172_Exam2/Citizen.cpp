#include "Citizen.h"

void Citizen::setFavoriteColor(string color) { this->favoriteColor = color; }

Citizen::Citizen(int id, string firstName, string lastName, string color)
{
	this->id = id;
	this->firstName = firstName;
	this->lastName = lastName;
	this->favoriteColor = color;
}

Citizen::Citizen(Citizen * citizen)
{
	this->id = citizen->id;
	this->firstName = citizen->firstName;
	this->lastName = citizen->lastName;
	this->favoriteColor = citizen->favoriteColor;
}

string Citizen::getFirstName() { return firstName; }

string Citizen::getLastName() { return lastName; }

int Citizen::getId() { return id; }

string Citizen::getFavoriteColor() { return favoriteColor; }
