#include <io.h>
#include <rand.h>

char *outcomes[] = {
    "heads", "tails", "tails", "heads"
};

int ksh_flip_coin() {
    int rand_index = (rand() % 4);

    char *outcome = "";

    outcome = outcomes[rand_index];

    printf("%d: %s\n", rand_index, outcome);
}
