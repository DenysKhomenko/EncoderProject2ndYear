#include"Encoder.h"
using namespace std;

int main()
{
	bool programRestart = true; // declaring a boolean variable.
	while (programRestart == true) // loop used for restarting the program when it's finished and if user wants to.
	{
		cout << "Convolutional Encoder Analyser" << endl;
		cout << "Welcome to the Encoder! " << endl;
		cout << "Denys Khomenko  SID: 8097325 " << " Coventry University" << endl;
		cout << "Output A = G(011), Output B = G(010), Output C = G(101)" << endl << endl;

		Encoder encoder; // creating a copy of the class

		encoder.takeInput(); //calling the methods from Encoder's class.
		encoder.calcOut();
		encoder.printOut();

		cout << "Would you like to re-run the program?" << endl;
		string restart;
		cin >> restart;

		if (restart == "yes" || restart == "Yes" || restart == "YES" || restart == "Y" || restart == "y") // if user says "yes" the command prompt will be erased and the program will be restarted.
		{

			system("cls"); // clears the command prompt.

		}
		else //If user doesnt want to re-run the program it will Leave the loop and print the message bellow.
		{

			programRestart = false;

		}

	}
	cout << "Thank you for using the convolutional encoder program." << endl << "Goodbye!" << endl;

	return 0;
}