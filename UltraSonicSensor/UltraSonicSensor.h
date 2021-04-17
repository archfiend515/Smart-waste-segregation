#include<stdio.h>
#include<iostream>
#include<linux/i2c-dev.h>
#include<i2c/smbus.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/ioctl.h>
#include<sys/types.h>
#include<sys/stat.h>
using namespace std;
int USensorOp()
{
    printf("Ultrasonic Sensor Running");
    int file;
    string port = "/dev/i2c-1";                                         // I2C port
    file = open(port, O_RDWR);
    if (file < 0)
    {
        printf("failed to open port \n");
        exit(1);
    }
    int addr = 0x70;                                                    //Address of device
    if (ioctl(file, I2C_SLAVE, addr) < 0)
    {
        printf("unable to access device \n");
        exit(1);
    }
    char buff[10];

    while(1)
    {
    buff[0] = 0;                                                        // Software Version
    buff[1] = 81;                                                       // Distance in Centimeters, for inchs buff[1]=80

    if ((write(file, buff, 2)) != 2) {
        printf("unable to write to i2c device\n");
        exit(1);
    }

    usleep(1000000);                                                    // Command waits until there is an interupt                                      

    buff[0] = 0;

    if ((write(file, buff, 1)) != 1) {
        printf("unable to write to i2c device\n");
        exit(1);
    }

    if (read(file, buff, 4) != 4) {
        printf("unable to read from i2c device\n");
        exit(1);
    }
    else {
        char highByte = buff[2];                                         //Range Higher byte
        char lowByte = buff[3];                                          //Range lower byte
        int distance = highByte;
        distance <<= 8;                                                  //Left shift bitwise 8 times 
        distance = distance + lowByte;                                   //Total distance
        printf("Distance: %d\n", distance);
        return distance;
    }
}

    close(file);


    return distance;
}


