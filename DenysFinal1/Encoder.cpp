#include "Encoder.h"



Encoder::Encoder()
{
	//setting initial states of all the registers to be 0.
	SR[0] = 0;
	SR[1] = 0;
	SR[2] = 0;
}

void Encoder::takeInput() // defining the method "takeInput".
{
	cout << "Please enter the input filename or type in the input sequence from the keyboard: " << endl;
	cin >> choice;
	inFile.open(choice); // Open text file.
	if (inFile.good()) //User can write the text file both ways.
	{

		ifstream ifs(choice, ios::ate); // sets the indicator to the end of the stream when opened.
		int size = ifs.tellg();
		if (size == 0)                           // if the size of the file is 0, print that it's empty.
		{
			cout << "File is empty. Program will now quit." << endl;
			exit(EXIT_FAILURE);
		}
		else
		{
			cout << "Input file opened successfully..." << endl;
		}

		while (!inFile.eof())                    // Run while the file didn't finish.
		{

			string input;
			getline(inFile, input, ';');         //stores text file content, where ';' is the delimiter.

			if (input.length() == 0)             // Read file untill there is no data left.
			{
				cout << endl;
				break;
			}
			try {                                // Error exception.

				inputInt = stoi(input);          // Converting "input" to a integer.
			}
			catch (std::invalid_argument& e)     // Do nothing when invalid argument.
			{

			}
			catch (std::out_of_range& e)         //Do nothing when the input is too large
			{

			}

			if (inputInt != 0 && inputInt != 1)  //Print error message when the input is not 0s or 1s.
			{
				cout << "Wrong filename or corrupted. Please restart it and try again. " << endl;
				exit(EXIT_FAILURE);
			}

			History.storeInputs(inputInt); //Storing the input values given by the user in EncoderHistory's method.
		}

		inFile.close(); // Closing input file.


	}

	else
	{

		for (int currentInput = 0; currentInput < choice.length(); currentInput++) // Read user input values one by one. 
		{
			inputInt = choice[currentInput] - 48; // Converting char to int.

			if (inputInt != 0 && inputInt != 1) // Print error message when the input is not 0s or 1s.
			{
				cout << "A wrong input/filename has been set. Restart and try again" << endl;
				exit(EXIT_FAILURE);
			}

			History.storeInputs(inputInt); //Storing the input values given by the user in EncoderHistory's method.

		}
		cout << "User input read successfully..." << endl;
		cout << endl;
	}
}


void Encoder::calcOut() //Defining the Encoder's class method used to calcualte the output.
{

	for (int currentInput = 0; currentInput < History.sizeOfinputs(); currentInput++) //reading input values one by one.
	{
		SR[2] = SR[1];                         // shifting the value from register 1 to register 2.
		SR[1] = SR[0];                         // shifting the value from register 1 to register 2.
		SR[0] = History.gettingInputs(currentInput); // shifting the input value from the vector to the shift register 0.
		History.storeCurrentState(SR[0]);
		History.storeCurrentState(SR[1]);      // storing the shift register values for each state.
		History.storeCurrentState(SR[2]);
		History.storeXorOutput(SR[1] ^ SR[2]); // push back from output A.
		History.storeXorOutput(SR[1]);         // push back from output B.
		History.storeXorOutput(SR[0] ^ SR[2]); // push back from output C

	}
}
void Encoder::printOut() //Defining the Encoder's class method used to print everything on screen.
{
	stringstream trellisOutput;
	trellisOutput << "Input : n/a, ";

	for (int currentInput = 0; currentInput < History.sizeOfinputs(); currentInput++) //loop used to know how many inputs to print.
	{
		trellisOutput << History.gettingInputs(currentInput);

		if (currentInput < (History.sizeOfinputs()) - 1)   // Loop used for removing the last "," after the last input value.
		{
			trellisOutput << "  , ";
		}

	}

	trellisOutput << endl;

	trellisOutput << "Output: n/a";

	for (int currentOutput = 0; currentOutput < History.sizeOfoutputs(); currentOutput++)//reading output values one by one.
	{
		if (currentOutput % 3 == 0)     // dividing the spaces occupied by the numbers by 3, if the remainder is 0, print a "space".
		{
			trellisOutput << ", ";
		}
		trellisOutput << History.gettingOutput(currentOutput) << ""; // print the output values.
	}

	trellisOutput << endl;

	trellisOutput << "Current State:";


	trellisOutput << endl;
	for (int row = 0; row < 8; row++)
	{
		bitset<3>rowBinary = row; //converting row number to binary.
		trellisOutput << rowBinary << "(" << row << ") :";// printing the number of the rows in binary with the following decimal numbers.

		for (int currentState = 0; currentState < History.sizeOfoutputs() + 1; currentState++) //know how many states to print.
		{
			if (currentState % 3 == 0) // dividing the number of states by  3 and adding the values of each register together.
			{
				int currentShiftReg = History.gettingState(currentState) * 4 + History.gettingState(currentState + 1) * 2 + History.gettingState(currentState + 2); // converting the binary values of the shift registers to decimal.
				if (currentShiftReg == row) // if the line number in decimal is equal to the shift registers decimal value it will print an "X" else print "    :" .
				{
					trellisOutput << "  X :";
				}
				else
					trellisOutput << "    :";
			}
		}
		trellisOutput << endl;
	}

	string trellis = trellisOutput.str();
	cout << trellis;

	cout << "Do you want the output to be saved to a text file? yes/no." << endl;
	string answer;
	cin >> answer;
	if (answer == "yes")
	{
		ofstream trellisout;
		trellisout.open("TrellisOutput.txt");
		trellisout << trellis; // output the trellis diagram to the text file.
		trellisout.close();
	}
	else
	{
		cout << "File won't be saved!" << endl;
	}

}

Encoder::~Encoder()
{
}

