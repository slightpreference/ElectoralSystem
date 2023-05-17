#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

void RegistrationOfPoliticalParties();
bool ValidationOfNames(string);
void ElectionDateAnnouncement();

int main()
{
	//RegistrationOfPoliticalParties();
	ElectionDateAnnouncement();
}

void RegistrationOfPoliticalParties()
{
	string temp;

	fstream Registration;
	Registration.open("sample.txt", ios::app);

	cout << "Name of Chairman: ";
	getline(cin, temp);

	if (!ValidationOfNames(temp))
	{
		cout << "You cannot register two parties on your name!" << endl;
	}
	else
	{
		Registration << temp << ",";

		cout << "Name of political party: ";
		getline(cin, temp);

		while (!ValidationOfNames(temp))
		{
			cout << "Already Registered. Would you consider another name: ";
			getline(cin, temp);
		}

		Registration << temp << endl;
	}

	Registration.close();
}

bool ValidationOfNames(string temp)
{
	string line;

	bool validName = true;
	fstream Registration;
	Registration.open("sample.txt", ios::in);

	int commaIndex = 0;

	while (getline(Registration, line))  // line by line through the file
	{
		string chairmanName,
			politicalParty;

		for (int i = 0; i < line.size(); i++) // checking the index of comma, helpful in separating chairman name and political party
		{
			if (line[i] == ',')   commaIndex = i;
		}

		for (int i = 0; i < commaIndex; i++) // chairman name separation
		{
			chairmanName += line[i];
		}

		for (int i = commaIndex + 1; i < line.size(); i++) // political party name separation
		{
			politicalParty += line[i];
		}

		if (chairmanName.compare(temp) || politicalParty.compare(temp)) // comparison
		{
			validName = false;
		}
	}

	return validName;
}

void ElectionDateAnnouncement()
{
	srand(time(NULL));

	int random;
	
	do 
	{
		random = (rand() % 100);

	} while (random > 60 || random < 10);

	cout << random << endl;
}
