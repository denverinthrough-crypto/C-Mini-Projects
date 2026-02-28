#include <iostream>
using namespace std;


double convert(double temp ){
        return (temp * 9/5) + 32;
        
};

int main(){
    double num;
    
    cout << "Enter number: \n"; // user's input
    cin >> num;

   
    cout << "The temperature is: " << convert(num) << + " F" << "\n";

    
    if (num > 80) {
        cout << "It's too hot outside!";
    
    } else if (num > 75) {
        cout << "It's not too bad outside!";

    } else {
        cout << "It's cold!";
    }
   
    
}


// convert c to f - checked
// add temp to convert