import tkinter as tk

intext = ""
def main():
    root = tk.Tk()
    root.resizable(False, False)
    HEIGHT = int(root.winfo_screenheight()*(1/2))
    WIDTH = int(HEIGHT*(4/5))
    root.geometry(str(WIDTH)+"x"+str(HEIGHT))
    buttons = []
    #inputs = tk.Frame(master=root, width=WIDTH, height=HEIGHT/5,bg = "grey")
    #inputs.place(x=0, y=0)
    global txt
    txt=tk.StringVar()

    inent = tk.Frame(root, bg="grey", width=WIDTH, height=HEIGHT/5,)#txt)
    inent.place(x=0, y=0, width=WIDTH, height=HEIGHT/5)
    inent.grid_rowconfigure(index=0, weight=1, uniform=True)
    inent.grid_columnconfigure(index=0, weight=1, uniform=True)
    ent = tk.Label(master=inent, width=20, height=9, textvariable=txt, bg="grey")
    ent.grid(row=0, column=0, columnspan=4, sticky="NESW")

    btns = tk.Frame(master=root, width=WIDTH, height=HEIGHT*(4/5))
    btns.place(x=0, y=HEIGHT/5, width=WIDTH, height=HEIGHT*(4/5))
    for i in range (0,4):
        btns.grid_rowconfigure(index=i, weight=1, uniform=True)
        btns.grid_columnconfigure(index=i, weight=1, uniform=True)
    for i in range (0, 10):
        newb = tk.Button(master=btns, width=100, height=100, text=(i+1)%10, command=lambda x = (i+1)%10:btn_command(x))
        buttons.append(newb)
        print(buttons[i])
        buttons[i].grid(row=int(i/3), column = (i%3), sticky = "NESW")
    plus = tk.Button(master = btns, text="+", command=lambda:btn_command("+"))
    plus.grid(row=0, column=3, sticky = "NESW")
    minus = tk.Button(master = btns, text="-", command=lambda:btn_command("-"))
    minus.grid(row=1, column=3, sticky = "NESW")
    mult = tk.Button(master = btns, text="*", command=lambda:btn_command("*"))
    mult.grid(row=2, column=3, sticky = "NESW")
    div = tk.Button(master=btns, text="/", command=lambda:btn_command("/"))
    div.grid(row=3, column = 3, sticky = "NESW")
    clear = tk.Button(master = btns, text="CLR", command=lambda:clear_command())
    clear.grid(row=3, column=1, sticky = "NESW")
    enter = tk.Button(master = btns, text="=", command=lambda:enter_command())
    enter.grid(row=3, column=2, sticky = "NESW")
    root.mainloop()

def btn_command(i):#, txt:tk.StringVar):
    global intext
    print(i)
    intext += str(i)
    txt.set(intext)
    
    
def enter_command():
    global intext
    intext = str(eval(str(intext)))
    txt.set(intext)
    intext = ""

def clear_command():
    global intext
    intext = ""
    txt.set(intext)

    
        

#print_window = tk.Entry(master=root, width=WIDTH, height=HEIGHT/5)


if __name__ == '__main__':
    main()