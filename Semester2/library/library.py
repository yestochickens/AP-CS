import csv

from cs50 import SQL

db = SQL("sqlite:///library.db")

index = 1
with open("books.csv", "r") as file:
    reader = csv.DictReader(file)
    for book in reader:
        db.execute(f'''
                   INSERT INTO books (book_ID, ISBN, author, date, category)
                   VALUES (?, ?, ?, ?, ?)
                   ''',
                   index,
                   book["ISBN"],
                   book["Author"],
                   book["Publish Date"],
                   book["Genre"]
                   )
        index += 1

