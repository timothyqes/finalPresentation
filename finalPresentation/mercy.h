#include <string>
#include <vector>
#pragma once

namespace sacraments /*This entire program is about a person finding the opportunity to receive three 
	sacraments, and to frequent two of them.*/
{
	//A type alias to get to std::vector<int> for convenience.
	using listOfSins = std::vector<std::string>;

	/*
	Baptism:
	First asks the user if the person is baptized.

	If the user says "yes", the program will ask how many unforgiven sins the person had before receiving
	the sacrament, will store their input, will notify the user that the person's sins at the time of
	baptism were forgiven, sets a boolean variable tied to the sacrament of Baptism to true (1), and
	proceed to the Sacrament of Confession function.

	If the user says, "no", they will be asked whether the person would like to be baptized. If the user
	says "no", they will be asked in a loop whether the person would like to be baptized until they say "yes".

	Once the user enters that the person would like to be baptized, the number of venial and mortal sins will be
	prompted and stored, will be forgiven and reset the value of the current number of mortal and venial sins to "0",
	and stores the number of sins forgiven in this first instance in an array counting them. A boolean
	variable tied the the Sacrament of Baptism will be switched to true (1), and the person will be
	prompted for the Sacrament of Holy Communion.
	*/
	void sacramentOfBaptism(std::string nameOfPerson, listOfSins forgivenVenialSinsList, listOfSins forgivenMortalSinsList, int unforgivenVenialSins, int unforgivenMortalsins, int absolution);

	/*
	Confession:
	After the program confirms that the user is baptized (i.e., the boolean variable is true), the user
	is prompted for whether the person is reasonably trying to repent of sin, and their response will be
	stored in a boolean variable.
	If they say "no", then they will be asked again whether the person is
	trying to repent of sin, but as if it was a new time they are going to Confession.
	Once the boolean variable tied to repentance is switched from false to true, the user will be asked
	whether person will receive the Sacrament of Confession. Inputting "yes" for the person will prompt
	the user and store the person's amount of mortal and venial sins that are not forgiven, but as the
	user is being prompted, the terminal will say that the person is telling the priest their sins, which
	is telling Jesus them.

	Once the user enters the person's amount of sins, thus receiving the graces of Confession, the user's
	input will be counted as forgiven, meaning that the variables counting the current number of
	unforgiven sins, including mortal sins will update to "0", which will update the boolean variable
	named stateOfGrace to true.

	Confession - Penance:
	After receiving the sacrament, the person's penance (i.e., beginning to restore what was damaged in
	the person's relaitonship with God), at least one mortal sin or twenty venial sins will correspond to
	one decade of the rosary (then three mortal sins or fourty venial sins will count as two decades,
	etc.), and the max amount of mortal and venial sins to reach the highest penance, that is, praying the
	rosary, would be 9 mortal sins or 100 venial sins.

	A while () loop could begin at this function. It may terminate after 10 receptions of the Sacrament
	of Confession, which could look like: while (absolutionCounter != 10) { }. This loop may also add,
	for each iteration, an entry to an array that lists the amount of sins forgiven for every reception of
	the sacrament of Baptism and Confession. This means that I should make at least ten arrays, each
	named for the respective set of forgiven sins.
	*/
	void sacramentOfConfession(std::string nameOfPerson, bool baptismB, std::string baptismS, listOfSins forgivenVenialSinsList, listOfSins forgivenMortalSinsList);

	/*
	Communion:
	Prompts the user whether they would like to receive communion during Holy Mass. The cin answer will be
	"yes" or "no".
	This function presupposes that the person has fasted from food and drink (excluding water) for one
	hour or more before receiving communion. This function also checks whether the person has been
	baptized, which is required for receiving the sacrament. If the person is not, then they will be
	prompted for it in the function, baptism_and_confession([...]).

	If the person is in a state of grace:
	If the user's input is "yes", the terminal tells them that the person has received the Eucharist
	(Jesus Christ Himself) and that the person has life within them and eternal life (John 6:53-4, Revised
	Standard Version, Second Catholic Edition).
	Saying "no" while in a state of grace tells the user in the terminal that they may receive a blessing
	by the priest or server.

	If the user is in a state of mortal sin or is not baptized:
	The user's input as "yes" tells them in the terminal that they are still in a state of mortal sin or
	are not baptized, one more mortal sin has been added, and will be encouraged to go to confession or
	receive the Sacrament of Baptism.
	Saying "no" while in a state of mortal sin tells the user in the terminal that they are encouraged to
	go to confession, and that they may receive a blessing.
	*/
	void receivingCommunion(std::string nameOfPerson, listOfSins forgivenVenialSinsLIst, listOfSins forgivenMortalSinsList, listOfSins unforgivenVenialSinsList, listOfSins unforgivenMortalSinsList);
}