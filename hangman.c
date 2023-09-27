/*==================================================================
 *
 *               University College Dublin
 *          EEEN20010 - Computer Engineering I Lab 2
 *                     "Game of Hangman"
 *
 * File Name:   hangman.c
 *
 * The user inputs the name of a file and the word inside the file and is then used in a game of hangman.
 *
 * Author:      Jeremy Trane
 *
 * Date:        15 Nov 2019
 *
 *==================================================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define READONLY "r"
#define MAX_WORD_LENGTH 20

void removeNewLine(char *string);
int containsChar(const char *word, char ch);
void guessWord(const char *answer, char *hiddenWord, int *lives);
void guessLetter(const char *answer, char *hiddenWord, int *lives);

int main(void) {
    char cont = 'y';

    while(cont == 'y') {
        char answer[MAX_WORD_LENGTH] = "";
        FILE *fPointer;
        char fileName[MAX_WORD_LENGTH];

        printf("Give the filename with the unknown word: ");
        scanf("%s", fileName);

        if ((fPointer = fopen(fileName, READONLY)) == NULL) {
            printf("Failed to open file\n");
            exit(1);
        }

        fgets(answer, MAX_WORD_LENGTH, fPointer);
        removeNewLine(answer);
        fclose(fPointer);

        int lives = 10;
        char hiddenWord[MAX_WORD_LENGTH] = "";
        strncpy(hiddenWord, answer, strlen(answer));
        for (int i = 0; i < strlen(answer); i++) {
            hiddenWord[i] = '*';
        }

        printf("Ready to Start!\nThe word is: %s\n\n", hiddenWord);

        while (lives > 0) {
            char preference;
            printf("Number of turns remaining: %d\nWould you like to guess the word [w] or guess a letter [l]: ", lives);
            scanf(" %c", &preference);

            if (preference == 'w') {
                guessWord(answer, hiddenWord, &lives);
            } else {
                guessLetter(answer, hiddenWord, &lives);
            }

            if (strcmp(answer, hiddenWord) == 0) {
                printf("Congratulations!\n");
                break;
            }

            if (lives == 0) {
                printf("You have lost, the word was %s\n", answer);
            }
        }

        printf("***********************************************\n");
        printf("Do you want to play again [y/n]:");
        scanf(" %c", &cont);

        while (cont != 'n' && cont != 'y') {
            printf("Please enter either y for yes to restart the program or n for no to terminate the program:");
            scanf(" %c", &cont);
        }
    }

    return 0;
}

void removeNewLine(char *string) {
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == '\n') {
            string[i] = '\0';
        }
    }
}

int containsChar(const char *word, char ch) {
    for (int i = 0; i < strlen(word); i++) {
        if (word[i] == ch) {
            return 1;
        }
    }
    return 0;
}

void guessWord(const char *answer, char *hiddenWord, int *lives) {
    char wordGuess[MAX_WORD_LENGTH];
    printf("What is your guessed word?:");
    scanf("%s", wordGuess);

    if (strcmp(answer, wordGuess) == 0) {
        strncpy(hiddenWord, answer, strlen(answer));
        printf("Congratulations!\n\n");
    } else {
        printf("Bad Choice\nThe word is: %s\n", hiddenWord);
        (*lives)--;
    }
}

void guessLetter(const char *answer, char *hiddenWord, int *lives) {
    char characterGuess;
    printf("What letter have you chosen?:");
    scanf(" %c", &characterGuess);

    if (containsChar(answer, characterGuess)) {
        for (int i = 0; i < strlen(answer); i++) {
            if (answer[i] == characterGuess) {
                hiddenWord[i] = characterGuess;
            }
        }
        printf("Good choice!\nThe word is: %s\n", hiddenWord);
    } else {
        (*lives)--;
        printf("Bad Choice\nThe word is: %s\n", hiddenWord);
    }
}
