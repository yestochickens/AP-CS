'''
Derek Yee
Predicts the age of a piece of writing based on the Coleman-Liau formula
'''


def main():
    # gets text input
    text = input("Text: ").strip()
    # counts sentences, words and letters
    sentences = sentenceCount(text)
    words = wordCount(text)
    letters = characterCount(text)
    # calculates based on Coleman-Liau formula
    index = 0.0588 * (letters * 100 / words) - 0.296 * (sentences * 100 / words) - 15.8
    if index > 16:
        print("Grade 16+")
    elif index < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {round(index)}")


def sentenceCount(input):
    sentenceCount = 0
    punctuations = ["?", "!", "."]
    for i in input:
        if i in punctuations:
            sentenceCount += 1
    return sentenceCount


def wordCount(input):
    # one more word than number of spaces in sentence
    wordCount = 1
    for i in input:
        if i == " ":
            wordCount += 1
    return wordCount


def characterCount(input):
    characterCount = 0
    for i in input:
        if i.isalpha():
            characterCount += 1
    return characterCount


main()
