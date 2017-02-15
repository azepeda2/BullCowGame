# Bulls and Cows Game

# Table of Contents

* [Introduction](#introduction)
* [Author](#author)
* [Project Demo](#demo)
* [Further Expansions](#expansions)

# <a name="introduction"></a>Introduction
    Bulls and Cows is a guess the word game completely played through the 
	command-line and written in C++. The player must try to guess the word 
	within a set amount of guesses. The key is that all of the words in the 
	set are isograms (words without repeating letters).
    
# <a name="author"></a>Author
* "Alejandro Zepeda" <zepedaalex25@gmail.com>

# <a name="demo"></a>Project Demo

	The game was written in order to create a fun word game and demonstrate 
	understanding of the C++ language. In order to win, the player must guess 
	the correct word within a set number if guesses (the number of guesses are 
	based on the number of letters in the current word). Upon each guess, the 
	player is told how close they are to the word, by the number of "cows" (right letter in the wrong place) or "bulls" (right letter in the right place) in 
	their guess. The game randomly chooses between a set of 3-11 letter isograms
	(words without repeating letters) and adjusts the number of guesses allowed 
	based on the amount of letters in the word. Win or lose, the player is asked
	if they would like to play again and presented with a new random word from 
	the set or exit the game respectfully. 
	
# <a name="expansions"></a>Further Expansions
	If I was to further expand upon this game I would include a bigger set of 
	isograms, including more commonly known words and more varied lengths. This 
	would allow the seperation of word sets and allow the user to be able to 
	choose between different difficulties that would range from the different 
	word lengths and amount of tries given. It would also be nice to create a 
	GUI so that the user would be able to play the game more visually, rather 
	than through the plain command-line. Another thought would be to have 
	different categories of words for the player to choose from, such as 
	Places, foods, actions, etc, depending on the list of words.