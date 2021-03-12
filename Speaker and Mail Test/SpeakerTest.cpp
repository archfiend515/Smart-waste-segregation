#include <iostream>
#include <wiringPi.h>
#include <stdlib.h>

using namespace std;

int main()
{
system("echo 'Please throw your garbage in the appropriate bin' | festival --tts");
system("echo 'Please throw your garbage in the appropriate bin' | msmtp -a gmail karan.rajashekar@gmail.com");
    return 0;
}