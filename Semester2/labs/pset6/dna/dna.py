'''
Derek Yee
from a sequence of DNA the program identifies who it belongs to based on DNA sequences' repitition
'''
from sys import argv, exit
import csv

def main():
    # checks that the datavase and sequence is submitted to check
    if len(argv) != 3:
        exit("requires 2 file inputs")
    # import sequence as string
    sequence = open(argv[2]).read()

    # opens data base and creates dictionary
    file = open(argv[1], "r")
    reader = csv.DictReader(file)
    substrings = reader.fieldnames[1:]
    for person in reader:
        # name of person we are checking
        name = person.get("name")
        matches = 0
        for subsequence in substrings:
            # checking if longest matches the person for the given substring
            if str(longest_match(sequence, subsequence)) == person.get(subsequence):
                matches += 1
        # if all substrings are a match then print the name
        if matches == len(substrings):
            print(name)
            exit()
    # if none of the people match the loop finishes and No match is printed
    print("No match")
    file.close()
def longest_match(sequence, subsequence):
    # find len of subsequence
    length = len(subsequence)
    # check if subsequence = sequence[0:len(subsequce)]
    index = 0
    values = []
    matches = 0
    while index < len(sequence):
        # if yes match + 1, shift over 1 subsequence
        if subsequence == sequence[index:index + length]:
            matches += 1
            index += length
        # if no append to list of all matches, reset match count to zero, shift over 1
        else:
            index += 1
            values.append(matches)
            matches = 0
    # return the max value of all the matches
    return max(values)


main()
