#include <iostream>
#include <string>
using namespace std;

struct Book {
    int id;
    string name;
};

Book b[100];
int count = 0;

// Add Book
void addBook() {
    cout << "Enter Book ID: ";
    cin >> b[count].id;
    cout << "Enter Book Name: ";
    cin.ignore();
    getline(cin, b[count].name);
    count++;
    cout << "Book Added Successfully!\n";
}

// Display Books
void displayBooks() {
    if(count == 0) {
        cout << "No books available\n";
        return;
    }
    for(int i = 0; i < count; i++) {
        cout << "ID: " << b[i].id << ", Name: " << b[i].name << endl;
    }
}

// Search Book
void searchBook() {
    int id, found = 0;
    cout << "Enter Book ID to search: ";
    cin >> id;

    for(int i = 0; i < count; i++) {
        if(b[i].id == id) {
            cout << "Book Found: " << b[i].name << endl;
            found = 1;
        }
    }
    if(!found) cout << "Book Not Found\n";
}

// Delete Book
void deleteBook() {
    int id;
    cout << "Enter Book ID to delete: ";
    cin >> id;

    for(int i = 0; i < count; i++) {
        if(b[i].id == id) {
            for(int j = i; j < count-1; j++) {
                b[j] = b[j+1];
            }
            count--;
            cout << "Book Deleted\n";
            return;
        }
    }
    cout << "Book Not Found\n";
}

int main() {
    int choice;

    while(true) {
        cout << "\n1.Add Book\n2.Display\n3.Search\n4.Delete\n5.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: deleteBook(); break;
            case 5: return 0;
            default: cout << "Invalid choice\n";
        }
    }
}