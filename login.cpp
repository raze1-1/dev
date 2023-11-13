#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isLoggedIn()
{
    string username, password, un, pw;

    cout << "Enter a username: "; cin >> username;
    cout << "Enter a password: "; cin >> password;

    ifstream read("data\\" + username + ".txt");
    getline(read, un);
    getline(read, pw);

    if (un == username && pw == password)
    {
        return true;
        
    } 
    else
    {
        return false;
    }
 
}

int main()
{
    int choice;

    cout << "1: Register\n2: Login\n Your choice: "; cin >> choice;
    if (choice == 1)
    {
        string username, password;

        cout << "select a username: "; cin >> username;
        cout << "select a password: "; cin >> password;
        
        ofstream file;
        file.open("data\\" + username + ".txt");
        file <<username << endl << password;
        file.close();

        main();
    }
    else if (choice == 2)
    {
        bool status = isLoggedIn();

        if (!status)
        {
            cout << "False login, check details." << endl;
            system("PAUSE");
            return 0;

        }
        else
        {
            cout << "Successfully logged in!" << endl;
            system("PAUSE");
            return 1;
        }
    }
}
