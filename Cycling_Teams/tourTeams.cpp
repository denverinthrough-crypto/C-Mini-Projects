#include <iostream>
#include <string>
#include <vector>
using namespace std;


struct Rider {
    string fname, lname, country, role;
};


int main(){
    
    
    
    vector<Rider> roster;
    int roleOption;
    string choice;
    
    
    cout << "********** RIDER's PROFILE **********\n\n";

    
        Rider rider;
    


    do {   
        // ask user to enter name
        cout << "Enter First Name: ";
        getline(cin, rider.fname);

        cout << "Enter Last Name: ";
        getline(cin,  rider.lname);

        cout << "Enter Country: ";
        getline(cin, rider.country);

        string profile = rider.fname + " " + rider.lname + " : " + rider.country;
        cout << "Rider's profile: " + profile << "\n";

        cout << "\nAssign Role:\n";
        cout << "1. Team Leader\n";
        cout << "2. Climbing Domestique\n";
        cout << "3. All-Around Domestique\n";
        cin >> roleOption;

    
   
        switch(roleOption) {
            case 1:
                rider.role = "Team Leader";
                break;
            case 2:
                rider.role = "Climbing Domestique";
                break;
            case 3:
                rider.role = "All-Around Domestique";
                break;
            default:
                cout << "Invalid option.\n";
                continue;
        }

        roster.push_back(rider); // save rider to roster
        cout <<  rider.role  + " : " + profile + "\n"; // press enter to add another rider
        cout << "****|Team Roster|****\n";

        for(int i = 0; i < roster.size(); i++){
            
            cout << i + 1 << ". "
                << roster[i].fname + " " +  roster[i].lname 
                << " | " << roster[i].country
                << " | " << roster[i].role << "\n";
        }

        cout << "Add another rider: (yes/no)\n"; // i need a loop to go back to this option
        cin >> choice;
        cin.ignore();
        

    } while (choice == "Yes" || choice == "yes");
        cout << "Finished team's roster.\n";
   
    return 0;

};



