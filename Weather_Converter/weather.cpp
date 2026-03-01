#include <iostream>
#include <iomanip>
using namespace std;


class WeatherConverter {
    private:
        double temperature;

    public:
        // Constructor
        WeatherConverter(double temp = 0.0) {
            temperature = temp;
        }

        // Setter
        void setTemperature(double temp) { // no return
            temperature = temp;
        }

        // Getter
        double getTemperature() { // get the value of temp(user's input) temperature = temp;
            return temperature;
        }

        // Function to convert Celsius to Fahrenheit
        double convertF(){
            return (temperature * 9/5) + 32; // return the value as a "expression"
        }

        // Function to convert Fahrenheit to Celsius
        double convertC(){
            return (temperature - 32) * 5/9;
        }

        // Function message output
        void weatherMessage(double temp){
        if (temp > 100) {
            cout << "Extremely hot!\n";
        } else if (temp > 80) {
            cout << "It's too hot outside!\n";
        } else if (temp > 75) {
            cout << "It's a bit warm!\n";
        } else if (temp > 50) {
            cout << "It's a bit chilly!\n";
        } else {
            cout << "It's cold!\n";
        }
    }
};
        


int main() {

    WeatherConverter converter; // create object
    
    int choice; // store user's yes/no input

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
            converter.setTemperature(num); // Set the temperature
            double fahrenheit = converter.convertF(); // Call method via object
            cout << "The temperature is: " << fahrenheit << " F\n";
            converter.weatherMessage(fahrenheit); // call function

        } else if (choice == 2) {
            cout << "Enter number: ";
            cin >> num;
            converter.setTemperature(num);
            double celsius = converter.convertC();       
            cout << "The temperature is: " << celsius << " C\n";
            converter.weatherMessage(celsius);

        } else if (choice == 3) {
            cout << "Goodbye!\n";

        }else {
            cout << "Invalid input. Please choose 1, 2, 3.\n";
        }
    } while (choice != 3);
    return 0;

   

}


