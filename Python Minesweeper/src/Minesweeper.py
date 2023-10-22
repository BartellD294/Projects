from tkinter import *
import random


class Minesweeper:

    def __init__(self, tk):
        self.tk = tk
        self.frame = tk.Frame(self.tk)
        self.frame.pack()


def main():

    root = Tk()
    root.title("Minesweeper")
    root.geometry("600x600")
    root.resizable(width=False, height=False)
    game = Minesweeper(root)
    root.mainloop()






