#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "main.h"

int main(int argc, char const *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <map file>\n", argv[0]);
    return 1;
  }

  // 1. Read the file

  FILE *file = fopen(argv[1], "r");
  if (!file) {
    fprintf(stderr, "Error opening file %s\n", argv[1]);
    return 2;
  }

  char visual[MAX_MAZE_SIZE];
  size_t length = fread(visual, 1, MAX_MAZE_SIZE, file);
  fclose(file);

  // 2. Parse the map, find the start/end points

  bool walls[MAX_MAZE_SIZE];
  memset(walls, false, sizeof(bool) * length);

  int start_x = -1, start_y = -1, end_x = -1, end_y = -1, width = -1;
  for (size_t i = 0; i < length; ++i) {
    size_t x = width == -1 ? i : i % (width + 1), y = width == -1 ? 0 : i / (width + 1);

    switch (visual[i]) {
    case '\n':
      if (width == -1)
        width = i;
      break;
    
    case '1':
      start_x = x;
      start_y = y;
      break;

    case '2':
      end_x = x;
      end_y = y;
      break;

    case '*':
      walls[i - y] = true;
      break;

    case ' ':
      break;
    }
  }

  size_t height = (length + 1) / (width + 1);

  struct map_t map = { width, height, start_x, start_y, end_x, end_y, walls };

  // 3. Perform a depth-first search

  bool visited[MAX_MAZE_SIZE];
  memset(visited, false, sizeof(bool) * map.width * map.height);

  bool solution = dfs(&map, visited, visual, map.start_x, map.start_y);

  // 4. Print the solution

  if (!solution) {
    printf("No solution.\n");
    return 3;
  }

  visual[map.start_x + map.start_y * (map.width + 1)] = '1';
  visual[(map.width + 1) * map.height] = '\0';
  printf("%s\n", visual);

  return 0;
}

// Depth-first search
bool dfs(const struct map_t *map, bool *visited, char *visual, const size_t x, const size_t y) {
  size_t i = x + y * map->width;
  if (x == map->end_x && y == map->end_y) return true;
  if (visited[i] || map->walls[i]) return false;

  visited[i] = true;

  // Go left
  if (x != 0 && dfs(map, visited, visual, x - 1, y)) {
    visual[i + y] = '.';
    return true;
  }

  // Go right
  if (x != map->width - 1 && dfs(map, visited, visual, x + 1, y)) {
    visual[i + y] = '.';
    return true;
  }

  // Go up
  if (y != 0 && dfs(map, visited, visual, x, y - 1)) {
    visual[i + y] = '.';
    return true;
  }

  // Go down
  if (y != map->height - 1 && dfs(map, visited, visual, x, y + 1)) {
    visual[i + y] = '.';
    return true;
  }

  return false;
}
