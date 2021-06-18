#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <bitset>
#include <sstream>
#include "EncoderHistory.h"
using namespace std;


class Encoder
{
public: // Access Specifier: Includes functions and variables that can be accessed from outside the class (main).
	Encoder();
	~Encoder();

	//declaring the class' methods.
	void takeInput();      // Used to get the input.
	void calcOut();        // Used to calculate the output using the XOR relation.
	void printOut();       // Used to print everything on the screen.
private:                   // AccessSpecifier: Includes functions and variables that can only be accessed from inside the class.
	int SR[3];             // Declaring an array of integers for the shift registers.
	ifstream inFile;       // Declaring a variable that will be used for the text file.
	int inputInt = -1;     // Declaring a integer variable.
	string choice;         // Declaring a string that will be used for user choice.
	EncoderHistory History;//Make an instance (copy) of the EncoderHistory class where we store input, output, shift reg data.
};




