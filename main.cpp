#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

using namespace std;

void checkPassword()
{
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

    cout << "Security Score     : " << score << "/100\n\n";
}

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