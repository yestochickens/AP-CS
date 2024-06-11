def main():
    time = convert(input("What time is it? "))
    if 7 <= time <= 8:
        print("breakfast time")
    if 12 <= time <= 13:
        print("lunch time")
    if 18 <= time <= 19:
        print("dinner time")

def convert(time):
    hour, minute = time.split(":")
    return int(hour) + int(minute)/60


if __name__ == "__main__":
    main()
