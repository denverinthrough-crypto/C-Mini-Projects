#include <iostream>
using namespace std;


double convert(double temp ){
        return (temp * 9/5) + 32;
        
};

int main(){
    double num = 50;

    cout << "The temperature is: " << convert(num) << + "F" << "\n";


}



// celsius to fahrenheit
// (c * 9/5) + 32