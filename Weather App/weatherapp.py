import requests
import tkinter as tk

root = tk.Tk()
root.geometry("400x200")
root.title("Weather App")

def button_command():
        #city_entry = entry1.get()
        #print(city_entry)
        api = "http://api.weatherapi.com/v1/current.json?key=a31315c765234c6daf4163025232206&q="+entry1.get()+"&aqi=no"
        weather_result = requests.get(api).json()
        temp_f = weather_result['current']['temp_f']

        #print(weather_result)
        #print("The temperature is: ",temp_f,"° F",sep="")
        show_weather.config(text="The temperature is: "+str(temp_f)+"° F")

tk.Label(root, text="Enter city name (City, State):").pack()
city_entry = tk.StringVar()
entry1 = tk.Entry(root, textvariable=city_entry, width = 30)
entry1.pack()
tk.Button(root, text = "Enter", command=button_command).pack()

show_weather = tk.Label(root, text = "The temperature is:")
show_weather.pack()

root.mainloop()
