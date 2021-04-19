import os
from subprocess import call
import multiprocessing

#subprocess.run("g++ -o main main.cpp -lstdc++ -lpaho-mqttpp3 -lpaho-mqtt3as")
#subprocess.run("./main")
call("cd Face-Detection; g++ -o detectFace detectFace.cpp `pkg-config --cflags opencv4` `pkg-config --libs opencv4` -lstdc++ -lpaho-mqttpp3 -lpaho-mqtt3as -lpthread",shell=True)
call("cd Face-Detection;./detectFace",shell=True)
