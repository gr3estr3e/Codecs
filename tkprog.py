from tkinter import *
from tkinter import ttk

root=Tk()
root.title('Hello')
mainfrm=Frame(root)
mainfrm.grid(column=100,row=50)
ttk.Label(mainfrm,text='Hi').grid(column=7,row=0)
root.mainloop()
