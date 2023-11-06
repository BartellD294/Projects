import tkinter as tk


app_title = "Wordle-Klon"  # Appens titel.
app_font = ("Arial", 20)  # Applikation-vid typsnitt.
app_background_color = "yellow"  # Bakgrundsfärg för appen.


class App(tk.Tk):
    def __init__(self):
        super().__init__()
        self.geometry('500x500')
        tk.Label(text=app_title, anchor="c", pady=20, font=app_font, bg='yellow', fg="black").pack()
        self.letterFrame = tk.Frame(self, bg="Blue")
        self.letterFrame.pack(fill="both", expand=True, padx=20, pady=20)
        self.label_list = []
        self.number_of_columns = 5
        self.number_of_labels = 25
        self.createLetterSquares()

    def createLetterSquares(self):
        row = 0
        col = 0
        for i in range(self.number_of_labels):
            self.letterFrame.grid_columnconfigure(col, weight=1, uniform="True")
            self.letterFrame.grid_rowconfigure(row, weight=1, uniform="True")
            lbl = tk.Label(self.letterFrame, text=f"({row+1}, {col+1})", bg="red", padx=10, pady=10)
            self.label_list.append([lbl, row, col])
            self.label_list[-1][0].grid(row=row, column=col, sticky=tk.NSEW)
            col += 1
            if col == self.number_of_columns:
                col = 0
                row += 1
        print(self.label_list)


if __name__ == "__main__":
    app = App()  # Skapa ett app objekt.
    app.mainloop()  # Loopa appen.