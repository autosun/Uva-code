/**
 * Box of Bricks
 */

#include <stdio.h>
#include <math.h>

#define MAX_N 55

int main() {
    int iteration = 0;
    int nu_stacks, moves, average, i;
    int stack[MAX_N];

    scanf("%d", &nu_stacks);

    while (nu_stacks != 0) {

        average = 0;
        moves = 0;

        for (i = 0; i < nu_stacks; ++i) {
            scanf("%d", stack + i);
            average += stack[i];
        }
        average /= nu_stacks;

        for (i = 0; i < nu_stacks; ++i) {
            moves += abs(stack[i] - average);
        }
        moves /= 2;

        printf("Set #%d\n", ++iteration);
        printf("The minimum number of moves is %d.\n\n", moves);

        scanf("%d", &nu_stacks);
    }

    return 0;
}

