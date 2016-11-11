#include "City.h"
using namespace std;

City::City(string cityName)
{
	name = cityName;
	population = 0;

	ifstream input;

	string filename = cityName + ".txt";
	input.open(filename.c_str());
	if (!input.fail()) // if the file exists, read the population from file
	{
		while (!input.eof())
		{
			int id;
			string firstname;
			string lastname;
			string favoriteColor;

			input >> id >> firstname >> lastname >> favoriteColor;

			if (firstname != "")
			{
				Citizen* temp = new Citizen(id, firstname, lastname, favoriteColor);

				addCitizen(temp);
			}
		}
		input.close();
	}
}

City::~City() // sets population to file <cityName> <population>
{
	ofstream output;
	string filename = name + ".txt";
	output.open(filename.c_str());
	if (!output.fail())
	{
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
	return citizens.at(index);
}

void City::addCitizen(Citizen * citizen)
{
	Citizen* c = new Citizen(citizen->getId(), citizen->getFirstName(), citizen->getLastName(), citizen->getFavoriteColor());
	citizens.push_back(c);
	population++;
}

Citizen * City::getCitizenWithId(int id)
{
	// 
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	for (int i = 0; i < citizens.size(); i++)
	{
		Citizen temp = citizens.at(i);

		if (temp.getId() == id)
		{
			Citizen* citizenReturn = new Citizen(temp.getId(), temp.getFirstName(), temp.getLastName(), temp.getFavoriteColor());
			return citizenReturn;
		}
	}
}

vector<Citizen*> City::getCitizensForFavoriteColor(string color)
{
	vector<Citizen*>* citizensForColor = new vector<Citizen*>;

	for (int i = 0; i < citizens.size(); i++)
	{
		Citizen temp = citizens.at(i);
		if (temp.getFavoriteColor() == color)
		{
			Citizen* citizenReturn = new Citizen(temp.getId(), temp.getFirstName(), temp.getLastName(), temp.getFavoriteColor());
			citizensForColor->push_back(citizenReturn);
		}
	}
	return *citizensForColor;
}
