import requests # type: ignore



apikey = "11f7b1c9dc187b9124d1bdf1259b3abf"
city = input("City: ")


print("0")

def weather_get(city, api_key):


    url = "https://api.openweathermap.org/data/2.5/weather"

    params = {
        "q": city,
        "appid": api_key,
        "units": "metric"
    }

    response = requests.get(url, params=params)
    data = response.json()

    print(data)
    if data["cod"] == 200:
        temp = data["main"]["temp"]
        humidity = data["main"]["humidity"]
        description = data["weather"][0]["description"]
        Country = data["sys"]["country"]

        print(f"Temperature: {temp}°C")
        print(f"Humidity: {humidity}%")
        print(f"Condition: {description}")
        print(f"country: {Country}")

    else:
        print("City not found")

weather_get(city, apikey)

print("0")