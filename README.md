=========================================================================
                                HANGMAN
                    University College Dublin
            EEEN20010 - Computer Engineering I Lab 2
                      Developed by Jeremy Trane
                              15 Nov 2019
=========================================================================

1. DESCRIPTION:

   This program simulates the traditional game of Hangman. The user provides
   a filename containing the word to be guessed. The word is masked, and the 
   player has to guess letters or the whole word.

2. HOW TO RUN:

   $ gcc -o hangman hangman.c
   $ ./hangman

3. USAGE:

   - Enter the filename containing the word to guess.
   - You'll be shown a masked word, where each letter is represented by '*'.
   - You get 10 lives.
   - Choose between:
       - [w] Guess the whole word.
       - [l] Guess a letter in the word.
   - If you guess correctly, the mask reveals the letter(s).
   - Run out of lives or guess the word to end the game.

4. FILES:

   hangman.c         - The main source code for the Hangman game.

5. FUNCTIONS:

   removeNewLine     - Removes newlines from strings.
   containsChar      - Checks if a word contains a given character.
   guessWord         - Allows the user to guess the entire word.
   guessLetter       - Allows the user to guess a single letter in the word.

6. NOTES:

   - The word file should contain only one word and not exceed 20 characters.
   - Word guessing is case sensitive.
   - Ensure the file provided exists and is accessible to avoid errors.

=========================================================================
