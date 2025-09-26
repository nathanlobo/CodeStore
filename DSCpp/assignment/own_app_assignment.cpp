
#include <iostream>   // For input/output operations
#include <fstream>    // For file handling
#include <vector>     // For using vector container
#include <sstream>    // For string stream operations
#include <iomanip>    // For output formatting
using namespace std;


// Struct to hold expense data (date, category, and amount)
struct Expense {
    string date;      // Date of the expense
    string category;  // Category of the expense
    double amount;    // Amount spent
};


// File name where expenses are stored
const string EXPENSE_FILE = "expenses.txt";


// Loads all expenses from the file into the expenses vector
void loadExpenses(vector<Expense>& expenses) {
    ifstream file(EXPENSE_FILE); // Open the file for reading
    if (!file) return;           // If file doesn't exist, return

    string line;
    while (getline(file, line)) {      // Read each line from the file
        stringstream ss(line);         // Create a stringstream for parsing
        Expense e;
        getline(ss, e.date, ',');      // Extract date (up to comma)
        getline(ss, e.category, ',');  // Extract category (up to comma)
        ss >> e.amount;                // Extract amount
        expenses.push_back(e);         // Add expense to the vector
    }
    file.close();
}


// Saves all expenses from the vector to the file
void saveExpenses(const vector<Expense>& expenses) {
    ofstream file(EXPENSE_FILE); // Open the file for writing (overwrites)
    for (const auto& e : expenses) {
        file << e.date << "," << e.category << "," << e.amount << "\n"; // Write each expense as a line
    }
    file.close();
}


// Prompts the user to add a new expense and saves it
void addExpense(vector<Expense>& expenses) {
    Expense e;
    cout << "Enter date (YYYY-MM-DD): ";
    cin >> e.date;
    cin.ignore(); // to consume leftover newline
    cout << "Enter category: ";
    getline(cin, e.category); // Read category (can include spaces)
    cout << "Enter amount: ";
    cin >> e.amount;

    expenses.push_back(e);      // Add new expense to the vector
    saveExpenses(expenses);     // Save updated expenses to file
    cout << "Expense added!\n";
}


// Displays all expenses in a formatted table
void viewExpenses(const vector<Expense>& expenses) {
    cout << "\n--- All Expenses ---\n";
    cout << left << setw(12) << "Date"
              << setw(20) << "Category"
              << setw(10) << "Amount" << "\n";
    cout << "------------------------------------\n";
    for (const auto& e : expenses) {
        cout << left << setw(12) << e.date
                  << setw(20) << e.category
                  << setw(10) << e.amount << "\n";
    }
    cout << "------------------------------------\n";
}


// Calculates and displays the total amount of all expenses
void showTotal(const vector<Expense>& expenses) {
    double total = 0;
    for (const auto& e : expenses) {
        total += e.amount; // Add each expense's amount
    }
    cout << "Total expenses: " << total << "\n";
}


// Displays the main menu and handles user input
void menu() {
    vector<Expense> expenses;    // Vector to store all expenses
    loadExpenses(expenses);      // Load existing expenses from file

    while (true) {
        cout << "\nExpense Tracker Menu\n";
        cout << "1. Add Expense\n";
        cout << "2. View Expenses\n";
        cout << "3. Show Total\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";

        int choice;
        cin >> choice;
        cin.ignore(); // consume leftover newline

        if (choice == 1) {
            addExpense(expenses);      // Add a new expense
        } else if (choice == 2) {
            viewExpenses(expenses);    // View all expenses
        } else if (choice == 3) {
            showTotal(expenses);       // Show total expenses
        } else if (choice == 4) {
            cout << "Exiting...\n";
            break;                    // Exit the program
        } else {
            cout << "Invalid choice! Try again.\n";
        }
    }
}


// Entry point of the program
int main() {
    menu(); // Start the menu loop
    return 0;
}