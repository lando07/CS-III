#include "util.h"
#include <cctype>
#include <string>

string removeA(string s);

int main(){
    string s = readLine("Please enter a phrase in caps: ");
    for(char &c : s){
        c = toupper(c);
    }
    cout << "Removed A's: " << removeA(s) << endl;
}

string removeA(string s){
    if(s.find("A") != string::npos){
        return removeA(s.replace(s.find("A"),1,""));
    }
    else{
        return s;
    }
}