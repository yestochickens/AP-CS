from cs50 import get_int

def greeting():
    name = input("What is your name? ")
    age = get_int("How old are you? ")
    color = input("What is your favorite color? ")

    return name, age, color

name, age, color = greeting()
print(f"Hi {name}. You are {age} years old and your favorite color is {color}")
