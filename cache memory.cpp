#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int generateRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}
int main() {
    srand(time(NULL));
    const int CACHE_SIZE = 8;
    const int NUM_VALUES = 64;
    int cache[CACHE_SIZE];
    int values[NUM_VALUES];
    int i, j;
    int hit = 0;
    int miss = 0;
    for (i = 0; i < NUM_VALUES; i++) {
        values[i] = generateRandomNumber(0, NUM_VALUES - 1);
    }

    for (i = 0; i < NUM_VALUES; i++) {
        int value = values[i];
        int inCache = 0;
        for (j = 0; j < CACHE_SIZE; j++) {
            if (cache[j] == value) {
                inCache = 1;
                break;
            }
        }
        if (inCache) {
            printf("Cache hit at index %d\n", value);
            hit++;
        } else {
            printf("Cache miss at index %d\n", value);
            miss++;
            int oldestValueIndex = generateRandomNumber(0, CACHE_SIZE - 1);
            cache[oldestValueIndex] = value;
        }
    }
    printf("Total cache misses: %d\n", miss);
    printf("Total cache hits: %d\n", hit);
    return 0;
}