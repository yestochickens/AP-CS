def main():
    plate = input("Plate: ")
    if is_valid(plate):
        print("Valid")
    else:
        print("Invalid")


def is_valid(s):
    input = []
    for i in s:
        try:
            input.append(int(i))
        except:
            input.append(i)
    # checks that first two characters are letters
    for i in input[0:2]:
        if type(i) == int:
            return False
    # checks for correct length
    if not(2 <=len(input) <= 6):
        return False
    # checks for only characters
    for i in input:
        if not(type(i) == int):
            if not(i.isalpha()):
                return False
    numbers = input[2:]
    index = []
    for i in range(len(numbers)):
        # find the index of the int in the plate
        if type(numbers[i]) == int:
            while type(numbers[i]) == int:
                index.append(i)
                if type(numbers[i]) == str or i >= len(numbers) - 1:
                    break
                i += 1
        # if the index has already been added it goes to the next line
        if not(len(index) == 0):
            break
    # checks that there were numbers in the plate, if not returns Valid
    if not(len(index) == 0):
        if numbers[min(index)] == 0:
            return False
        # checks that objects around int are not both strings
        if max(index) + 2 < len(numbers):
            if type(numbers[min(index) + 1]) == str and type(numbers[max(index) + 3]) == str:
                return False
        else:
            return True
    else:
        return True

main()
