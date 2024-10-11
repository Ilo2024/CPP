#include <iostream>
using namespace std;

double yourSalary(int year) {
    if (year == 1) {
        return 15000;
    }
    else {
        double previousSalary = yourSalary(year - 1);
        return previousSalary * 1.04 + 400;
    }
}

int main() {
    int year;

    cout << "Enter what year you want to calculate you'r salary: ";
    cin >> year;

    double salary = yourSalary(year);

    cout << "You'r monthly salary for year " << year << " is: " << salary << " sek." << endl;
    return 0;
}
