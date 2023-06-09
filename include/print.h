#ifndef __PRINT__
#define __PRINT__
#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;

class Print {
    public:
        void printOutput(const string& s) {
            cout << s;
        }
        void printStaggeredOutput(const string& text, int delay) {
            for (char c : text) {
                cout << c << flush; // Print the character
                usleep(delay * 1000); // Delay in microseconds
            }
        }
        void printNewline() {
            cout << endl;
        }
        void printYellow(const string& s) {
            cout << "\033[1;33m" << s << "\033[0m";
        }
        void printGreen(const string& s) {
            cout << "\033[1;32m" << s << "\033[0m";
        }
        void handleColor(int num) {
            if(num == -1) {
                cout << "\033[0m\n"; // reset to white
                return;
            }
            if(num >= 5) {
                cout << "\033[1;32m"; //set to green
                return;
            } if(num >=3) {
                cout << "\033[1;33m"; // yellow
                return;
            }
            else {
                cout << "\033[1;31m"; // red
            }
        }
};

#endif