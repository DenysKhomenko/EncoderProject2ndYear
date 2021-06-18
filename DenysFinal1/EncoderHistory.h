#include <vector>
using namespace std;
class EncoderHistory
{
public: // Access Specifier: Includes functions and variables that can be accessed from outside the class (main).
	EncoderHistory();
	~EncoderHistory();

	//declaration of EncoderHistory's methods responsible for storing values.
	void storeCurrentState(int state); // Storing Current State. 
	void storeXorOutput(int output); // Storing Output.
	void storeInputs(int input); // Storing Input storage.

								 // declaration of the class' methods responsible for the values after each input.
	int gettingState(int gs); // Gets each state of the shift register.
	int gettingOutput(int go); // Gets output for each state.
	int gettingInputs(int gi); // Gets the input for each state.

	int sizeOfoutputs(); // declaration of the class' method for the amount of outputs given.
	int sizeOfinputs(); // declaration of the class' method for the amount of inputs given.

private:  // AccessSpecifier: Includes functions and variables that can only be accessed from inside the class.
		  // Vector declaration
	vector<int> states; // Used to store all the given shift register states.
	vector<int> outputs; // Used to store all the given outputs.
	vector<int>inputs; // Used to store all the given inputs.
};



