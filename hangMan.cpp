#include <bits/stdc++.h>

using namespace std;

int maxGuessOfPlayer();
string chooseWord();
void renderGame(string guessWord, int badGuessCount);
char readAGuess();
bool contains(string secretWord, char guess);
string uppdate(string guessWord, string secretWord, char guess);
int startGame();
void  displayResault(int badGuessCount , string guessWord, string secretWord );

const string WORD_LIST[] = {"angle", "ant", "apple", "arch", "arm", "army",
 "baby", "bag", "ball", "band", "basin", "basket", "bath", "bed", "bee", "bell", "berry",
 "bird", "blade", "board", "boat", "bone", "book", "boot", "bottle", "box", "boy",
 "brain", "brake", "branch", "brick", "bridge", "brush", "bucket", "bulb", "button",
 "cake", "camera", "card", "cart", "carriage", "cat", "chain", "cheese", "chest",
 "chin", "church", "circle", "clock", "cloud", "coat", "collar", "comb", "cord",
 "cow", "cup", "curtain", "cushion",
 "dog", "door", "drain", "drawer", "dress", "drop", "ear", "egg", "engine", "eye",
 "face", "farm", "feather", "finger", "fish", "flag", "floor", "fly",
 "foot", "fork", "fowl", "frame", "garden", "girl", "glove", "goat", "gun",
 "hair", "hammer", "hand", "hat", "head", "heart", "hook", "horn", "horse",
 "hospital", "house", "island", "jewel", "kettle", "key", "knee", "knife", "knot",
 "leaf", "leg", "library", "line", "lip", "lock",
 "map", "match", "monkey", "moon", "mouth", "muscle",
 "nail", "neck", "needle", "nerve", "net", "nose", "nut",
 "office", "orange", "oven", "parcel", "pen", "pencil", "picture", "pig", "pin",
 "pipe", "plane", "plate", "plow", "pocket", "pot", "potato", "prison", "pump",
 "rail", "rat", "receipt", "ring", "rod", "roof", "root",
 "sail", "school", "scissors", "screw", "seed", "sheep", "shelf", "ship", "shirt",
 "shoe", "skin", "skirt", "snake", "sock", "spade", "sponge", "spoon", "spring",
 "square", "stamp", "star", "station", "stem", "stick", "stocking", "stomach",
 "store", "street", "sun", "table", "tail", "thread", "throat", "thumb", "ticket",
 "toe", "tongue", "tooth", "town", "train", "tray", "tree", "trousers", "umbrella",
 "wall", "watch", "wheel", "whip", "whistle", "window", "wire", "wing", "worm"};

const int WORD_COUNT = sizeof(WORD_LIST) / sizeof(string);
const int MAX_GUESS_PLAYER = 7;
const string FIGURE[] = {
 " ------------- \n"
 " | \n"
 " | \n"
 " | \n"
 " | \n"
 " | \n"
 " ----- \n",
 " ------------- \n"
 " | | \n"
 " | \n"
 " | \n"
 " | \n"
 " | \n"
 " ----- \n",
 " ------------- \n"
 " | | \n"
 " | O \n"
 " | \n"
 " | \n"
 " | \n"
 " ----- \n",
 " ------------- \n"
 " | | \n"
 " | O \n"
 " | | \n"
 " | \n"
 " | \n"
 " ----- \n",
 " ------------- \n"
 " |  | \n"
 " |  O \n"
 " | /| \n"
 " | \n"
 " | \n"
 " ----- \n",
 " ------------- \n"
 " |  | \n"
 " |  O \n"
 " | /|\\ \n"
 " | \n"
 " | \n"
 " ----- \n",
 " ------------- \n"
 " |  | \n"
 " |  O \n"
 " | /|\\ \n"
 " | / \n"
 " | \n"
 " ----- \n",
 " ------------- \n"
 " |  | \n"
 " |  O \n"
 " | /|\\ \n"
 " | / \\ \n"
 " | \n"
 " ----- \n",
};

int main()
{
    startGame();
    
	return 0;
}


string chooseWord() {
    
    int randomIndex = rand() % WORD_COUNT;
    return WORD_LIST[randomIndex];
}

void renderGame(string guessWord, int badGuessCount){
    cout << FIGURE[badGuessCount] << endl;
	cout << "Guess Word : " << guessWord << endl;
	cout << "Number of wrong guesses: " << badGuessCount << endl;

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
    srand(time(NULL));
	string secretWord = chooseWord();
    string guessWord  = string(secretWord.length(), '-');
    int badGuessCount = 0;

    do {
        renderGame(guessWord, badGuessCount);
        char guess = readAGuess();
        if (contains(secretWord, guess))
        {
            guessWord = uppdate(guessWord, secretWord, guess);
        } else  {
            badGuessCount++ ;
        }

        if (badGuessCount == MAX_GUESS_PLAYER ) {
            renderGame(guessWord, badGuessCount );
        }

    } while (badGuessCount < MAX_GUESS_PLAYER && secretWord != guessWord);
    
    displayResault(badGuessCount, guessWord , secretWord);
}

void  displayResault(int badGuessCount , string guessWord, string secretWord ) {
	
	if (badGuessCount < MAX_GUESS_PLAYER) {
    	cout << "You Win !" << endl;
	} else {
		cout << "You Lose !" << endl;
	}
}