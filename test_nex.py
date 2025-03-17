from nextion import Nextion, Button, Serial

# btn = Button(0,2,"b1")
# nex = Nextion()
# nex.init()

ser = Serial();
ser.send("habe die ehre\n")
#value = ser.rcv()
#print("value : ",value)