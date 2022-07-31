from tkinter import *

width = 500  # size of window is set
height = 500

colour = 'red'  # colour is initially set to red


def colourchange():
    global colour
    colour = 'green'
    window.update()


window = Tk()  # creates window
canvas = Canvas(window, width=width, height=height)  # creates canvas
canvas.create_arc(10, 10, width - 10, height - 10, fill=colour,
                  style=PIESLICE, extent=180, width=10)  # creates top shell of pokeball
canvas.create_arc(10, 10, width - 10, height - 10, fill='white', style=PIESLICE,
                  extent=180, width=10, start=180)  # creates bottom shell of pokeball

# creates button to switch colour of pokeball
colourButton = Button(window, text='Switch Colour', command=colourchange)
colourButton.pack()

canvas.pack()
window.mainloop()
