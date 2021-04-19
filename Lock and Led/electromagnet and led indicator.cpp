#include <pigpio.h>

#define LED 4
#define lock 26
#define HIGH 0x1
#define LOW 0x0
int main()
{
	if (gpioInitialise() < 0) exit(1);
	int distance;
	gpioSetMode(LED, PI_OUTPUT);
	gpioSetMode(lock, PI_OUTPUT);
	
	distance = 10;
	if (distance > 1)
	{
		gpioWrite(LED, HIGH);
		gpioWrite(lock, LOW);
	}
	else
	{
		gpioWrite(LED, LOW);
		gpioWrite(lock, HIGH); 

	}
	gpioTerminate();
}