import os
from subprocess import call

call(['lxterminal', '-e', "python parallelrun2.py"])
call(['lxterminal', '-e', "python parallelrun1.py"])
call(['lxterminal', '-e', "python parallelrun3.py"])