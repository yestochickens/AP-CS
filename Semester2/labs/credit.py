'''
Derek Yee
Deteremines what type of credit card you have
'''
def isInt(input):
    try:
        int(input)
        return True
    except:
        return False

def main():
    while True:
        credit = input("Credit Card #: ")
        if isInt(credit):
            break
    valid = False
    total = 0
    # reverses credit card #
    reverseCredit = credit[::-1]
    for i in range(0, len(str(credit)), 2):
        total += int(reverseCredit[i])
    for i in range(1, len(str(credit)), 2):
        addNumber = 2 * int(reverseCredit[i])
        for i in str(addNumber):
            total += int(i)
    if total % 10 == 0:
        valid = True
    if len(credit) == 16 and valid == True:
        if int(str(credit)[0]) == 4:
            print("VISA")
        elif int(str(credit)[0:2]) > 50 and int(str(credit)[0:2]) < 56:
            print("MASTERCARD")
        else:
            print("INVALID")
    elif len(credit) == 13 and valid == True:
        if int(str(credit)[0]) == 4:
            print("VISA")
        else:
            print("INVALID")
    elif len(credit) == 15 and valid == True:
        if int(str(credit)[0:2]) == 34 or int(str(credit)[0:2]) == 37:
            print("AMEX")
        else:
            print("INVALID")
    else:
        print("INVALID")
main()
