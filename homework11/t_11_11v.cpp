#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int passenger_id;
    int item_count;
    float total_weight;
} Baggage;

int main() {
    FILE *file = fopen("/Users/lina/CLionProjects/proghome2/prog2coursecpp/homework11/input2.txt", "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    Baggage baggage, min_baggage;
    int min_items = __INT_MAX__;
    float min_weight = __FLT_MAX__;

    while (fscanf(file, "%d %d %f", &baggage.passenger_id, &baggage.item_count, &baggage.total_weight) == 3) {
        if (baggage.item_count < min_items ||
            (baggage.item_count == min_items && baggage.total_weight <= min_weight)) {
            min_items = baggage.item_count;
            min_weight = baggage.total_weight;
            min_baggage = baggage;
            }
    }

    fclose(file);

    printf("Passenger with smallest item count and minimum weight:\n");
    printf("Passenger ID: %d, Items: %d, Weight: %.2f\n", min_baggage.passenger_id, min_baggage.item_count, min_baggage.total_weight);

    return 0;
}

