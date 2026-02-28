#include <iostream>
using namespace std;

// Function to convert Celsius to Fahrenheit
double convertF(double temp ){
        return (temp * 9/5) + 32;
};

// Function to convert Fahrenheit to Celsius
double convertC(double temp){
        return (temp - 32) * 5/9;
};
        


int main(){
    
    int choice;
     // store user's yes/no input
    
   
    do {
        double num; // stores user's Celsius input
        cout << "===== WEATHER CONVERTER ===== \n";
        cout << "Choose temperature to Convert\n";
        cout << "1. Convert Celsius to Fahrenheit\n";
        cout << "2. Convert Fahrenheit to Celsius\n";
        cout << "3. Exit\n";
        cout << "Choose option: ";
        cin >> choice;


        if(choice == 1) {
            cout << "Enter number: ";
            cin >> num;
            double fahrenheit = convertF(num); 
            cout << "The temperature is: " << fahrenheit << " F\n";

        } else if (choice == 2) {
            cout << "Enter number: ";
            cin >> num;
            double celsius = convertC(num);
            cout << "The temperature is: " << celsius << " C\n";
        } else if (choice == 3) {
            cout << "Goodbye!\n";


        }else {
            cout << "Invalid input. Please choose 1, 2, 3.\n";
        }
    } while (choice != 3);

   

}


