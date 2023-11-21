import tkinter as tk

def main():
    root = tk.Tk()
    root.resizable(False, False)
    HEIGHT = int(root.winfo_screenheight()*(3/4))
    WIDTH = int(HEIGHT*(4/5))
    root.geometry(str(WIDTH)+"x"+str(HEIGHT))
    buttons = []
    inputs = tk.Frame(master=root, width=WIDTH, height=HEIGHT/5)
    inputs.place(x=0, y=0)
    btns = tk.Frame(master=root, width=WIDTH, height=HEIGHT*(4/5))
    btns.place(x=0, y=HEIGHT/5, width=WIDTH, height=HEIGHT*(4/5))
    for i in range (0,4):
        btns.grid_rowconfigure(index=i, weight=1, uniform=True)
        btns.grid_columnconfigure(index=i, weight=1, uniform=True)
    for i in range (0, 10):
        buttons.append(tk.Button(master=btns, width=100, height=100, text=(i+1)%10, command=num_command(buttons[i])))
        buttons[i].grid(row=int(i/3), column = (i%3), sticky = "NESW")
    plus = tk.Button(master = btns, text="+")
    plus.grid(row=0, column=3, sticky = "NESW")
    minus = tk.Button(master = btns, text="-")
    minus.grid(row=1, column=3, sticky = "NESW")
    mult = tk.Button(master = btns, text="*")
    mult.grid(row=2, column=3, sticky = "NESW")
    div = tk.Button(master=btns, text="/")
    div.grid(row=3, column = 3, sticky = "NESW")
    enter = tk.Button(master = btns, text="=")
    enter.grid(row=3, column=1, columnspan=2, sticky = "NESW")

def num_command():
    pass

    
        

#print_window = tk.Entry(master=root, width=WIDTH, height=HEIGHT/5)
    root.mainloop()

if __name__ == '__main__':
    main()