#include "opencv4/opencv2/objdetect.hpp"
#include "opencv4/opencv2/highgui.hpp"
#include "opencv4/opencv2/imgproc.hpp"
#include "opencv4/opencv2/videoio.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>
#include <thread>
#include <atomic>
#include <chrono>
#include <cstring>
using namespace std;
 
using namespace cv;
CascadeClassifier face_cascade;
void display( Mat frame );
int state=0;
int counter =0;
time_t lt = time(NULL);
 double seconds;
int main( int argc, const char** argv )
{

	 if (!face_cascade.load("/home/pi/opencv/data/haarcascades/haarcascade_frontalface_default.xml")) {
        std::cerr << "ERROR! Could not load cascade file\n";
    }
    

       // create video stream instance and set the resolution (if not set then maximum available is used)
	cv::VideoCapture capture(0);
    capture.set(cv::CAP_PROP_FRAME_WIDTH, 320);
    capture.set(cv::CAP_PROP_FRAME_HEIGHT, 240);
    capture.set(cv::CAP_PROP_FPS, 5);
    if ( ! capture.isOpened() )
    {
        cout << "--(!)Error opening video capture\n";
        return -1;
    }
    Mat frame;
    while ( capture.read(frame) )
    {
        if( frame.empty() )
        {
            cout << "--(!) No captured frame -- Break!\n";
            break;
        }
        
        //-- displayFrame
        display( frame );
        if( waitKey(10) == 27 )
        {
            break; // escape
        }
    }
    return 0;
}

void display( Mat frame )
{
    Mat frame_gray;
    cvtColor( frame, frame_gray, COLOR_BGR2GRAY );
    equalizeHist( frame_gray, frame_gray );
    
    //-- Show what you got
    cv::imshow( "Capture - Face detection", frame );
}

