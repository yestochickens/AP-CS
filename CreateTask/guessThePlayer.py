import random
from termcolor import cprint
import csv


def main():

    # Gets all players from NBA CSV table who played in 2023.
    # Link to database: https://www.kaggle.com/datasets/wyattowalsh/basketball
    players = []
    with open("players.csv", "r") as file:
        reader = csv.DictReader(file)
        for line in reader:
            if line['rosterstatus'] == 'Active':
                players.append(line)

    # cleans data to only have one primary position. Example Forward-Center --> Forward
    for player in players:
        newPosition = player['position'].split("-")[0]
        player['position'] = newPosition
    # chooses random player from the list
    answer = players[random.randint(0, len(players)+1)]

    # gives the player 6 tries to guess the player
    for i in range(6):
        # validates that they guessed a valid NBA player
        guess = input(str(i+1) + ". NBA Player: ")
        while not isValidPlayer(guess, players):
            print("Not a Valid NBA Player")
            guess = input("NBA Player: ")
        # gets the ID of the guessed player
        guessID = getID(guess, players)
        # check if they won
        if checkPlayer(guessID, answer, players):
            print(f"You did it in {i+1} guesses")
            return 0
    print(f"You lose. The answer is {answer['display_first_last']}")


def checkPlayer(guessID, answer, players):
    # checks if guess is the correct player
    if players[guessID]['display_first_last'].lower() == answer['display_first_last'].lower():
        print("You Win!")
        return True
    else:
        print(players[guessID]['display_first_last'], end=" ")

    # turns height into inches so it can compare
    guessHeight = (int(players[guessID]['height'].split("-")[0]) * 12) + int(players[guessID]['height'].split("-")[1])
    answerHeight = int(answer['height'].split("-")[0]) * 12 + int(answer['height'].split("-")[1])
    # compares height and prints respective clue
    cprint(players[guessID]['height'] + checkStat(guessHeight, answerHeight, 2)
           [1], checkStat(guessHeight, answerHeight, 2)[0], end=" ")

    guessWeight = int(players[guessID]['weight'])
    answerWeight = int(answer['weight'])
    # compares weight
    cprint(players[guessID]['weight'] + checkStat(guessWeight, answerWeight, 20)
           [1], checkStat(guessWeight, answerWeight, 20)[0], end=" ")

    # if positions are the same then it prints position in green
    if players[guessID]['position'] == answer['position']:
        cprint(players[guessID]['position'], "green", end=" ")
    # otherwise prints position in white
    else:
        print(players[guessID]['position'], end=" ")

    # compares year started
    guessStartYear = int(float(players[guessID]['from_year']))
    answerStartYear = int(float(answer['from_year']))
    cprint(players[guessID]['from_year'] + checkStat(guessStartYear, answerStartYear, 2)
           [1], checkStat(guessStartYear, answerStartYear, 2)[0], end=" ")

    # compares current team
    conferences = [
        ["Celtics", "Knicks", "76ers", "Nets", "Raptors"],
        ["Bucks", "Cavaliers", "Pacers", "Bulls", "Pistons"],
        ["Magic", "Heat", "Hawks", "Hornets", "Wizards"],
        ["Thunder", "Nuggets", "Timberwolves", "Jazz", "Trail Blazers"],
        ["Clippers", "Suns", "Kings", "Lakers", "Warriors"],
        ["Pelicans", "Mavericks", "Rockets", "Grizzlies", "Spurs"]
    ]
    guessTeam = players[guessID]['team_name']
    answerTeam = answer['team_name']
    # if the teams are the same the team prints in green
    if guessTeam == answerTeam:
        cprint(guessTeam, "green")
        # exits function
        return False
    else:
        # checks if the guessTeam and answerTeam is in the same conference, if so it prints yellow
        for conference in conferences:
            if guessTeam in conference and answerTeam in conference:
                cprint(guessTeam, "yellow")
                # exits function
                return False
    # if not same team or conference it just prints the team
    print(guessTeam)


def isValidPlayer(guess, players):
    for player in players:
        if player['display_first_last'].lower() == guess.lower():
            return True
    else:
        return False


def getID(guess, players):
    for i in range(len(players)):
        if players[i]['display_first_last'].lower() == guess.lower():
            return i


def checkStat(guess, answer, error):
    # if guess is the same as anwser return green
    if guess == answer:
        return "green", ""
    # if guess within answer by error then return yellow, and higher or lower
    elif (guess) <= answer <= (guess+error):
        return "yellow", "⬆️ "
    elif (guess-error) <= answer <= (guess):
        return "yellow", "⬇️ "
    # if not within error range return white with higher or lower
    elif guess > answer:
        return "white", "⬇️ "
    else:
        return "white", "⬆️ "


main()
