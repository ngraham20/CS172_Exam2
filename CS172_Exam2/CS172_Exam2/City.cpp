/*
I affirm that all code given below was written soley by me,
Nathaniel Lewis Graham, and that any help I received adhered
to the rules stated for this exam.
*/
#include "City.h"
using namespace std;

City::City(string cityName)
{
	name = cityName; // initializes cityName
	population = 0; // initializes population count

	ifstream input;

	string filename = cityName + ".txt";
	input.open(filename.c_str());
	if (!input.fail()) // if the file exists, read the population from file
	{
		while (!input.eof())
		{
			// sets the variables to be loaded from file
			int id;
			string firstname;
			string lastname;
			string favoriteColor;

			input >> id >> firstname >> lastname >> favoriteColor; // loads variables from file

			if (firstname != "") // prevents adding blank names
			{
				Citizen* temp = new Citizen(id, firstname, lastname, favoriteColor); // creates new pointer to be added to the system

				addCitizen(temp); // sends temp to the City

				delete temp; // deletes temp
			}
		}
		input.close(); // closes document
	}
}

City::~City() // sets population to file <cityName> <population>
{
	ofstream output;
	string filename = name + ".txt";
	output.open(filename.c_str());
	if (!output.fail())
	{
		// sends City info to file.
		for (int i = 0; i < citizens.size(); i++)
		{
			Citizen temp = citizens.at(i);

			int id = temp.getId();
			string firstname = temp.getFirstName();
			string lastname = temp.getLastName();
			string favoriteColor = temp.getFavoriteColor();

			output << id << " " << firstname << " " << lastname << " " << favoriteColor << endl;
		}
		return;
	}
	else // the file didn't open...
	{
		// since the destructor has been called,
		// the city WILL be destryed. This causes
		// a new city to be created with the old
		// one's name and population.
		City(this->name);
	}
}

string City::getCityName() { return name; }

int City::populationSize() { return population; }

Citizen * City::getCitizenAtIndex(int index)
{
	return citizens.at(index); // returns the memory location of the citizen at index
}

void City::addCitizen(Citizen * citizen)
{
	Citizen* c = new Citizen(citizen->getId(), citizen->getFirstName(), citizen->getLastName(), citizen->getFavoriteColor());
	citizens.push_back(c); // adds the memory location of c to citizens (therefore deleting c will affect citizens as well)
	population++;
}

Citizen * City::getCitizenWithId(int id)
{
	for (int i = 0; i < citizens.size(); i++) // searches citizens for any citizen with unique id
	{
		Citizen temp = citizens.at(i); // creates a temporary citizen

		if (temp.getId() == id) // checks the citizen's id
		{
			return citizens.at(i); // returns it if the id is correct
		}
	}
}

vector<Citizen*> City::getCitizensForFavoriteColor(string color)
{
	vector<Citizen*>* citizensForColor = new vector<Citizen*>; // creates a vector to be returned

	for (int i = 0; i < citizens.size(); i++) // loops through all citizens
	{
		Citizen temp = citizens.at(i); // creates a temp citizen
		if (temp.getFavoriteColor() == color) // checks the citizen for favorite color
		{
			// creates a return pointer holding the value of temp within it
			Citizen* citizenReturn = new Citizen(temp.getId(), temp.getFirstName(), temp.getLastName(), temp.getFavoriteColor());
			citizensForColor->push_back(citizenReturn);
		}
	}
	return *citizensForColor;
}
