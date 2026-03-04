#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;


class Teams {
    private:
 
        vector<string> teams; // member variable
        vector<string> countries; // member variable

    public: 
        // Constructor
        Teams(){
            cout << "Tour de France Team Manager Started!\n";
        }
        
        // Function to add team name and country name
        void addTeam(string name, string country){
            teams.push_back(name);
            countries.push_back(country);
            cout << "Team " + name + " | " + country + " added.\n";
        }

        // Function to show team/country
        void showTeam(){
            cout << "\n****| Tour de France Teams |****\n";
            for(int i = 0; i < teams.size(); i++) {
                cout << i + 1 << ". " << teams[i] << " (" << countries[i] << ")\n";
            }
        }

};

int main() {

    Teams tourTeams;

    // Local variables
    Teams tourTeams;
    string teamName;
    string country;
    int choice;
    string input;

    do {
        cout << "\n*** Tour De France Teams ***\n";
        cout << "1. Add Team\n2. Show Teams\n3. Exit\n";
        cout << "Choose: ";
        getline(cin, input);


        try {
            choice = stoi(input);
            input = "";
        } catch (...) {
            cout << "Invalid input. Please enter a number.\n";
            choice = 0;
            continue;
        }


        switch(choice){
            case 1:
                cout << "Enter team name: ";
                getline(cin, teamName);

                // Check if name contains only letters and spaces
                if(teamName.empty() || !all_of(teamName.begin(), 
                        teamName.end(), [](char c){ return isalpha(c)|| isspace(c); })) {
                        cout << "Invalid name. Use letters only.\n";
                        break;
                }

                cout << "Enter country: ";
                getline(cin, country);

                if (country.empty() || !all_of(country.begin(), country.end(), [](char c){ return isalpha(c) || isspace(c); })) {
                    cout << "Invalid country. Use letters only.\n";
                    break;
                }

                tourTeams.addTeam(teamName, country);
                break;

            case 2:
                tourTeams.showTeam();
                break;

            case 3:
                cout << "Exiting.... \n";
                break;

            default:
                cout << "Invalid option.\n";

        }
    } while (choice != 3);

    return 0;
   

}

// struct Rider {
//     string fname, lname, country, role;
// };


// int main(){
    
    
    
//     vector<Rider> roster;
//     int roleOption;
//     string choice;
    
    
//     cout << "********** RIDER's PROFILE **********\n\n";

    
//         Rider rider;
    


//     do {   
//         // ask user to enter name
//         cout << "Enter First Name: ";
//         getline(cin, rider.fname);

//         cout << "Enter Last Name: ";
//         getline(cin,  rider.lname);

//         cout << "Enter Country: ";
//         getline(cin, rider.country);

//         string profile = rider.fname + " " + rider.lname + " : " + rider.country;
//         cout << "Rider's profile: " + profile << "\n";

//         cout << "\nAssign Role:\n";
//         cout << "1. Team Leader\n";
//         cout << "2. Climbing Domestique\n";
//         cout << "3. All-Around Domestique\n";
//         cin >> roleOption;

    
   
//         switch(roleOption) {
//             case 1:
//                 rider.role = "Team Leader";
//                 break;
//             case 2:
//                 rider.role = "Climbing Domestique";
//                 break;
//             case 3:
//                 rider.role = "All-Around Domestique";
//                 break;
//             default:
//                 cout << "Invalid option.\n";
//                 continue;
//         }

//         roster.push_back(rider); // save rider to roster
//         cout <<  rider.role  + " : " + profile + "\n"; // press enter to add another rider
//         cout << "****|Team Roster|****\n";

//         for(int i = 0; i < roster.size(); i++){
            
//             cout << i + 1 << ". "
//                 << roster[i].fname + " " +  roster[i].lname 
//                 << " | " << roster[i].country
//                 << " | " << roster[i].role << "\n";
//         }

//         cout << "Add another rider: (yes/no)\n"; // i need a loop to go back to this option
//         cin >> choice;
//         cin.ignore();
        

//     } while (choice == "Yes" || choice == "yes");
//         cout << "Finished team's roster.\n";
   
//     return 0;

// };



