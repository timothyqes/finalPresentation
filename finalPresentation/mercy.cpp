#include "mercy.h"

#include <iostream>
#include <string>
#include <vector>

/*void baptism() asks and stores whether the person is baptized, and also prompts, stores, and 
notifies of the person's forgiven sins after receiving the sacrament. The only way to proceed to the 
other sacraments (i.e., functions) is for the person to be baptized.*/
void sacramentOfBaptism(std::string nameOfPerson, sacraments::listOfSins forgivenVenialSinsList, sacraments::listOfSins forgivenMortalSinsList, int unforgivenVenialSins, int unforgivenMortalSins, int absolution)
{
	//Setting variables for the prompts:
	bool baptismB = false;
	std::string baptismS = " ";
	
	bool consentForBaptism = false;
	std::string consentForBaptismS = " ";
	
	//Prompts for whether the person is baptized:
	std::cout << "Is " << nameOfPerson << "baptized? (enter 'yes' or 'no'): " << std::endl;
	std::getline(std::cin, baptismS);

	if (baptismS == "yes")
	{
		bool baptism = true;
		//Prompt and store forgiven venial sins before baptism:
		std::cout << "How many venial sins (i.e., sins that do not break relationship with God) did " 
			<< nameOfPerson << " commmit before reception of the Sacrament? " <<
			std::endl;
		std::cin, forgivenVenialSinsList[0]; //Working on whether cin will be used here.
		
		//Prompt and store unforgiven mortal sins before baptism:
		std::cout << "How many mortal sins (sins that break relationship with God) did " <<
			nameOfPerson << "commit before recpetion of the Sacrament of Baptism? " << std::endl;
		std::cin, forgivenMortalSinsList[0];

		//Mercy
		unforgivenVenialSins = 0;
		unforgivenMortalSins = 0;

		absolution++; //Incrementing for the while loop in the main() function.
		
		//Proceeds to the Sacrament of Confession after reaching this point.
		sacramentOfConfession(nameOfPerson, baptismB, baptismS, forgivenVenialSinsList, forgivenMortalSinsList); //Working on the unfinished confession() function.
	}

	//Consent for reception of the Sacrament of Baptism.
	if (baptismS == "no")
	{
		bool baptism = false;
		while (baptism = false)
		{
			std::cout << "Would " << nameOfPerson << " like to be baptized? (enter 'yes' or 'no'): " 
				<< std::endl;
			std::getline(std::cin, baptismS);
			if (baptismS = "yes")
			{
				bool baptism = true;
			}
		}
		//Will not proceed to the next function until the person is baptized:
		sacramentOfConfession(nameOfPerson, baptismB, forgivenVenialSinsList, forgivenMortalSinsList);
	}
	else
	{
		bool baptism = true;
		//Prompt and store forgiven venial sins before baptism:
		std::cout << "How many venial sins (i.e., sins that do not break relationship with God) did "
			<< nameOfPerson << " commmit before reception of the Sacrament? " <<
			std::endl;
		std::cin, forgivenVenialSinsList[0]; //Working on whether I should use cin here.

		//Prompt and store unforgiven mortal sins before baptism:
		std::cout << "How many mortal sins (sins that break relationship with God) did " <<
			nameOfPerson << "commit before recpetion of the Sacrament of Baptism? " << std::endl;
		std::cin, forgivenMortalSinsList[0];

		//Proceeds to the Sacrament of Confession after reaching this point.
		sacramentOfConfession(nameOfPerson, baptismB, forgivenVenialSinsList, forgivenMortalSinsList);
	}
}

void sacramentOfConfession(std::string nameOfPerson, bool baptismB, std::string baptismS, sacraments::listOfSins forgivenVenialSinsList, sacraments::listOfSins forgivenMortalSinsList)
{
	//Confirming that the person is baptized, similar to the baptism() function:
		while (baptismB = false)
		{
			std::cout << "Would " << nameOfPerson << " like to be baptized? (enter 'yes' or 'no'): " 
				<< std::endl;
			std::cin, baptismS;
			if (baptismS = "yes")
			{
				bool baptism = true;
			}
		}
	//Proceeding to the Sacrament of Confession:
		{
			std::cout << "Is " << nameOfPerson <<
				"reasonably trying to repent of their sins? (enter 'yes' or 'no'): " << std::endl;
			std::getline(cin, repentence);
		}
}

void receivingCommunion()
{
	bool promptingForCommunion = "no";
}