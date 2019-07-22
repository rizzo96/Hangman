//  Hangman.cpp
//  Hangman
//  Created by Rizwan on 7/27/17.
//  Copyright © 2017 Rizwan. All rights reserved.

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int MAX_WORDS = 8;


void pick_category(ifstream &fin); //function to open the selected category file.
void get_word (ifstream& fin, string& word); //function to get a random word for the file
void prepareWord (string word, string& solved); //function to set up "_ _"
void hangman_game (string& tried, string& solved, string& word, bool& successful, int times); //function to look for the letters in the word
string solvedLetters (char letter, string word, string& solved, bool& successful); //also function to look for the letters in the word
void hangman_function8(); //all functions to display hangman image
void hangman_function7();
void hangman_function6();
void hangman_function5();
void hangman_function4();
void hangman_function3();
void hangman_function2();
void hangman_function1();
void hangman_function0();


int main ()

{
    
   char restart = 'y';
    
    while (restart == 'y' || restart =='Y')
{
    ifstream fin; // ifstream to open file
    string word; // string to hold word
    string solved; // string to hold "_"
    string tried; // string to hold function that checks for letters
    char letter; //letter user guesses
    bool Succ; //bool to check if letter is correct or not
    int times; // amount of "guesses" are left

    srand(time(0));
    
    pick_category(fin);
    get_word (fin, word);
    
    prepareWord (word, solved);
    hangman_game(tried, solved, word, Succ, times);

    
    
    if(!Succ)
        cout << "YOU HAVE FAILED. The word is: " << word << endl;

    cout << "Would you like to play again? Press y/Y to restart otherwise press anything else to quit.\n";
    cin >> restart;
    

    }

 
}


void pick_category(ifstream &fin)

{
    
    int category;
    
    cout << "Select a category. 1 for Animals, 2 for Cities, 3 for Corporate Brands. \n";
    cin >> category;
    
    switch (category)
    
    {
        case 1:
            fin.open ("Animals.txt");
            if (fin.fail())
            {
                cout << "File opening failed!";
                exit (1);
            }
            break;
            
        case 2: fin.open ("Cities.txt");
            if (fin.fail())
            {
                cout << "File opening failed!";
                exit (2);
            }
            break;
    
        case 3: fin.open ("Corporate Brands.txt");
            if (fin.fail())
            {
                cout << "File opening failed!";
                exit(3);
            }
            break;
    }
    

    
}


void get_word (ifstream& fin, string& word)

{
    int a;
    int get_word;
    
    get_word = rand () % MAX_WORDS + 1;
  
    
    for (a = 0; a < get_word; a++)
        
    {
        getline(fin, word);
        
    }

}

void prepareWord (string word, string& solved)

{
    solved = "";
    
    for (unsigned int i = 0; i < word.length(); ++i)
    {
        solved.push_back('_');
    }
    
    for(int i=0; i<solved.length(); i++)
    {
        if(isalpha(solved[i]))
            cout << solved[i] << " ";
        else cout << "_ ";
    }
    cout << endl << endl;
    
}

void hangman_game (string& tried, string& solved, string& word, bool& successful, int times)
{
    char letter;
    bool Succ;
    
    times = 8;
    
   
   
    hangman_function8();
    

    
    while (times != 0)
    {
        
        cout <<"Guess your letter:";
        cin >> letter;
        
        if (isdigit(letter))
        {
            cout << "Error! Only enter characters!\n";
            cout <<"Guess your letter:";
            cin >> letter;
        }
        
        tried = solvedLetters(letter, word, solved, Succ);
        
        for(int i=0; i<tried.length(); i++){
            if(isalpha(tried[i]))
                cout << tried[i] << " ";
            else cout << "_ ";
        }
        cout << endl << endl;
        
        if (! Succ)
        {
            
            --times;
            
            if (times == 7)
            {
                hangman_function7();
            }
            else if (times == 6)
            {
                hangman_function6();
            }
            else if (times == 5)
            {
                hangman_function5();
            }
            else if (times == 4)
            {
                hangman_function4();
            }
            else if (times == 3)
            {
                 hangman_function3();
            }
            else if (times == 2)
            {
                 hangman_function2();
            }
            else if (times == 1)
            {
                 hangman_function1();
            }
            else if (times == 0)
            {
                 hangman_function0();
            }

            cout << "There is no such letters"<<endl;
            cout << "Your amount of tries " << times << endl;
        
        }
        
        else
        {
            if (times == 8)
            {
                hangman_function8();
            }
            else if (times == 7)
            {
                hangman_function7();
            }
            else if (times == 6)
            {
                hangman_function6();
            }
            else if (times == 5)
            {
                hangman_function5();
            }
            else if (times == 4)
            {
                hangman_function4();
            }
            else if (times == 3)
            {
                hangman_function3();
            }
            else if (times == 2)
            {
                hangman_function2();
            }
            else if (times == 1)
            {
                hangman_function1();
            }
            else if (times == 0)
            {
                hangman_function0();
            }
        cout << "Your amount of tries " << times << endl;
        
        }
        
        if (tried == word){
            cout << "GREAT JOB" << endl;
            break;
        }
    }
    
    if (tried == word) successful=true;
    else successful=false;
    
}

string solvedLetters (char letter, string word, string& solved, bool& successful)
{
    int pos = -1;
    for(int i=0; i<word.length(); i++)
        if (word[i]==toupper(letter)) pos=i;
    if(pos==-1) successful=false;
    else successful=true;
    
    
    cout << endl;
    
    for(int i=0; i<word.length(); i++)
        if (word[i]==toupper(letter)) solved[i]=word[i];
    
    
    
    return solved;
    
}

void hangman_function8()
{
    cout <<"          ( )   \n";
    cout <<"         / | \\  \n";
    cout <<"           |     \n";
    cout <<"           |    \n";
    cout <<"          / \\  \n";
}

void hangman_function7()
{
    cout <<"          ( )   \n";
    cout <<"         / |    \n";
    cout <<"           |    \n";
    cout <<"          / \\  \n";
}
void hangman_function6()
{
    cout <<"          ( )   \n";
    cout <<"           |    \n";
    cout <<"           |    \n";
    cout <<"          / \\  \n";
}
void hangman_function5()
{
    cout <<"          ( )   \n";
    cout <<"           |    \n";
    cout <<"           |    \n";
    cout <<"            \\  \n";
}
void hangman_function4()
{
    cout <<"          ( )    \n";
    cout <<"           |     \n";
    cout <<"           |     \n ";
    cout <<"                 \n";
}
void hangman_function3()
{
    cout <<"          ( )   \n";
    cout <<"           |    \n";
    cout <<"                \n";
    cout <<"                \n";
}
void hangman_function2()
{
    cout <<"          ( )   \n";
    cout <<"                \n";
    cout <<"                \n";
    cout <<"                \n";
}
void hangman_function1()
{
    cout <<"          (    \n";
    cout <<"               \n";
    cout <<"               \n";
    cout <<"               \n";
}
void hangman_function0()
{
    cout <<"               \n";
    cout <<"               \n";
    cout <<"               \n";
    cout <<"               \n";
}
