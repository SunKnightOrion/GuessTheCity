#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cctype>
#include <string>
using namespace std;



int main()
{
    cout<<"Welcome to game \"Guess The City\"!!!"<<endl;
    cout<<"Guid:"<<endl;
    cout<<"You shall unriddle the name of a random city"<<endl;
    cout<<"By entering one character at a time."<<endl;
    cout<<"Maximum mistakes - 8."<<endl;
    const int MAX_WRONG = 8;
    vector<string> words;
    words.push_back("TOKYO");
    words.push_back("MOSCOW");
    words.push_back("KYOTO");
    words.push_back("LONDON");
    words.push_back("PARIS");
    words.push_back("TASHKENT");
    words.push_back("ASTANA");
    words.push_back("BERLIN");
    words.push_back("SEUL");
    words.push_back("NEWYORK");
    words.push_back("BEIJING");
    words.push_back("SINGAPORE");
    words.push_back("PETERSBURG");
    words.push_back("ROME");
    words.push_back("BUKHARA");
    words.push_back("KHOREZM");
    words.push_back("ANKARA");
    words.push_back("ISTANBUL");
    words.push_back("SAMARKAND");
    words.push_back("KHIVA");
    words.push_back("VENICE");
    words.push_back("BARCELONA");
    words.push_back("MADRID");
    words.push_back("RIO");
    words.push_back("VATICAN");
    words.push_back("MEXICO");
    words.push_back("STOCKHOLM");
    words.push_back("DELHI");
    words.push_back("ABUDHABI");
    words.push_back("DUBAI");
    words.push_back("AMSTERDAM");
    words.push_back("SYDNEY");
    words.push_back("KIEV");
    char w='y';
    while(w=='y'){
        srand(static_cast<unsigned int>(time(0)));
        random_shuffle(words.begin(),words.end());
        const string THE_WORD = words[0];
        int wrong = 0;
        int n = THE_WORD.length();
        string soFar(n,'-');
        string used = " ";
        while(wrong<MAX_WRONG && soFar!=THE_WORD){
            cout<<"\n\nRemaining mistakes: "<<MAX_WRONG - wrong;
            cout<<"\nYou have used: ";
            cout<<used;
            cout<<"\nSo far the word is:\n";
            cout<<soFar<<endl;
            cout<<"\nEnter your guess: ";
            char guess;
            cin>>guess;
            guess = toupper(guess);
            while(used.find(guess) != string::npos){
                cout<<"You have already used this character.\n";
                cout<<"Enter your guess: ";
                cin>>guess;
                guess = toupper(guess);
            }
            used +=guess;
            used +=" ";
            if(THE_WORD.find(guess) != string::npos){
                cout<<"\nRight! \'"<<guess<<"\' is in this name!";
                for(int i=0; i<n; i++){
                    if(guess==THE_WORD[i]){
                        soFar[i]=guess;
                    }
                }
            }
            else{
                cout<<"\nSorry, but this character is missing.";
                wrong++;
            }
        }
        if(wrong==MAX_WRONG){
            cout<<"\n\n\t\t\tGAME OVER\n";
        }
        else if(soFar==THE_WORD){
            cout<<"\n\n\t\t\tYes! You have guessed name the city!\n";
        }
        cout<<"\nIt was: "<<THE_WORD<<endl;
        cout<<"\nEnter y to continue -> ";
        cin>>w;
    }
    return 0;
}
