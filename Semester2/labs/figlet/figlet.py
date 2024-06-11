'''
Derek Yee
Prints words with figlet. No input prints random font, -f "font" and --font "font" prints out desired font
'''
from sys import argv, exit
import random
from pyfiglet import Figlet

figlet = Figlet()
# gets all fonts
fonts = figlet.getFonts()
# no input then random font
if len(argv) == 1:
    userFont = random.choice(fonts)
# checks for correct font syntax
elif len(argv) == 3:
    if argv[1] != "-f" and argv[1] != "font":
        print("Invalid usage")
        exit(1)
    if argv[2] in fonts:
        userFont = argv[2]
    else:
        print("Invalid usage")
        exit(1)
else:
    print("Invalid usage")
    exit(1)
userInput = input("Input: ")
figlet.setFont(font=userFont)
print(figlet.renderText(userInput))
