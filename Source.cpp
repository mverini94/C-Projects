#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <climits>


void randomStream(std::string fileName, int length);

int main() {
	
	int linesInFile;
	std::string fileName;
	std::cout << "Please enter the filename you would like to write to: " << std::endl;
	std::cin >> fileName;
	std::cout << "Please enter the number of lines for the file: " << std::endl;
	std::cin >> linesInFile;
	randomStream(fileName, linesInFile);

}

/*This function takes in the fileName parameter and length of the file
to output random letters vertically which are specified by how many
lines the user enters*/

void randomStream(std::string fileName, int length) {
	char randomLetters[6] = { 'A', 'D', 'P', 'E', 'C', 'S' };

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(INT_MIN, INT_MAX);

	std::ofstream outFile;
	outFile.open(fileName);

	for (int i = 0; i < length; i++)
	{
		char currentCharacter = randomLetters[rand() % 6];

		if (currentCharacter == 'A') {
		outFile << currentCharacter << " ";
		outFile << dis(gen) << std::endl;
		}
		else {
			outFile << currentCharacter << std::endl;
		}
	}
	outFile.close();
}




