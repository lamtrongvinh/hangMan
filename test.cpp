#include <bits/stdc++.h>

using namespace std;

string chooseWord();
void renderGame(string guessWord, int badGuessCount);
char readAGuess();
bool contains(string secretWord, char guess);
string uppdate(string guessWord, string secretWord, char guess);
int startGame();
void  displayResault(int badGuessCount , string guessWord, string secretWord );

int main()
{
    startGame();
    
	return 0;
}

string chooseWord() {
    return "book";
}

void renderGame(string guessWord, int badGuessCount){
	cout << guessWord << endl;
	cout << badGuessCount << endl;
}

char readAGuess() {
    cout << "Enter your guess : ";
    char char_guess;
    cin >> char_guess;
    return char_guess;
}

bool contains(string secretWord, char guess) {
    return (secretWord.find_first_of(guess) != string::npos) ;
}

string uppdate(string guessWord, string secretWord, char guess){
	for (int i = 0 ; i < secretWord.length() ; i++)
	{
		if ( guess == secretWord[i]  )
		{
			guessWord[i] = guess;
		}
	}
	// cout << secretWord<< " " << guess << " " << guessWord << endl;
	return guessWord;
}

int startGame() {
	string secretWord = chooseWord();
    string guessWord  = string(secretWord.length(), '-');
    int badGuessCount = 0;

    do {
        renderGame(guessWord, badGuessCount);
        char guess = readAGuess();
        if (contains(secretWord, guess))
        {
            guessWord = uppdate(guessWord, secretWord, guess);
        } else {
            badGuessCount++;
        }

    } while (badGuessCount < 7 && secretWord != guessWord);
    
    displayResault(badGuessCount, guessWord , secretWord);
}

void  displayResault(int badGuessCount , string guessWord, string secretWord ) {
	
	if (badGuessCount <= 7 && secretWord == guessWord) {
    	cout << "You Win !" << endl;
	} else {
		cout << "You Lose !" << endl;
	}
}