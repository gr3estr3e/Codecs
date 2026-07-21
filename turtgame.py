from turtle import *
from tkinter import messagebox
root=Screen()
payer=Turtle()
payer.shape('arrow')
payer.color('black')
root.bgcolor('white')
def fwd():
    payer.fd(10)
def bwd():
    payer.bk(10)
def rgt():
    payer.rt(5)
def lft():
    payer.lt(5)
listen()
onkey(fwd,'Up')
onkey(bwd,'Down')
onkey(rgt,'Right')
onkey(lft,'Left')
root.mainloop()
