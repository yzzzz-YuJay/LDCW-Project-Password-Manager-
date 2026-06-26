#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

using namespace std;

// Return to the main menu after viewing a page.
void returnToMenu()
{
    int choice;

    cout << "\nPress 1 to return to Main Menu: ";
    cin >> choice;

    if(cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
    }

    while(choice != 1)
    {
        cout << "Invalid input. Press 1 to return: ";
        cin >> choice;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }

    system("cls");
}

// Display password security tips for creating stronger passwords.
void showTips()
{
    system("cls");

    cout << "==================================================\n";
    cout << "            PASSWORD SECURITY TIPS\n";
    cout << "==================================================\n\n";

    cout << "1. Use at least 12 characters.\n\n";
    cout << "2. Include uppercase letters.\n\n";
    cout << "3. Include lowercase letters.\n\n";
    cout << "4. Include numbers.\n\n";
    cout << "5. Include special characters.\n\n";
    cout << "6. Avoid personal information.\n\n";
    cout << "7. Use different passwords for different accounts.\n\n";

    cout << "==================================================\n";

    returnToMenu();
}

// Display information about the program.
void showAbout()
{
    system("cls");

    cout << "==================================================\n";
    cout << "                ABOUT PROGRAM\n";
    cout << "==================================================\n\n";

    cout << "Program Name:\n";
    cout << "Smart Password Security Checker\n\n";

    cout << "Category:\n";
    cout << "Cybersecurity - Password Manager\n\n";

    cout << "Purpose:\n";
    cout << "Evaluate password strength and provide\n";
    cout << "recommendations for better security.\n\n";

    cout << "Developed For:\n";
    cout << "LDCW6123 Group Project\n\n";

    cout << "==================================================\n";

    returnToMenu();
}

// Display a farewell message before exiting the program.
void exitProgram()
{
    system("cls");

    cout << "==================================================\n";
    cout << "          THANK YOU FOR USING\n\n";
    cout << "      SMART PASSWORD SECURITY CHECKER\n\n";
    cout << "==================================================\n\n";

    cout << "Stay Safe Online!\n\n";

    cout << "Program Terminated Successfully.\n\n";

    cout << "==================================================\n";
}

// Analyze the password and evaluate its strength.
void checkPassword()
{
    int option;

    do
    {
        system("cls");

        // Variables used for password analysis.
        string password;

        bool hasUpper = false;
        bool hasLower = false;
        bool hasDigit = false;
        bool hasSymbol = false;

        int score = 0;

        cout << "==================================================\n";
        cout << "            PASSWORD STRENGTH CHECKER\n";
        cout << "==================================================\n\n";

        cout << "Enter Password: ";
        cin >> password;

        // Check whether the password contains different character types.
        for(char ch : password)
        {
            if(isupper(ch))
                hasUpper = true;
            else if(islower(ch))
                hasLower = true;
            else if(isdigit(ch))
                hasDigit = true;
            else
                hasSymbol = true;
        }

        // Calculate the password security score.
        if(password.length() >= 8)
            score += 20;

        if(password.length() >= 12)
            score += 20;

        if(hasUpper)
            score += 20;

        if(hasLower)
            score += 20;

        if(hasDigit)
            score += 10;

        if(hasSymbol)
            score += 10;

        cout << "\n==================================================\n";
        cout << "              PASSWORD ANALYSIS\n";
        cout << "==================================================\n\n";

        cout << "Length >= 8        : "
             << (password.length() >= 8 ? "PASS" : "FAIL") << endl;

        cout << "Uppercase Letter   : "
             << (hasUpper ? "PASS" : "FAIL") << endl;

        cout << "Lowercase Letter   : "
             << (hasLower ? "PASS" : "FAIL") << endl;

        cout << "Number             : "
             << (hasDigit ? "PASS" : "FAIL") << endl;

        cout << "Special Character  : "
             << (hasSymbol ? "PASS" : "FAIL") << endl;

        cout << "\n--------------------------------------------------\n\n";

        cout << "Security Score     : "
             << score << "/100\n\n";

        // Display the overall password strength.
        cout << "Password Strength  : ";

        if(score < 40)
            cout << "WEAK\n";
        else if(score < 70)
            cout << "MEDIUM\n";
        else
            cout << "STRONG\n";

        cout << "\n--------------------------------------------------\n\n";

        // Provide suggestions to improve password security.
        cout << "Suggestions:\n\n";

        if(score >= 70)
        {
            cout << "Excellent password security.\n";
        }
        else
        {
            if(password.length() < 8)
                cout << "- Increase password length\n";

            if(!hasUpper)
                cout << "- Add uppercase letters\n";

            if(!hasLower)
                cout << "- Add lowercase letters\n";

            if(!hasDigit)
                cout << "- Add numbers\n";

            if(!hasSymbol)
                cout << "- Add special characters\n";
        }

        cout << "\n==================================================\n\n";

        cout << "[1] Check Another Password\n";
        cout << "[2] Return To Main Menu\n\n";

        cout << "Enter Choice: ";

        // Validate user input to prevent invalid menu selection.
        while(!(cin >> option) || (option != 1 && option != 2))
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid choice. Enter 1 or 2: ";
        }

    }
    while(option == 1);

    system("cls");
}

// Main function that controls the program flow.
int main()
{
    int choice;

    do
    {
        cout << "==================================================\n";
        cout << "      SMART PASSWORD SECURITY CHECKER\n";
        cout << "==================================================\n\n";

        cout << "[1] Check Password\n\n";
        cout << "[2] Password Security Tips\n\n";
        cout << "[3] About Program\n\n";
        cout << "[4] Exit Program\n\n";

        cout << "==================================================\n";
        cout << "Enter Choice: ";

        cin >> choice;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
        }

        // Execute the selected menu option.
        switch(choice)
        {
            case 1:
                checkPassword();
                break;

            case 2:
                showTips();
                break;

            case 3:
                showAbout();
                break;

            case 4:
                exitProgram();
                break;

            default:
                system("cls");
                cout << "Invalid Choice. Please Try Again.\n\n";
        }

    }
    while(choice != 4);

    return 0;
}