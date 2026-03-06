#include <iostream>
#include <string>
#include <vector>
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

       

         vector<Rider>& getRoster() {
            return roster;
        }

        


};

 void showTeamWithRiders(Teams& teams, Riders& riders) {
            cout << "\n****| Tour de France Teams & Riders |****\n";
            for(int i = 0; i < teams.teamCount(); i++) {
               cout << i + 1 << ". " << teams.getTeam(i) << "\n";
               bool hasRider = false;
               for (auto& r : riders.getRoster()) {
                if(r.team == teams.getTeam(i)) {
                    cout << "   - " << r.fname << " " << r.lname
                     << " | " << r.country
                     << " | " << r.role << "\n";
                    hasRider = true;
                }
            }
            if(!hasRider) cout << "   - No riders yet.\n";
            }
         }

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
        cout << "\n*** Tour de France Team Manager ***\n";
        cout << "1. Add Team\n2. Add Rider\n3. Show Teams & Riders\n4. Exit\n";
        cout << "Choose: ";
        getline(cin, input);


        try {
            choice = stoi(input);
           
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

           

            case 2: {
                // Check if teams exit first
                if(tourTeams.isEmpty()) {
                    cout << "No teams yet. Please add a team first.\n";
                    break;
                }

                string fname, lname, country, roleInput, teamInput;
                int roleOption, teamChoice;

                cout << "Enter First Name: ";
                getline(cin, fname);
                if(isCancelled(fname)) { cout << "Cancelled.\n"; break; }
                fname = formatTeamName(fname);

                cout << "Enter Last Name: ";
                getline(cin, lname);
                if(isCancelled(lname)) { cout << "Cancelled.\n"; break; }
                lname = formatTeamName(lname);

                cout << "Enter Country: ";
                getline(cin, country);
                if(isCancelled(country)) { cout << "Cancelled.\n"; break; }
                country = formatTeamName(country);

                cout << "\nAssign Role:\n";
                cout << "1. Team Leader\n";
                cout << "2. Climbing Domestique\n";
                cout << "3. All-Around Domestique\n";
                cout << "Choose: ";
                getline(cin, roleInput);
                if(isCancelled(roleInput)) { cout << "Cancelled.\n"; break; }

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
                if(isCancelled(teamInput)) { cout << "Cancelled.\n"; break; }

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

           

            case 3:
                showTeamWithRiders(tourTeams, tourRiders);
                break;

            case 4:
                cout << "Exiting....\n";
                break;

            default:
                cout << "Invalid option.\n";

        }
    } while (choice != 4);

    return 0;
   

}





