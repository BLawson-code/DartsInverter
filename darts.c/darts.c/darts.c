#include <stdio.h>

int calculateScore(int wedgeHit) {
	int opposites[] = { -1, 19, 12, 20, 16, 17, 11, 18, 13, 15, 14, 6, 2, 8, 10, 9, 4, 5, 7, 1, 3 };
	int opposite = -1;
	if (wedgeHit <= 0 || wedgeHit > 20) {
		opposite = -1;
	}
	else {
		opposite = opposites[wedgeHit];
	}
	return opposite;
}

int obtainUserInput() {
	int userInput;

	printf("Please enter the number hit by the dart. Enter 0 to exit ");
	scanf_s("%d", &userInput);

	while (userInput < 0 || userInput > 20) {
		printf("Sorry, invalid input. Please enter the number hit by the dart or 0 to exit: ");
		scanf_s("%d", &userInput);
	}
	return userInput;
}

int main() {
	const int throwsPerRound = 5;

	int throwNumber = 1;
	int totalScore = 0;
	int playing = 1;

	while (playing) {
		int userInput = obtainUserInput();

		if (userInput > 0) {
			int throwScore = calculateScore(userInput);
			totalScore += throwScore;
			printf("Throw number %d: You scored %d; your total score is %d.\n", throwNumber, throwScore, totalScore);
			throwNumber++;
			if (throwNumber > throwsPerRound) {
				printf("Round over. \n\n");
				throwNumber = 1;
				totalScore = 0;
			}
		}
		else {
			playing = 0;
		}
	}
}