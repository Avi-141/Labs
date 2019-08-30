#include <stdlib.h>
#include <string.h>
 
static void maximum_clique_recursive(const unsigned int **adjmat, unsigned int order, 
        unsigned int *current_clique, unsigned int *current_clique_size, unsigned int *max_clique,
        unsigned int *max_clique_size, unsigned int level)
{
    unsigned int i, connected;
    if (level == order) {
        /* Found a new max clique */
        memcpy(max_clique, current_clique, order * sizeof(unsigned int));
        *max_clique_size = *current_clique_size;
        return;
    }
    /* Find out if current vertex is connected to all vertices in current clique */
    connected = 1;
    for (i = 0; i < level && connected; i++) {
        if (current_clique[i] && !adjmat[level][i]) {
            connected = 0;
        }
    }
 
    if (connected) {
        /* Add this vertex to the clique */
        current_clique[level] = 1;
        (*current_clique_size)++;
        maximum_clique_recursive(adjmat, order, current_clique, current_clique_size, max_clique, 
                max_clique_size, level + 1);
        (*current_clique_size)--;
    }
    if (*current_clique_size + order - level > *max_clique_size) {
        /* Still promising */
        current_clique[level] = 0;
        maximum_clique_recursive(adjmat, order, current_clique, current_clique_size, max_clique, 
                max_clique_size, level + 1);
    }
}
 
unsigned int maximum_clique(const unsigned int **adjmat, unsigned int order, 
        unsigned int **max_clique)
{
    unsigned int max_clique_size = 0;
    unsigned int current_clique_size = 0;
    unsigned int *current_clique = malloc(order * sizeof(unsigned int));
    *max_clique = malloc(order * sizeof(unsigned int));
    if (current_clique == NULL || *max_clique == NULL) {
        free(current_clique);
        free(max_clique);
        return 0;
    }
    maximum_clique_recursive(adjmat, order, current_clique, &current_clique_size, *max_clique, 
            &max_clique_size, 0);
    free(current_clique);
    return max_clique_size;
}