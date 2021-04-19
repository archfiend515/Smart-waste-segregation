#include<wiringpi.h>
int main()
{
	int led = 4;
	int lock = 26;
	wiringPiSetup();
	pinMode(led, OUTPUT);
	if (distance > 1)
	{
		digitalWrite(led, HIGH);
		digitalWrite(lock, LOW);
	}
	else
	{
		digitalWrite(led, LOW);
		digitalWrite(lock, HIGH);

	}

}