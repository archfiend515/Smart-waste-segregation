import os
from subprocess import call

call(['lxterminal', '-e', "python runultrasonic.py"])
call(['lxterminal', '-e', "python runcamera.py"])
call(['lxterminal', '-e', "python runmain.py"])