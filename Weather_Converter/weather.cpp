#include <iostream>
using namespace std;


double convert(double temp ){
        return (temp * 9/5) + 32;
        
};

int main(){
    
    string choice;
    
    do {
        double num;

        cout << "Enter number: "; // user's input
        cin >> num;

        double fahrenheit = convert(num); // store the converted value
        cout << "The temperature is: " << fahrenheit << " F\n";

    if (fahrenheit > 100) {
        cout << "Extremely hot!\n";   

    } else if (fahrenheit > 80) {
        cout << "It's too hot outside!\n";

    } else if (fahrenheit > 75) {
        cout << "It's a bit warm!\n";

    } else if (fahrenheit > 50) { 
        cout << "It's a bit chilly!\n";

    } else {
        cout << "It's cold!\n";
    }

    cout << "\n";
    cout << "You want to check again? (Yes/No): ";
    cin >> choice;
    cout << "\n";
   
    } while (choice == "Yes" || choice == "yes");

    cout << "Goodbye!\n";

    return 0;

    
}


// convert c to f - checked
// do/while loop - checked
// implement if statement