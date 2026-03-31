import tkinter as tk
import requests # type: ignore


apikey = "11f7b1c9dc187b9124d1bdf1259b3abf"
#functions


def weather(city, api_key):
    url = "https://api.openweathermap.org/data/2.5/weather"

    params = {
        "q": city,
        "appid": api_key,
        "units": "metric"
    }

    response = requests.get(url, params=params)
    data = response.json()

    if data["cod"] == 200:

        return {
            "temp": data["main"]["temp"],
            "humidity": data["main"]["humidity"],
            "description": data["weather"][0]["description"],
        }

    else:
        return("404")


def show_text(a1):
    print(a1.get())


def change_label(a1):
    a1.config(text="New text")


def open_window():
    win = tk.Toplevel(root)
    win.title("New Window")
    win.geometry("200x100")

    data = weather(text_var.get(),apikey)
    tk.Label(win, text="Weather of:").grid(row=0)
    tk.Label(win, text=text_var.get()).grid(row=0, column=1)
    tk.Label(win, text="temp").grid(row=1)
    tk.Label(win, text=f"{data['temp']} C").grid(row=1, column=1)
    tk.Label(win, text="humidity").grid(row=2)
    tk.Label(win, text=data["humidity"]).grid(row=2, column=1)
    tk.Label(win, text="description").grid(row=3)
    tk.Label(win, text=data["description"]).grid(row=3, column=1)




root = tk.Tk()

#windows
root.geometry("300x300")
root.maxsize(300, 300)
root.minsize(100, 100)
root.title("Weather app")

#Starting Var
text_var = tk.StringVar()

tk.Label(root, text="Weather checker for you!").pack()
entry = tk.Entry(root, textvariable=text_var)
entry.pack()
tk.Button(root, text="Print", command=open_window).pack()




root.mainloop()
