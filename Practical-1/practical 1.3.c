#include <iostream>
#include <string>
using namespace std;

int main()
{
    string sen, word = "", longest = "";

    cout << "Enter a sentence: ";
    getline(cin, sen);

    sen = sen + " ";

    for (int i = 0; i < sen.length(); i++)
    {
        if (sen[i] != ' '){
            word = word + sen[i];
        }
        else{
            if (word.length() > longest.length()){
                longest = word;
            }
            word = "";
        }
    }

    cout << "Longest word:" << longest << endl;
    cout << "Number of characters:" << longest.length();

    return 0;
}
