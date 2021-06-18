#include "EncoderHistory.h"



EncoderHistory::EncoderHistory()
{
	states.push_back(0);
	states.push_back(0); // puts the default shift register state to 0.
	states.push_back(0);
}

//Definning the EncoderHistory's methods
//The following 3 methods are resposible for storing values.
void EncoderHistory::storeCurrentState(int state)
{
	states.push_back(state);

}

void EncoderHistory::storeXorOutput(int output)
{

	outputs.push_back(output);

}
void EncoderHistory::storeInputs(int input)
{

	inputs.push_back(input);

}

//The 3 methods bellow are in charge of getting each values and store them in the appropriate vector.
int EncoderHistory::gettingState(int gs)
{

	return states[gs];

}
int EncoderHistory::gettingOutput(int go)
{

	return outputs[go];

}

int EncoderHistory::gettingInputs(int gi)
{

	return inputs[gi];
}

// The methods bellow, are responsible for outputting the size of the trellis diagram
// by having the quantity of the inputs and outputs.
int EncoderHistory::sizeOfoutputs()
{

	return outputs.size();
}
int EncoderHistory::sizeOfinputs()
{

	return inputs.size();
}
EncoderHistory::~EncoderHistory()
{
}

