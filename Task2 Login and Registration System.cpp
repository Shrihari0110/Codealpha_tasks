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

    // Check if the username already exists
    ifstream readFile(username + ".txt");
    if (readFile) {
        cout << "Username already exists! Try another.\n";
        return;
    }

    // Save credentials to a file
    ofstream file(username + ".txt");
    file << username << endl << password;
    file.close();
    cout << "Registration successful!\n";
}

// Function to login a user
void loginUser() {
    string username, password, storedUsername, storedPassword;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Open the file and verify credentials
    ifstream file(username + ".txt");
    if (file) {
        getline(file, storedUsername);
        getline(file, storedPassword);
        file.close();

        if (username == storedUsername && password == storedPassword) {
            cout << "Login successful! Welcome, " << username << "!\n";
        } else {
            cout << "Invalid credentials! Try again.\n";
        }
    } else {
        cout << "User not found! Please register first.\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n1. Register\n2. Login\n3. Exit\nChoose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 3);

    return 0;
}

