import tkinter as tk

def open_window():
    win = tk.Toplevel(root)
    win.title("New Window")
    win.geometry("200x100")

    tk.Label(win, text="Hello from new window").pack(pady=10)

root = tk.Tk()
root.title("Main Window")

tk.Button(root, text="Open Window", command=open_window).pack(pady=20)

root.mainloop()
