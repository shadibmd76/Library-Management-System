# Library Management System (C++ / OS Lab Project)

## Project purpose
This is a beginner-friendly, menu-driven C++ project. It demonstrates how a small library can manage book records using a text file.

## Features
1. Add a new book
2. View all books
3. Search a book by ID
4. Issue a book
5. Return a book
0. Exit

## Files
- `main.cpp` — complete C++ source code
- `books.txt` — sample book records; the program updates this file
- `run.sh` — compiles and runs the program on Linux/Unix
- `README.md` — project guide

## How it works (simple explanation)
- The user selects an option from the menu.
- C++ reads the choice and runs the matching function.
- Book records are stored permanently in `books.txt`.
- When a book is issued, its status changes from `Available` to `Issued`.
- When it is returned, its status changes back to `Available`.
- A temporary file (`temp.txt`) is used while updating a record safely.

Each line in `books.txt` follows this format:

`BookID|Title|Author|Status`

Example:

`101|Operating System Concepts|Silberschatz|Available`

## Run on Linux / Unix
Open a terminal in this project folder and run:

```bash
chmod +x run.sh
./run.sh
```

You can also compile manually:

```bash
g++ -std=c++11 main.cpp -o library
./library
```

## Sample run
```text
===== LIBRARY MANAGEMENT SYSTEM =====
1. Add Book
2. View All Books
3. Search Book
4. Issue Book
5. Return Book
0. Exit
Enter your choice: 2

----- BOOK LIST -----
101|Operating System Concepts|Silberschatz|Available
102|Object Oriented Programming|Robert Lafore|Available
103|Database System Concepts|Korth|Issued
```

## OS concepts demonstrated
- File handling: persistent storage in a file
- Process execution: compile and run using a Unix shell script
- Command-line interface: terminal-based interaction
- Basic data management: reading and updating records

## Notes
- Keep `main.cpp`, `books.txt`, and `run.sh` in the same folder.
- The program uses a simple text-file format for learning purposes, not a production database.
- If you want a clean starting list, edit `books.txt` and keep one record per line.
