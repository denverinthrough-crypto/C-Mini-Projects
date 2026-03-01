#include <iostream>
#include <string>
#include <vector>
using namespace std;



int main(){
    // Rider UpdateRider();
    string fname, lname, nationality, profile;
    
    vector<string> roles = {};
    int option;
    char addAnother;


    cout << "********** RIDER's PROFILE **********\n\n";

   

    // ask user to enter name
    cout << "Enter First Name: ";
    cin >> fname;

    cout << "Enter Last Name: ";
    cin >> lname;

    cout << "Enter Nationality: ";
    cin >> nationality;

    string profile = fname + " " + lname + " : " + nationality;
    cout << "Rider profile: " + profile << "\n";

    cout << "\nAssign Role:\n";
    cout << "1. Team Leader\n";
    cout << "2. Climbing Domestiques\n";
    cout << "3. All-Around Domestiques\n";
    cin >> option;

    switch(option) {
        case 1:
            roles.push_back("Team Leader");
            break;
        case 2:
            roles.push_back("Climbing Domestiques");
            break;
        case 3:
            roles.push_back("All-Around Domestiques");
            break;
        default:
            cout << "Invalid option\n";
    }

    cout <<  roles.back()  + " : " + fname + " " + lname + "\n"; // press enter to add another rider

    cout << "Add Rider: "; // i need a loop to go back to this option

    

};



