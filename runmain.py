import os
from subprocess import call
import multiprocessing

#subprocess.run("g++ -o main main.cpp -lstdc++ -lpaho-mqttpp3 -lpaho-mqtt3as")
#subprocess.run("./main")

call("g++ -o main main.cpp -lstdc++ -lpaho-mqttpp3 -lpaho-mqtt3as",shell=True)
call("./main",shell=True)
