'''
prints mario tower to terminal
Derek Yee
'''

def main():
    # checks for a valid height input
    while True:
        height = input("Height: ")
        if isRightInt(height):
            break
    # makes mario tower
    for i in range(int(height)):
        for j in range(int(height) - i - 1):
            print(" ", end="")
        for j in range(i + 1):
            print("#", end="")
        print("  ", end="")
        for j in range(i + 1):
            print("#", end="")
        print("")
def isRightInt(number):
    accepted = "12345678"
    if number in accepted and len(number) != 0:
        return True
    else:
        return False
main()
