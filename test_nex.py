from nextion import Nextion, Button, Serial, Slider, Page
import _thread

# Initialize components
b1 = Button(0, 2, "b1")
back_button = Button(1, 3, "b0")
b2 = Button(0, 3, "b2")
h1 = Slider(0, 5, "h1")
p0 = Page("page0")
p1 = Page("page1")
nex = Nextion()
nex.init()

def next_page():
    print("hello")
    p1.show()

# Attach callback
nex.attachPush(b1, next_page)

# Function to run in thread
def run_nex_loop():
    nex.nexLoop([b1, b2])

# Start the nexLoop in a new thread
_thread.start_new_thread(run_nex_loop, ())