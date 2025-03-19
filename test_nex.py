from nextion import Nextion, Button, Serial, Slider, Page


ser = Serial()
ser.read_ring_buffer()

b1 = Button(0,2,"b1")
b2 = Button(0,3,"b2")
h1 = Slider(0,5,"h1")
p0 = Page("page0")
p1 = Page("page1")
nex = Nextion()
nex.init()

b1.setText("Hallo")
b2.setText("Hi OtH")
b1.getText(5)
b2.getText(10)