#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdbool.h>

#define MAX_MAZE_SIZE (1 * 1024 * 1024)

struct map_t {
    size_t width;
    size_t height;
    size_t start_x;
    size_t start_y;
    size_t end_x;
    size_t end_y;
    bool *walls;
};

int main(int argc, char const *argv[]);
bool dfs(const struct map_t *map, bool *visited, char *visual, const size_t x, const size_t y);

#endif
