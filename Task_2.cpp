        /*              Login And Registration System               */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to register a user
void registerUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Check if username already exists
    ifstream readFile("users.txt");
    string fileUser, filePass;
    bool exists = false;

    while (readFile >> fileUser >> filePass) {
        if (fileUser == username) {
            exists = true;
            break;
        }
    }
    readFile.close();

    if (exists) {
        cout << "Username already exists. Try a different one.\n";
        return;
    }

    // Save new user
    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();
    cout << "Registration successful!\n";
}

// Function to login a user
void loginUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    string fileUser, filePass;
    bool found = false;

    while (file >> fileUser >> filePass) {
        if (fileUser == username && filePass == password) {
            found = true;
            break;
        }
    }
    file.close();

    if (found) {
        cout << "Login successful! Welcome, " << username << "!\n";
    } else {
        cout << "Invalid credentials. Please try again.\n";
    }
}

int main() {
    int choice;
    cout << "====== LOGIN SYSTEM ======\n";
    cout << "1. Register\n2. Login\nEnter your choice: ";
    cin >> choice;

    if (choice == 1) {
        registerUser();
    } else if (choice == 2) {
        loginUser();
    } else {
        cout << "Invalid choice.\n";
    }

    return 0;
}
