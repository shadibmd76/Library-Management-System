#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const string FILE_NAME = "books.txt";

void addBook() {
    int id;
    string title, author;

    cout << "\nEnter book ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter book title: ";
    getline(cin, title);

    cout << "Enter author name: ";
    getline(cin, author);

    ofstream file(FILE_NAME, ios::app);
    if (!file) {
        cout << "Error: Could not open books.txt\n";
        return;
    }

    file << id << "|" << title << "|" << author << "|Available\n";
    file.close();

    cout << "Book added successfully!\n";
}

void viewBooks() {
    ifstream file(FILE_NAME);
    if (!file) {
        cout << "\nNo book data found yet.\n";
        return;
    }

    string line;
    cout << "\n----- BOOK LIST -----\n";
    bool found = false;

    while (getline(file, line)) {
        cout << line << '\n';
        found = true;
    }

    if (!found) {
        cout << "No books available.\n";
    }
    file.close();
}

void searchBook() {
    int searchID;
    cout << "\nEnter book ID to search: ";
    cin >> searchID;

    ifstream file(FILE_NAME);
    if (!file) {
        cout << "No book data found.\n";
        return;
    }

    string line;
    bool found = false;

    while (getline(file, line)) {
        size_t firstSeparator = line.find('|');
        if (firstSeparator != string::npos) {
            int id = stoi(line.substr(0, firstSeparator));
            if (id == searchID) {
                cout << "\nBook found:\n" << line << '\n';
                found = true;
                break;
            }
        }
    }

    if (!found) {
        cout << "Book not found.\n";
    }
    file.close();
}

void issueBook() {
    int searchID;
    cout << "\nEnter book ID to issue: ";
    cin >> searchID;

    ifstream input(FILE_NAME);
    if (!input) {
        cout << "No book data found.\n";
        return;
    }

    ofstream output("temp.txt");
    string line;
    bool found = false;

    while (getline(input, line)) {
        size_t first = line.find('|');
        size_t last = line.rfind('|');

        if (first != string::npos && last != string::npos && first != last) {
            int id = stoi(line.substr(0, first));
            if (id == searchID) {
                found = true;
                string status = line.substr(last + 1);
                if (status == "Available") {
                    line.replace(last + 1, string::npos, "Issued");
                } else {
                    cout << "This book is already issued.\n";
                }
            }
        }
        output << line << '\n';
    }

    input.close();
    output.close();

    remove(FILE_NAME.c_str());
    rename("temp.txt", FILE_NAME.c_str());

    if (found) {
        cout << "Issue operation completed. Check the book status.\n";
    } else {
        cout << "Book not found.\n";
    }
}

void returnBook() {
    int searchID;
    cout << "\nEnter book ID to return: ";
    cin >> searchID;

    ifstream input(FILE_NAME);
    if (!input) {
        cout << "No book data found.\n";
        return;
    }

    ofstream output("temp.txt");
    string line;
    bool found = false;

    while (getline(input, line)) {
        size_t first = line.find('|');
        size_t last = line.rfind('|');

        if (first != string::npos && last != string::npos && first != last) {
            int id = stoi(line.substr(0, first));
            if (id == searchID) {
                found = true;
                string status = line.substr(last + 1);
                if (status == "Issued") {
                    line.replace(last + 1, string::npos, "Available");
                } else {
                    cout << "This book was not issued.\n";
                }
            }
        }
        output << line << '\n';
    }

    input.close();
    output.close();

    remove(FILE_NAME.c_str());
    rename("temp.txt", FILE_NAME.c_str());

    if (found) {
        cout << "Return operation completed. Check the book status.\n";
    } else {
        cout << "Book not found.\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. View All Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 0: cout << "Thank you for using the system!\n"; break;
            default: cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
