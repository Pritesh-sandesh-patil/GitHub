#include <iostream>
#include <windows.h>
#include<stdlib.h>
#include<time.h>

enum eState
{
	IDLE,
	SENSING,
	PROCESSING
};

using namespace std;

class Machine
{
public:
	Machine();

	void idle();
	void sensing();
	float processing();
	eState state = IDLE;
	int temperature[30];
};




void Machine::idle()
{
	this->state = IDLE;
	cout << "System idle...\n";

}

void Machine::sensing()
{
	cout << "Sensing temperatures..\n";

	this->state = SENSING;

	for (int i = 0; i < 30; i++)
	{
		this->temperature[i] = rand() % 50;

		cout << this->temperature[i] << " ";

	}

	cout << "\n";
}

float Machine::processing()
{
	this->state = PROCESSING;
	cout << "Processing..\n";

	float average = 0.0f;

	for (int i = 0; i < 30; i++)
	{
		average += (float)this->temperature[i];


	}

	average /= 30.0f;

	return average;


}

Machine::Machine()
{
	cout << '\n';
}

int main()
{
	Machine fsm;

	int time = 0;
	int run = 0;
	float tempAverage;

	while (1)
	{
		switch (fsm.state)
		{
		case IDLE:
			fsm.idle();


		case SENSING:
			fsm.sensing();
			Sleep(1000);
			fsm.state = PROCESSING;
			break;


		case PROCESSING:
			fsm.processing();
			Sleep(1000);
			fsm.state = IDLE;
			break;
		}
		fsm.idle();

		fsm.sensing();

		tempAverage = fsm.processing();

		cout << "Average Temperature = " << tempAverage << "degree celcius\n";

		Sleep(1000);

		run++;


	}
}









