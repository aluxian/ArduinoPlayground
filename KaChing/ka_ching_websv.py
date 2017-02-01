from bottle import route, run
import serial
import time

@route('/')
def index():
    try:
        ser = serial.Serial('/dev/ttyACM0', 9600)
	time.sleep(2)
        bytesNum = ser.write('c')
	print 'Wrote ' + str(bytesNum) + ' byte(s)'
    except:
	print "Could not write to serial"	 
    return 'ok'

run(host='0.0.0.0', port=8080)
