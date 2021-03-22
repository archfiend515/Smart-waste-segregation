#include<stdio.h>
#include<iostream>
#include<linux/i2c-dev.h>
#include<i2c/smbus.h>
#include<unistd.h>
using namespace std;
int main()
{
	int file;
	string port = "/dev/i2c-1";
	file = open(port, O_RDWR);
	if (file < 0)
	{
		printf("failed to open port \n");
		exit(1);
	}
	int addr = 0x70;
	if (ioctl(file, I2C_SLAVE, addr) < 0)
	{
		printf("unable to access device \n");
		exit(1);
	}
	char buff[10];
}