from tkinter import *
import random



class Minesweeper:

    flagCount = 0
    totalMines = 


    def __init__(self, tk):
        self.tk = tk
        self.frame = Frame(self.tk)
        self.frame.pack()

        self.label("")

    def startGame(self):
        self.build()

    def build(self):


def main():

    root = Tk()
    root.title("Minesweeper")
    root.geometry("600x600")
    root.resizable(width=False, height=False)
    game = Minesweeper(root)
    root.mainloop()

if __name__ == "__main__":
    main()