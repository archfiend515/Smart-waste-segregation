import os
from subprocess import call
import multiprocessing

#subprocess.run("g++ -o main main.cpp -lstdc++ -lpaho-mqttpp3 -lpaho-mqtt3as")
#subprocess.run("./main")

call("cd UltraSonicSensor; sudo pigpiod",shell=True)
call("cd UltraSonicSensor; sudo killall pigpiod",shell=True)
call("cd UltraSonicSensor; g++ -Wall -pthread -o UltraSonic UltraSonicSensor.cpp -lpigpio -lrt",shell=True)
call("cd UltraSonicSensor; sudo ./UltraSonic",shell=True)