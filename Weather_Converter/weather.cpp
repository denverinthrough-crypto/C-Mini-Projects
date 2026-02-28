#include <iostream>
using namespace std;

// Function to convert Celsius to Fahrenheit
double convert(double temp ){
        return (temp * 9/5) + 32;
        
};

int main(){
    
    string choice; // store user's yes/no input
    
    do {
        double num; // stores user's Celsius input

        // Ask user to enter a temperature in Celsius
        cout << "Enter number: "; 
        cin >> num;

        // Convert and store the Fahrenheit result
        double fahrenheit = convert(num); 
        cout << "The temperature is: " << fahrenheit << " F\n";
    
    // Check the converted Fahrenheit value and print a message
    if (fahrenheit > 100) {
        cout << "Extremely hot!\n";   

    } else if (fahrenheit > 80) {
        cout << "It's too hot outside!\n";

    } else if (fahrenheit > 75) {
        cout << "It's a bit warm!\n";

    } else if (fahrenheit > 50) { 
        cout << "It's a bit chilly!\n";

    } else {
        cout << "It's cold!\n"; // Anything 50F and below is considered cold
    }

    // Ask user if they want to convert another temperature
    cout << "\n";
    cout << "You want to check again? (Yes/No): ";
    cin >> choice;
    cout << "\n";
   
    } while (choice == "Yes" || choice == "yes");

    cout << "Goodbye!\n";

    return 0;

}


