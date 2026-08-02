#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main()
{
    string sen;
    string word, longest_word;
    int max_length =0;
    cout <<"Describe a article over here  :";
    getline(cin,sen);

    stringstream a(sen);
    while(a >> word )
    {
        if( word.length() > max_length)
        {
            max_length = word.length();
            longest_word =word;
        }
    }

    cout<<"Longest word :"<<longest_word <<endl;
    cout<<"Max Length :"<<max_length <<endl;
    return 0;
}

