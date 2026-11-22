#include "mercy.h"

#include <iostream>
#include <string>
#include <vector>

int main()
{
	//Counting unforgiven and forgiven sins, using integers and arrays:
	int unforgivenVenialSins = 0;
	int unforgivenMortalSins = 0;

	std::vector<int> forgivenVenialSinsList =
	{
		0, //I.e., forgiven venial sins after receiving absolution for the first time.
		0, //Forgiven venial sins after receiving absolution for the second time.
		0, //Etc.
		0,
		0,
		0,
		0,
		0,
		0,
		0
	};

	std::vector<int> forgivenMortalSinsList =
	{
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	};

	//Total forgiven and unforgiven sins:
	int totalUnforgivenSins = unforgivenVenialSins + unforgivenMortalSins;
	int totalSinsForgiven = forgivenVenialSinsList.size() + forgivenMortalSinsList.size();

	//The total amount of times the person has been absolved:
	int absolution_i = 0; //The program ends when reaching 10.
	//Setting a variable for the person in question:
	std::string nameOfPerson;

	//To be in a state of grace, a person must have no unforgiven mortal sins:
	bool stateOfGrace = false;
	if (unforgivenMortalSins > 0)
	{
		stateOfGrace = false;
	}

	else
	{
		stateOfGrace = true;
	}

	//Prompting and storing the name of the person:
	std::cout << "Enter the name of a person: " << std::endl;
	std::getline(std::cin, nameOfPerson);

	//Most of the code lies on this line:
	sacraments::sacramentOfBaptism(bool checkBaptism, std::string promptBaptism, int userInput, std::string nameOfPerson, sacraments::listOfSins forgivenVenialSinsList, sacraments::listOfSins forgivenMortalSinsList, int unforgivenVenialSins, int unforgivenMortalSins, int absolution_i);
	
	if (absolution_i++)
	{
		for (int mortalSinsIndex = 0; forgivenMortalSinsList.size(); mortalSinsIndex++)
		{
			//This function calls its helper functions.
			{
				/* Will insert the remaining functions. Planning to print the total forgiven mortal and venial
				sins individually and their sum, */
				if (std::cin >> forgivenMortalSinsList)
				{
					forgivenMortalSinsList[mortalSinsIndex];
				}
			}
		}
	}
	//The final std::cout lines of code to be seen:
	std::cout << "Total forgiven venial sins: " << forgivenVenialSinsList.size() << std::endl;
	std::cout << "Total forgiven mortal sins: " << forgivenMortalSinsList.size() << std::endl;
	std::cout << nameOfPerson << "has been forgiven of " << totalSinsForgiven << " sins total " <<
	std::endl;
}