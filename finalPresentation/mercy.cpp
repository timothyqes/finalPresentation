#include "mercy.h"

#include <iostream>
#include <string>
#include <vector>

/* sacramentOfBaptism() asks and stores whether the person is baptized, and also prompts, stores, and 
notifies of the person's forgiven sins after receiving the sacrament. The only way to proceed to the 
other sacraments (i.e., functions) is for the person to be baptized. Once nameOfPerson is baptized,
they should not be able to go through this function again. */
void sacramentOfBaptism(bool checkBaptism, std::string promptBaptism, int userInput, std::string nameOfPerson, sacraments::listOfSins forgivenVenialSinsList, sacraments::listOfSins forgivenMortalSinsList, int forgivenMortalSinsIndex, int forgivenVenialSinsIndex, int unforgivenVenialSins, int unforgivenMortalSins, int absolution_i)
{
	//Prompts for whether the person is baptized:
	std::cout << "Is " << nameOfPerson << "baptized? (enter 'yes' or 'no'): " << std::endl;
	std::getline(std::cin, promptBaptism);

	if (promptBaptism == "yes")
	{
		checkBaptism = true;
		//Prompt and store forgiven venial sins before baptism:
		std::cout << "How many venial sins (i.e., sins that do not break relationship with God) did "
			<< nameOfPerson << " commmit before reception of the Sacrament? " <<
			std::endl;
		std::cout << "Enter a number that is not spelt out (e.g., '10'): " << std::endl;
		std::cin, forgivenVenialSinsList[forgivenVenialSinsIndex]; //I.e., 0, the first item.

		//Prompt and store unforgiven mortal sins before baptism:
		std::cout << "How many mortal sins (sins that break relationship with God) did " <<
			nameOfPerson << "commit before recpetion of the Sacrament of Baptism? " << std::endl;
		std::cin, forgivenMortalSinsList[forgivenMortalSinsIndex];

		//Mercy:
		unforgivenMortalSins = 0;
		unforgivenVenialSins = 0;

		absolution_i++;
		forgivenMortalSinsIndex++; //Changes the variable placement in both arrays of sins.
		forgivenVenialSinsIndex++;

		//Proceeds to the Sacrament of Confession after reaching this point.
		sacraments::sacramentOfConfession(checkBaptism, nameOfPerson, promptBaptism, std::string promptRepentance, bool checkRepentance, forgivenVenialSinsList, unforgivenVenialSins, forgivenMortalSinsList, unforgivenMortalSins, absolution_i);
	}

	else //I.e., Anything besides "no" is inputted about whether he/she is baptized.
	{
		checkBaptism = false;
		std::cout << "Would " << nameOfPerson << " like to be baptized? (enter 'yes' or 'no'): " << 
			std::endl;

		if (promptBaptism == "yes")
		{
			bool checkBaptism = true;
			//Prompt and store forgiven venial sins before baptism:
			std::cout << "How many venial sins (i.e., sins that do not break relationship with God) did "
				<< nameOfPerson << " commmit before reception of the Sacrament? " <<
				std::endl;
			std::cin, forgivenVenialSinsList[forgivenVenialSinsIndex];

			//Prompt and store unforgiven mortal sins before baptism:
			std::cout << "How many mortal sins (sins that break relationship with God) did " <<
				nameOfPerson << "commit before recpetion of the Sacrament of Baptism? " << std::endl;
			std::cin, forgivenMortalSinsList[forgivenMortalSinsIndex];

			//Mercy:
			unforgivenMortalSins = 0;
			unforgivenVenialSins = 0;

			absolution_i++;
			forgivenMortalSinsIndex++;
			forgivenVenialSinsIndex++;

			//Proceeds to the Sacrament of Confession after reaching this point.
			sacraments::sacramentOfConfession(checkBaptism, nameOfPerson, promptBaptism, std::string promptRepentance, bool checkRepentance, forgivenVenialSinsList, unforgivenVenialSins, forgivenMortalSinsList, unforgivenMortalSins, absolution_i);
		}
		else
		{
			/* Proceeding to the Sacrament of Holy Communion, since the person cannot go to 
				confession if they are not baptized. Instead they may receive a blessing from a priest 
				during Holy Mass. */
			sacraments::sacramentOfCommunion(bool checkDesireToReceive, bool checkDesireForABlessing, std::string nameOfPerson, bool checkBaptism, std::string desireToReceive, bool checkStateOfGrace, std::string desireForABlessing, std::string nameOfPerson, sacraments::listOfSins forgivenVenialSinsList, int unforgivenVenialSins, int absolution_i);
		}
	}
}


void sacramentOfConfession(bool checkBaptism, std::string nameOfPerson, std::string promptBaptism, std::string promptRepentance, bool checkRepentance, sacraments::listOfSins forgivenVenialSinsList, int forgivenVenialSinsIndex, int unforgivenVenialSins, sacraments::listOfSins forgivenMortalSinsList, int forgivenMortalSinsIndex, int unforgivenMortalSins, int absolution_i)
{
	if (checkBaptism == true)
	{
		std::cout << nameOfPerson <<
			" enters the confessional, asks for the priest's blessing, and confesses their sins. "
			<< std::endl;
		std::cout << "Before beginning, is " << nameOfPerson <<
			"reasonably trying to repent of their sins? (enter 'yes' or 'no'): " << std::endl;
		std::getline(std::cin, promptRepentance);
		if (promptRepentance == "yes")
		{
			checkRepentance = true;
		}
		else //Continues to the else statement below after switching the bool variable to false.
		{
			checkRepentance = false;
		}

		if (checkRepentance == true) //The person will receive the sacrament.
		{
			std::cout << "How many venial sins " <<
				"(i.e., sins that do not break relationship with God) did " << nameOfPerson <<
				" commmit between now and after last receiving absolution? " << std::endl;
			std::cin, forgivenVenialSinsList[forgivenVenialSinsIndex]; //Working on whether I should use cin here.
			std::cin, unforgivenVenialSins;

			//Prompt and store unforgiven mortal sins before baptism:
			std::cout << "How many mortal sins (i.e., sins that break relationship with God) did " <<
				nameOfPerson << "commit between now and after last receiving absolution? " << std::endl;
			std::cin, forgivenMortalSinsList[forgivenMortalSinsIndex];
			std::cin, unforgivenMortalSins;

			if ((unforgivenVenialSins == 0) && (unforgivenMortalSins == 0))
			{
				std::cout << nameOfPerson << " is in a state of grace, and may receive" << 
					"Holy Communion." << std::endl;
				sacraments::sacramentOfCommunion(bool checkDesireToReceive, bool checkDesireForABlessing, std::string nameOfPerson, bool checkBaptism, std::string desireToReceive, bool checkStateOfGrace, std::string desireForABlessing, std::string nameOfPerson, sacraments::listOfSins forgivenVenialSinsList, int unforgivenVenialSins, int absolution_i);
			}

			else if ((unforgivenVenialSins >= 1) || (unforgivenMortalSins >= 1))
			{
				std::cout << "The priest tells " << nameOfPerson << " that their penance is " <<
					" to pray one decade of the rosary. " << std::endl;
			}

			else if ((unforgivenVenialSins >= 10) || (unforgivenMortalSins >= 3))
			{
				std::cout << "The priest tells " << nameOfPerson << " that their penance is " <<
					" to pray two decades of the rosary. " << std::endl;
			}

			else if ((unforgivenVenialSins >= 20) || (unforgivenMortalSins >= 5))
			{
				std::cout << "The priest tells " << nameOfPerson << " that their penance is " <<
					" to pray three decades of the rosary. " << std::endl;
			}

			else if ((unforgivenVenialSins >= 30) || (unforgivenMortalSins >= 7))
			{
				std::cout << "The priest tells " << nameOfPerson << " that their penance is " <<
					" to pray four decades of the rosary. " << std::endl;
			}

			else
			{
				std::cout << "The priest tells " << nameOfPerson << " that their penance is " <<
					" to pray the whole rosary once. " << std::endl;
			}

			//Mercy.
			std::cout << nameOfPerson << " is then asked to pray the Act of Contrition prayer. " <<
				std::endl;
			std::cout <<
				"then the priest says a short prayer, and absolves the person of all their sins, " <<
				" 'In the name of the Father, and of the Son, and of the Holy Spirit. Amen. " <<
				std::endl;

			unforgivenMortalSins = 0; //nameOfPerson is in a state of grace when reaching this line.
			unforgivenVenialSins = 0;

			absolution_i++;
			forgivenMortalSinsIndex++;
			forgivenVenialSinsIndex++;

			//Proceeds to the Sacrament of Communion at the end of this if() statement.
			sacramentOfCommunion(bool checkDesireToReceive, bool checkDesireForABlessing, std::string nameOfPerson, bool checkBaptism, std::string desireToReceive, bool checkStateOfGrace, std::string desireForABlessing, std::string nameOfPerson, sacraments::listOfSins forgivenVenialSinsList, int unforgivenVenialSins, int absolution_i);
		}
		else //nameOfPerson will be turned away from the sacrament, since they are not trying to repent.
		{
			std::cout << "The priest tells " << nameOfPerson << "that they are needing to make a " <<
				" genuine effort to repent of their sins to receive absolution. " << std::endl;
			std::cout << "He then invites them to receive the sacrament when they are making " <<
				" a genuine effort to repent of their sins. " << std::endl;

			/* The person returns to the confessional at the end of this else statment without
				receiving absolution. This will give them the opportunity to say "yes" to the
				repentance prompt. */
			sacramentOfConfession(bool checkBaptism, std::string nameOfPerson, std::string promptBaptism, std::string promptRepentance, bool checkRepentance, sacraments::listOfSins forgivenVenialSinsList, int unforgivenVenialSins, sacraments::listOfSins forgivenMortalSinsList, int unforgivenMortalSins, int absolution_i);
		}
	}
}


void sacramentOfCommunion(bool checkDesireToReceive, bool checkDesireForABlessing, std::string nameOfPerson, bool checkBaptism, std::string desireToReceive, bool checkStateOfGrace, std::string desireForABlessing, std::string nameOfPerson, sacraments::listOfSins forgivenVenialSinsList, int forgivenVenialSinsIndex, int unforgivenVenialSins, int unforgivenMortalSins, int absolution_i)
{
	//nameOfPerson goes to Mass.
	std::cout << nameOfPerson << " is attending Holy Mass, and the celebration reaches a point " <<
		" when the Eucharist (that is, the real presence of Jesus Christ) is brought to the " <<
		" congregation from the alter by the priest, clergy members, and other servers. " << std::endl;
	
	/* Tells the user that nameOfPerson needs to be in a state of grace to receive or else he/she will 
		commit a mortal sin. */
	std::cout << nameOfPerson << " must be in a state of grace, that is, not having " <<
		" any mortal sins they have committed be unforgiven, to receive Jesus. " << std::endl;

	//Receiving Holy Communion:
	std::cout << "Would " << nameOfPerson << " like to receive the Sacrament of " <<
		"Holy Communion? (enter 'yes' or 'no'): " << std::endl;
	std::cin, desireToReceive;

	if (desireToReceive == "yes")
	{
		checkDesireToReceive = true;
	}

	else //I.e., any input besides "yes".
	{
		checkDesireToReceive = false;
	}

	if ((checkDesireToReceive == true) && (checkStateOfGrace == true) && (checkBaptism == true))
	{
		std::cout << nameOfPerson << " receives Jesus in the Eucharist, and " <<
			" has eternal life, and Jesus will raise " << nameOfPerson <<
			" on the last day (John 6:53-54). " << std::endl;
		std::cout << "How many venial sins did " << nameOfPerson << " commit before receiving?" <<
			std::endl;
		std::cin, forgivenVenialSinsList[forgivenVenialSinsIndex];

		//Mercy:
		checkDesireToReceive = true;
		unforgivenVenialSins = 0;
		absolution_i++;


		//Returns the person to the Sacrament of Confession.
		sacramentOfConfession(bool checkBaptism, std::string nameOfPerson, std::string promptBaptism, std::string promptRepentance, bool checkRepentance, sacraments::listOfSins forgivenVenialSinsList, int unforgivenVenialSins, sacraments::listOfSins forgivenMortalSinsList, int unforgivenMortalSins, int absolution_i);
	}
	else if ((checkDesireToReceive == true) && (checkStateOfGrace == false) || 
		(checkBaptism == false))
	{
		unforgivenMortalSins++;
		std::cout << nameOfPerson << " has commited a mortal sin, because " << nameOfPerson << 
			"they received Jesus in the Eucharist while not in a state of grace, or without "
			<< "being baptized, or both " << std::endl;
	}
	else //I.e., desireToReceive is = false.
	{
		std::cout << "Would " << nameOfPerson << " like to go up and receive a blessing " <<
			" by the priest instead? (enter 'yes' or 'no'): " << std::endl;
		std::cin, desireForABlessing;

		if (desireForABlessing == "yes")
		{
			checkDesireForABlessing = true;
		}
		else
		{
			checkDesireForABlessing = false;
		}

		if (checkDesireForABlessing == true)
		{
			std::cout << nameOfPerson << "Goes up to the alter steps and crosses " <<
				" their arms to show the priest that they would like to " <<
				"receive a blessing rather than receiving Holy Communion " << std::endl;
			std::cout << "The priest raises his hand towards " << nameOfPerson << " and " <<
				" says, 'Receive the risen Lord Jesus Christ into your heart.' " << std::endl;
		}
		else
		{
			std::cout << nameOfPerson << " remains in their pew, and receives a final " <<
				" blessing at the end of Holy Mass. " << std::endl;
			std::cout << "The priest or deacon says, 'Go in peace.' And " << nameOfPerson <<
				" says, 'Thanks be to God.' " << std::endl;
		}
		//Back to the Sacrament of Confession
		sacramentOfConfession(bool checkBaptism, std::string nameOfPerson, std::string promptBaptism, std::string promptRepentance, bool checkRepentance, sacraments::listOfSins forgivenVenialSinsList, int unforgivenVenialSins, sacraments::listOfSins forgivenMortalSinsList, int unforgivenMortalSins, int absolution_i);
	}
}