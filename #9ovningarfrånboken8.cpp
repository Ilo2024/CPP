#include <iostream>
using namespace std;

char* myStrcat(char* destination, const char* source) {
    while (*destination) {
        destination++;
    }
    while (*source) {
        *destination++ = *source++;
    }

    *destination = '\0';

    return destination;
}

int main() {
    char destination[50] = "Hello ";
    const char* source = "friend!";

    myStrcat(destination, source);

    cout << "Resultat: " << destination << endl;

    return 0;
}
