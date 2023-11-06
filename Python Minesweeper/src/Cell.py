import tkinter as tk
import Minesweeper

class Cell:
    is_mine=False
    all_cells=[]
    def __init__(self, root, w, h,x,y, text="", is_mine = False):
        self.is_mine = is_mine
        self.x = x
        self.y = y
        self.is_revealed = False
        Cell.all_cells.append(self)
        self.btn = self.create_btn(root, w, h, text)
    
    def create_btn(self, root, w, h, text):
        btn  = tk.Button(root, width=w, height=h, text=text,bg="gray40")#, width=str(5), height=str(int(h)))
        btn.bind('<Button-1>', self.l_click)
        btn.bind('<Button-3>', self.r_click)
        return(btn)
    
    def change_text(self, text):
        self.btn.config(text=text)

    def set_mine(self):
        self.is_mine=True
        self.btn.config(text="MINE", bg="RED")
        
    def reveal(self):
        self.is_revealed=True
        self.btn.config(bg="grey80")
        num=0
        if (self.is_mine):
            Minesweeper.game_over()
        else:
            cels = [
                Cell.get_cell(self.x-1, self.y-1),
                Cell.get_cell(self.x-1, self.y),
                Cell.get_cell(self.x-1, self.y+1),     
                Cell.get_cell(self.x, self.y-1),
                Cell.get_cell(self.x, self.y+1),
                Cell.get_cell(self.x+1, self.y-1),
                Cell.get_cell(self.x+1, self.y),
                Cell.get_cell(self.x+1, self.y+1)
            ]
            cels = [cell for cell in cels if cell is not None]
        
            for i in range (len(cels)): 
                if cels[i].is_mine==True:
                    num+=1
            self.btn.config(text=num)
                    

    def get_cell(x,y):
        for c in Cell.all_cells:
            if c.y == y and c.x==x:
                return c



    def reveal_adjacent(self):
        for i in range (0,8):
            self.b += 1
    
    def l_click(self, event):
        print(event, "left click")
        print(self.is_revealed)
        if (self.is_revealed==False):
            self.reveal()

    def r_click(self, event):
        print(event, "right click")