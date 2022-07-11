
#include <iostream>
#include<fstream>
#include <iomanip>

using namespace std;

//Decalaring variables:
int acc = 0;
const int scoreList = 5; //There are 4 rows of scores in the txt file
char dots = '.';
const int players = 10;  //There are 10 players in the txt file
ifstream infile;  //Opens the txt file

string file = "BowlingScores.txt";  //Defines the txt file



struct bowlersNames {
	string names{};
	int score[scoreList]{};
	double average{};
};

bowlersNames people[players]; //This will be used to get information from the txt file

bool GetBowlingData(const string& file, bowlersNames people[], int& acc) {

	

	fstream infile(file);

	while (!infile.eof()) //While file is being read..
	{
		if (!infile) { //If the the file cannot be open, it will print the following lines.
			cout << "File not found" << endl;
			return false;
		}

		else {
			while (infile >> people[acc].names) //While getting the names one by one, it'll take the scores along those names
			{
				for (int i = 0; i < scoreList; i++)

					infile >> people[acc].score[i]; 

				acc++;

			}
		}



		return true;
	}

}


void getAverageScore(bowlersNames people[], int acc) {  //This function calculates the average of the scores for each player.
	

	for (int i = 0; i < acc; i++)
	{
		float avg = 0;

		for (int x = 0; x < scoreList; x++)
		{
			avg = avg + people[i].score[x];  //The 4 scores for each player gets stored in the 'avg' variable
		}

		people[i].average = int(avg / scoreList); //The added value then gets divided by 4
	}
}




void PrettyPrintResults(bowlersNames people[], int acc)  //Prints the average along with the names and the scores
{


	for (int i = 0; i < acc; i++)
	{
		std::cout << "\nPlayer " << (i+1) << ": " << people[i].names << setw(10) << setfill(dots) << dots << endl; //Prints the player's names
		std::cout << "Score: ";
		for (int x = 0; x < scoreList; x++) //Prints the list of scores in the next line
		{
			std::cout << " " << people[i].score[x];
		}

		cout << "\nAverage: " << people[i].average << endl; //Prints the average score in the next line
	}
}





int main()
{

	//Welcome message:
	std::cout << "\n";
	std::cout << "Average scores list" << setw(50) << setfill('*') << endl;
	std::cout << "\n";

	if (GetBowlingData(file, people, acc)) //If the file is found then the following functions will work
	{

		getAverageScore(people, acc);
		PrettyPrintResults(people, acc);

	}
	else {  //If the file can not be found then it will print out "File not found"
		return 0;
	}

	infile.close(); //After getting the information and printing the results it will close the file
}






