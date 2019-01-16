#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define inputfile "database.txt"

void findWord(char []);
int answerCheck(char[]);

int main(void) {
	char output[50];
	int score=0;
	int game = 1;
	
	while (game==1) {
		findWord(output);
		if (answerCheck(output) != 1) {
			printf("Wrong! Your score is %d Would you like to continue playing? 1 for yes and 0 for no: ", score);
			scanf("%d", &game);
			if (game != 0) {
				game = 1;
				score = 0;
			}
		}
		else
			score++;
	}
}

void findWord(char output[]) {
	FILE* inFile;
	inFile = fopen(inputfile, "r");

	srand((unsigned)time(NULL));

	int index = 0;

	int word = rand() % 9897 + 1;
	while (fscanf(inFile, "%s", output) == 1) {
		index++;
		if (index == word) {
			break;
		}
	}

	printf("%s\n", output);
}

int answerCheck(char output[]) {
	char answer[50];

	scanf("%s", answer);

	int index = 0;
	while (answer[index] != NULL) {
		index++;
		if (answer[index] != output[index]) {
			return 0;
		}
	}
	return 1;
}