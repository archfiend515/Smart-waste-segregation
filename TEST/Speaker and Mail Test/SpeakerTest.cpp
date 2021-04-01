//This is a simple code to test speaker and email generation

#include <iostream>
#include <wiringPi.h>
#include <stdlib.h>

using namespace std;

int main()
{
system("echo 'Please throw your garbage in the appropriate bin' | festival --tts");
cout << "Success" << endl;
system("echo 'Mail Check Successfull' | msmtp -a gmail karan.rajashekar@gmail.com");
    return 0;
}