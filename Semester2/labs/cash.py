def isFloat(input):
    possibilities = ".1234567890"
    if input != "":
        for i in input:
            if i in possibilities:
                continue
            else:
                return False
        if input.count(".") < 2:
            return True
    return False

def main():
    # checks for numerical input
    while True:
        amount = input("Change owed: ")
        if isFloat(amount):
            break
    amount = float(amount)
    coins = 0
    while amount >= 0.25:
        amount -= 0.25
        coins += 1
    amount = round(amount, 2)
    while amount >= 0.10:
        amount -= 0.1
        coins += 1
    amount = round(amount, 2)
    while amount >= 0.05:
        amount -= 0.05
        coins += 1
    amount = round(amount, 2)
    while amount >= 0.01:
        amount -= 0.01
        coins += 1
    print(coins)
main()
