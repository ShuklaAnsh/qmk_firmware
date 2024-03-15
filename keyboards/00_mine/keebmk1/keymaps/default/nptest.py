import machine
import neopixel
from random import randint

data_pin = machine.Pin(4)
num_leds = 26
np = neopixel.NeoPixel(data_pin, num_leds)

for led in range(num_leds):
    np[led] = (randint(30, 180), randint(30, 180), randint(30, 180))
    np.write()

curr = 0


def next():
    global curr
    np[curr] = (randint(30, 180), randint(30, 180), randint(30, 180))
    curr = curr + 1
    np.write()
