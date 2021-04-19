
# Smart-Waste-Segregation


![alt text](https://assets.telegraphindia.com/telegraph/9ca10d94-d495-48ec-be03-09186c3158aa.jpg)

## About the project

We have seen a substantial growth in the amount of waste generated day by day. Recycling is the only way to reduce the amount of waste generated for the recycling to done it is important tht first the waste must be segregated first because recycling process differs.
In order to do that it is important to educate the user For this purpose we design a garbage disposal system that uses multiple dustbins. Face detection is done by the camera interface and with a voice based system that speaks to the user each time he or she stands before the dustbin.
Using ultrasonic sensor we detect the levels of the bin which is mounted inside the bin. As soon as the level of bin is full a  message is directed over the internet to empty the bin.

## Hardware Used

1. Raspberry pi 4.
2. Pi camera.
3. SRF-02 Ultrasonic sensor.
4. Electromagnetic Lock
5. LED's.

### Getting Started

## Software Setup

 1. https://maker.pro/raspberry-pi/projects/  how-to-connect-a-raspberry-pi-to-a-laptop-display - For Connecting to Pi from your Laptop 

 2. https://qengineering.eu/install-opencv-4.4-on-raspberry-pi-4.html - Follow the steps in this link for installing OpenCV 4. (Virtual Environment part is not required for c++) 

 3. https://www.youtube.com/watch?v=dbBWyeHbGs0 – Follow this video to enable VNC viewer to see camera preview ( For VNC users only) 

## Installing Dependencies

INSTALLING DEPENDENCIES: 

 1. $ sudo apt-get update 

 2. $ sudo apt-get upgrade 

 3. $ sudo apt-get install alsa-utils ( For installing alsa sound utilities) 

 4. $ sudo nano /etc/modules (Execute this and add line snd_bcm2835) 

 5. $ sudo apt-get install mplayer 

 6. $ sudo apt-get install espeak-ng ( For Text to Speech) 

 7. $ sudo apt-get install msmtp (msmtp package for mail communication) 

 8. $ sudo apt-get install msmtp-mta ( Add your email id and password in .msmptrc file) 

 9. $ sudo apt-get install build-essential gcc make cmake cmake-gui cmake-curses-gui 

 10. $ sudo apt-get install libssl-dev 

 11. $ sudo apt-get install doxygen graphviz (For installing doxygen and graphviz) 

## Build And Install MQTT Library

We are using Eclipse Paho MQTT CPP library for async communication between the Camera and the Speaker. 

Before building the C++ library, build and install the Paho MQTT C library. Note, this version of the C++ library requires Paho C v1.3.8 or greater. 

 1. $ git clone https://github.com/eclipse/paho.mqtt.c.git 

 2. $ cd paho.mqtt.c 

 3. $ git checkout v1.3.8 

 4. $ cmake -Bbuild -H. -DPAHO_ENABLE_TESTING =OFF -DPAHO_BUILD_STATIC=ON -\DPAHO_WITH_SSL=ON -DPAHO_HIGH_PERFORMANCE=ON 

 5. $ sudo cmake --build build/ --target install 

 6. $ sudo ldconfig 

# Building the Paho C++ library
 
 1. $ git clone https://github.com/eclipse/paho.mqtt.cpp 

 2. $ cd paho.mqtt.cpp 

 3. $ cmake -Bbuild -H. -DPAHO_ENABLE_TESTING=OFF -DPAHO_BUILD_STATIC=ON \-DPAHO_BUILD_DOCUMENTATION=TRUE -DPAHO_HIGH_PERFORMANCE=ON 

 4. $ sudo cmake --build build/ --target install 

 5. $ sudo ldconfig


## Circuit Diagram
![circuit diagram](https://user-images.githubusercontent.com/41875477/115230062-bf3b9f80-a10b-11eb-9585-4cddc4697b9d.png)


## References

# MQTT
1. https://github.com/eclipse/paho.mqtt.cpp 
2. http://www.steves-internet-guide.com/mqtt/ 

# Open CV/Face Detection
1. https://docs.opencv.org/4.5.1/db/d28/tutorial_cascade_classifier.html 
2. https://docs.opencv.org/3.4/d4/d26/samples_2cpp_2facedetect_8cpp-example.html#_a2 
3. https://www.rs-online.com/designspark/beginners-guide-to-computer-vision-with-raspberry-pi-4 

# others
1. https://www.raspberrypi.org/
2. https://www.kernel.org/doc/Documentation/i2c/dev-interface
3. https://github.com/espeak-ng/espeak-ng 
4. https://wiki.archlinux.org/index.php/Msmtp 
5. https://www.gnu.org/software/libc/manual/html_node/ Termination-Signals.html 

##                                                                   Social Media Profiles
[![github](https://user-images.githubusercontent.com/41875477/115228747-10e32a80-a10a-11eb-828e-b4150430b2b5.png)][1] [![github](https://user-images.githubusercontent.com/41875477/115229474-01b0ac80-a10b-11eb-8a55-381cee2859ed.png)][2]

## Contributors

1. Aswin Subramanian Manickavasagam -2596691M@student.gla.ac.uk,
2. Akhil Bommireddypalli -2584567B@student.gla.ac.uk,
3. Karan Rajashekar -2584618R@student.gla.ac.uk.


 
[1]: https://www.instagram.com/smart_waste_segregation/
[2]: https://www.facebook.com/SmartWasteSegregation/
