# hackupc2016
Starduino

Thingies needed :
- python
- sip
- Qt
- PyQt

How to use :

1st) update line 13 at filemonitor.py, as it holds an absolute path to the output file from Stellarium. You must find that file in your system and put there the path.

2nd) connect the Starduino to the pc and run the python script.

4rd) Run the Stellarium script (you can search for it and run it from F12 menu (scripting menu default shortcut)) with the last line uncommented to point the servos to (0,0). Now you must physically move starduino so the laser points to the North (use a compass). Comment again the line and proceed to step 5.

P.S. you can also copy the config.ini into Stellarium's folder and use the ctrl+K shortcut (cmd+K in OSX) to run the script.

5th) Choose a star and run the script, repeat anytime you want to.

6th) Enjoy!
