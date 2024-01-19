#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <range X> <range Y>\n", argv[0]);
        return 1;
    }

    int maxX = atoi(argv[1]);
    int maxY = atoi(argv[2]);

    if (maxX <= 0 || maxY <= 0) {
        printf("Ranges must be greater than 0.\n");
        return 1;
    }

    srand(time(NULL));

    int questions = 0, correct = 0, incorrect = 0;
    time_t start_time = time(NULL);

    while (1) {
        int num1 = rand() % maxX + 1;
        int num2 = rand() % maxY + 1;

        printf("What is %d * %d? (Enter 0 or less to exit): ", num1, num2);

        int answer;
        scanf("%d", &answer);

        if (answer <= 0) {
            break;
        }

        if (answer == num1 * num2) {
            printf("Correct!\n");
            correct++;
        } else {
            printf("Incorrect. The correct answer is %d.\n", num1 * num2);
            incorrect++;
        }

        questions++;
    }

    time_t end_time = time(NULL);
    int quiz_time = (int)(end_time - start_time);

    printf("\nQuiz statistics:\n");
    printf("Number of questions: %d\n", questions);
    printf("Number of correct answers: %d\n", correct);
    printf("Number of incorrect answers: %d\n", incorrect);
    printf("Quiz time: %d seconds\n", quiz_time);

    return 0;
}
