from PyQt4 import QtCore
from PyQt4 import QtGui
import sys
from time import sleep
import serial
ser = serial.Serial('/dev/cu.usbmodem1411', 9600) # Establish the connection on a specific port

app = QtGui.QApplication(sys.argv)

print('wirks')

###############   ATTENTION  ###############
#You MUST change the following line to your Stellarium output.txt file. Else IT WILL NOT WORK.
filepath = '/Users/marina/Library/Application Support/Stellarium/output.txt'
#############################################

#this gets called everytime the output file is changed, the script is monitoring the file in the background
@QtCore.pyqtSlot(str)
def file_changed(path):
    coordFile = open(filepath, 'r')
    line = coordFile.readline()
    print line
    ser.write(str(line))
    print ser.readline() # Read the newest output from the Arduino to check the connection went OK
    coordFile.close()
    sleep(.1) # Delay for one tenth of a second


fs_watcher = QtCore.QFileSystemWatcher([filepath])

fs_watcher.connect(fs_watcher, QtCore.SIGNAL('fileChanged(QString)'), file_changed)

app.exec_()
