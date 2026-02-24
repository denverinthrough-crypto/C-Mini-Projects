#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Player structure
struct Player {
    string name;
    string height;   // e.g., 7'2
    string position; // PG, SG, SF, PF, C

    Player(string n, string h, string p) : name(n), height(h), position(p) {}
};

// Team class
class Team {
private:
    string teamName;
    vector<Player> players; // max 5 players

public:
     Team() : teamName("") {}
    Team(string name) : teamName(name) {}

    void addPlayer(const Player& p) {
        if (players.size() >= 5) {
            cout << "Team already has 5 players!\n";
            return;
        }
        players.push_back(p);
        cout << p.name << " added to " << teamName << "\n";
    }

    void removePlayer(const string& name) {
        bool found = false;
        for (auto it = players.begin(); it != players.end(); ++it) {
            if (it->name == name) {
                players.erase(it);
                found = true;
                cout << name << " removed from " << teamName << "\n";
                break;
            }
        }
        if (!found) cout << "Player not found!\n";
    }

    void modifyPlayer(const string& name, string newHeight, string newPosition) {
        bool found = false;
        for (auto& p : players) {
            if (p.name == name) {
                p.height = newHeight;
                p.position = newPosition;
                found = true;
                cout << name << " updated.\n";
                break;
            }
        }
        if (!found) cout << "Player not found!\n";
    }

    void showPlayers() const {
        cout << "\nTeam " << teamName << " Roster:\n";
        if (players.empty()) {
            cout << "(No players yet)\n";
            return;
        }
        for (const auto& p : players) {
            cout << p.name << " | " << p.height << " | " << p.position << "\n";
        }
    }

    string getName() const { return teamName; }
};

int main() {
    map<string, Team> league;
    int choice;

    while (true) {
        cout << "\n=== Basketball Team Manager ===\n";
        cout << "1. Create new team\n";
        cout << "2. Add player to a team\n";
        cout << "3. Remove player from a team\n";
        cout << "4. Modify player in a team\n";
        cout << "5. Show team roster\n";
        cout << "6. Show all teams\n";
        cout << "7. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore(); // consume leftover newline

        if (choice == 1) {
            string teamName;
            cout << "Enter team name: ";
            getline(cin, teamName);
            if (league.find(teamName) != league.end()) {
                cout << "Team already exists!\n";
            } else {
                league[teamName] = Team(teamName);
                cout << "Team " << teamName << " created!\n";
            }
        }
        else if (choice == 2) {
            string teamName;
            cout << "Enter team name: ";
            getline(cin, teamName);

            auto it = league.find(teamName);
            if (it != league.end()) {
                string playerName, height, position;
                cout << "Enter player name: ";
                getline(cin, playerName);
                cout << "Enter player height (e.g., 7'2): ";
                getline(cin, height);
                cout << "Enter player position (PG/SG/SF/PF/C): ";
                getline(cin, position);

                it->second.addPlayer(Player(playerName, height, position));
            } else {
                cout << "Team not found!\n";
            }
        }
        else if (choice == 3) {
            string teamName, playerName;
            cout << "Enter team name: ";
            getline(cin, teamName);
            cout << "Enter player name to remove: ";
            getline(cin, playerName);

            auto it = league.find(teamName);
            if (it != league.end()) {
                it->second.removePlayer(playerName);
            } else {
                cout << "Team not found!\n";
            }
        }
        else if (choice == 4) {
            string teamName, playerName, height, position;
            cout << "Enter team name: ";
            getline(cin, teamName);
            cout << "Enter player name to modify: ";
            getline(cin, playerName);
            cout << "Enter new height (e.g., 6'8): ";
            getline(cin, height);
            cout << "Enter new position (PG/SG/SF/PF/C): ";
            getline(cin, position);

            auto it = league.find(teamName);
            if (it != league.end()) {
                it->second.modifyPlayer(playerName, height, position);
            } else {
                cout << "Team not found!\n";
            }
        }
        else if (choice == 5) {
            string teamName;
            cout << "Enter team name: ";
            getline(cin, teamName);

            auto it = league.find(teamName);
            if (it != league.end()) {
                it->second.showPlayers();
            } else {
                cout << "Team not found!\n";
            }
        }
        else if (choice == 6) {
            cout << "All teams:\n";
            for (const auto& [name, team] : league) {
                cout << "- " << name << "\n";
            }
        }
        else if (choice == 7) {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}