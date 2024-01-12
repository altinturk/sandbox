import pandas as pd

# data = {
#   "calories": [420, 380, 390],
#   "duration": [50, 40, 45]
# }
#load data into a DataFrame object:
## df = pd.DataFrame(data)
# print(df) 


# df = pd.DataFrame(data, index = ["day1", "day2", "day3"])
# #refer to the named index:
# print(df.loc["day2"]) 

# Load the JSON file into a DataFrame:
# df = pd.read_json('data.json')
# print(df.to_string())

# Load a Python Dictionary into a DataFrame:
data = {
  "Duration":{
    "0":60,
    "1":60,
    "2":60,
    "3":45,
    "4":45,
    "5":60
  },
  "Pulse":{
    "0":110,
    "1":117,
    "2":103,
    "3":109,
    "4":117,
    "5":102
  },
  "Maxpulse":{
    "0":130,
    "1":145,
    "2":135,
    "3":175,
    "4":148,
    "5":127
  },
  "Calories":{
    "0":409,
    "1":479,
    "2":340,
    "3":282,
    "4":406,
    "5":300
  }
}


df = pd.DataFrame(data)

print(df)  