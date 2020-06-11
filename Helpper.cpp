#include "Helpper.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int Helpper :: numberLine(){ // hàm đếm số dòng trong file
    ifstream f1;
    char c;
    int numchars, numlines;

    f1.open("C:\\Users\\khiem\\Desktop\\ImportData.csv");

    numchars = 0;
    numlines = 0;
    f1.get(c);
    while (f1) {
        while (f1 && c != '\n') {
            numchars = numchars + 1;
            f1.get(c);
        }
        numlines = numlines + 1;
        f1.get(c);
    }
    //      cout << "The file has " << numlines << " lines and "
    //        << numchars << " characters" << endl;
    return(numlines);
}
vector<string> Helpper ::split(const string &s, char delim){
    vector<string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}
//hàm so sánh 2 string
int Helpper::isSubstring(string s1, string s2)
{
    std::transform(s1.begin(), s1.end(),s1.begin(), ::tolower);
    std::transform(s2.begin(), s2.end(),s2.begin(), ::tolower);
    int M = s1.length();
    int N = s2.length();
    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++)
            if (s2[i + j] != s1[j])
                break;

        if (j == M)
            return i;
    }

    return -1;
}



