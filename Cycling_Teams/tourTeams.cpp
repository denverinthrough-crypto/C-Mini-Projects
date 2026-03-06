#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
#include <sstream>
using namespace std;

// Known acronyms
 vector<string> acronyms = {"UAE", "BMC", "EF", "CMA", "CGM", "FDJ", "BORA", "XDS", "INEOS", "USA"};

 bool isAcronym(string word) {
    transform(word.begin(), word.end(), word.begin(), ::toupper);
    for (string a : acronyms) {
        if(word == a) return true;
    }
    return false;
 }

 string formatTeamName(string name){
    // Replace - with space around it for splitting
    string cleaned = "";
    for(char c : name) {
        if (c == '-') cleaned += " - ";
        else cleaned += c;
    }

    stringstream ss(cleaned);
    string word;
    string result = "";

    while (ss >> word) {
        if (word == "-") {
            result += "- "; // Keep the dash as is

        } else if(isAcronym(word)){
            transform(word.begin(), word.end(), word.begin(), ::toupper);
            result += word + " ";

        } else {
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            word[0] = toupper(word[0]);
            result += word + " ";

        }
    }

    result.pop_back();
    return result;
 }

 bool isCancelled(const string& input) { // input cancel option
    return input == "0" || input == "cancel";
 }

// =========================
// TEAM CLASS
// =========================
class Teams {
    private:
 
        vector<string> teams; // member variable
        vector<string> countries; // member variable

    public: 
        // Constructor
        Teams(){
            cout << "***********************************\n";
            cout << "*** Tour de France Team Manager ***\n";
            cout << "***********************************\n";
        }

        // Function to add team name and country name
        void addTeam(string name, string country){
            teams.push_back(name);
            countries.push_back(country);
            cout << "Team " + name + " | " + country << "\n";
        }

        // Function to show team/country
        void showTeam(){
            cout << "\n****| Tour de France Teams |****\n";
            for(int i = 0; i < teams.size(); i++) {
                cout << i + 1 << ". " << teams[i] << " (" << countries[i] << ")\n";
            }
        }

        // Returns team name by index for Riders to use
        string getTeam(int index){
            return teams[index];
        }

        int teamCount() {
            return teams.size();
        }

        bool isEmpty() {
            return teams.empty();
        }

};

// ======================
// RIDERS CLASS
// ======================
class Riders {
    private:
        struct Rider {
            string fname;
            string lname;
            string country;
            string role;
            string team;
        };

        vector<Rider> roster;

    public:
        Riders() {
            cout << "*****************************\n";
            cout << "*** Rider Profile Manager ***\n";
            cout << "*****************************\n";
        }

        void addRider(string  fname, string lname, string country, string role, string team ){
            Rider r;
            r.fname = fname;
            r.lname = lname;
            r.country = country;
            r.role = role;
            r.team = team;
            roster.push_back(r);
            cout << "\n" + role + ": " + fname + " " + lname + " added to " + team + ".\n";
        }

        void showRiders(){
            if(roster.empty()){
                cout << "No riders added yet.\n";
                return;
            
            }
            cout << "\n****| Tour de France Riders |****\n";
            for(int i = 0; i < roster.size(); i++) {
                cout << i + 1 << ". "
                << roster[i].fname + " " + roster [i].lname
                << " | " << roster[i].country
                << " | " << roster[i].role
                << " | " << roster[i].team << "\n";
            }
        }

};

// ======================
// Main
// ======================
int main() {

    

    // Local variables
    Teams tourTeams; // object created tourTeams to class Teams
    Riders tourRiders; // object created to class Riders
    string teamName, country, input;
    
    int choice;
    

    do {
        cout << "\n*** Tour De France Manager ***\n";
        cout << "1. Add Team\n2. Show Teams\n3. Add Rider\n4. Show Riders\n5. Exit\n";
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
                if(isCancelled(teamName)) { cout << "Cancelled.\n"; break;} // cancel option

                // Check if name contains only letters and spaces
                if(teamName.empty() || !all_of(teamName.begin(), 
                        teamName.end(), [](char c){ return isalpha(c)|| isspace(c)
                        || c == '-'; })) {
                        cout << "Invalid name. Use letters only.\n";
                        break;
                }

                teamName = formatTeamName(teamName);

                cout << "Enter country: ";
                getline(cin, country);
                if(isCancelled(country)) { cout << "Cancelled.\n"; break;} // cancel option

                if (country.empty() || !all_of(country.begin(), country.end(), [](char c){ return isalpha(c) || isspace(c)
                    || c == '-'; })) {
                    cout << "Invalid country. Use letters only.\n";
                    break;
                }

                country = formatTeamName(country);

                tourTeams.addTeam(teamName, country);
                break;

            case 2:
                tourTeams.showTeam();
                break;

            case 3: {
                // Check if teams exit first
                if(tourTeams.isEmpty()) {
                    cout << "No teams yet. Please add a team first.\n";
                    break;
                }

                string fname, lname, country, roleInput, teamInput;
                int roleOption, teamChoice;

                cout << "Enter First Name: ";
                getline(cin, fname);
                fname = formatTeamName(fname);

                cout << "Enter Last Name: ";
                getline(cin, lname);
                lname = formatTeamName(lname);

                cout << "Enter Country: ";
                getline(cin, country);
                country = formatTeamName(country);

                cout << "\nAssign Role:\n";
                cout << "1. Team Leader\n";
                cout << "2. Climbing Domestique\n";
                cout << "3. All-Around Domestique\n";
                cout << "Choose: ";
                getline(cin, roleInput);

                string role;
                try {
                    roleOption = stoi(roleInput);
                    switch(roleOption) {
                        case 1: role = "Team Leader"; break;
                        case 2: role = "Climbing Domestique"; break;
                        case 3: role = "All-Around Domestique"; break;
                        default:
                            cout << "Invalid role.\n";
                            break;
                    }
                    if(role.empty()) break;

                }catch (...) {
                    cout << "Invalid input.\n";
                    break;
                }

                // Pick from existing teams
                cout << "\nAssign to Team:\n";
                tourTeams.showTeam();
                cout << "Choose team number: ";
                getline(cin, teamInput);

                try {
                    teamChoice = stoi(teamInput);
                    if(teamChoice < 1 ||  teamChoice > tourTeams.teamCount()) {
                        cout << "Invalid team number.\n";
                        break;
                    }
                }catch (...){
                    cout << "Invalid input.\n";
                    break;

                }

                string assignedTEam = tourTeams.getTeam(teamChoice - 1);
                tourRiders.addRider(fname, lname, country, role, assignedTEam);
                break;
            }

            case 4:
                tourRiders.showRiders();
                break;

            case 5:
                cout << "Exiting....\n";
                break;

            default:
                cout << "Invalid option.\n";

        }
    } while (choice != 5);

    return 0;
   

}





