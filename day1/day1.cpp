#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    string x; 
    string directions;
    int floorCurrent = 0;
    int numBasementFirst;
    bool foundBasement = false;

    ifstream inFile;
    inFile.open("input.txt");
    if(!inFile) {
        cerr << "Unable to open file input.txt";
        exit(1);
    }

    while (inFile >> x) {
        directions = x;
    }
    int n = directions.length();

    char char_array[n+1];
    strcpy(char_array, directions.c_str());

    for (int i = 0; i<n; i++) {
        if (char_array[i] == '(') {
            floorCurrent++;
        } else if (char_array[i] == ')') {
            floorCurrent--;
        }
        if (!foundBasement and floorCurrent == -1) {
            numBasementFirst = i;
            numBasementFirst++;
            foundBasement = true;
        }
    }
    
    cout << "Found the basement on " << numBasementFirst << " direction. \n";
    cout << "We ended up on the " << floorCurrent << "th floor. \n";
    return 0;
}

