#include "./include/header.h"

#include <unistd.h>
#include <stdlib.h>

#define SIZE 30

char map[SIZE][SIZE];

pos current_dot;

player snake;

void init_map()
{
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            map[i][j] = ' ';
        }

    }
}

pos gen_random()
{
    pos tmp;
    tmp.x = (rand() % SIZE + 1);
    tmp.y = (rand() % SIZE + 1);
    return tmp;
}

int eq_pos(pos first, pos second)
{
    if (first.x == second.x && first.y == second.y)
        return 1;
    return 0;
}

void dot_to_map()
{
    map[current_dot.x][current_dot.y] = ' ';
    pos dot = gen_random();
    map[dot.x][dot.y] = 'x';
    current_dot.x = dot.x;
    current_dot.y = dot.y;
}

void player_to_map(int init)
{
    char mov;
    map[snake.head.x][snake.head.y] = ' ';
    if (init == 1)
        goto end;
    read(1, &mov, 1);
    if (mov == 'h') {
        if (snake.head.y == 0)
            snake.head.y = SIZE - 1;
        else
            snake.head.y -= 1;
    } else if (mov == 'j') {
        if (snake.head.x == SIZE - 1)
            snake.head.x = 0;
        else
            snake.head.x += 1;
    } else if (mov == 'k') {
        if (snake.head.x == 0)
            snake.head.x = SIZE - 1;
        else
            snake.head.x -= 1;
    } else if (mov == 'l') {
        if (snake.head.y == SIZE - 1)
            snake.head.y = 0;
        else
            snake.head.y += 1;
    } else if (mov == 'q') {
        exit(0);
    }
    end:
    map[snake.head.x][snake.head.y] = '#';
}

void print_map()
{
    int i;
    write(1, CLR, 5);
    write(1, RET, 4);
    for (i = 0; i < SIZE; i++) {
        write(1, map[i], SIZE);   // prints the map line by line
        write(1, "|\n", 2);     // faster than char by char.
    }
    for (i = 0; i < SIZE; i++)
        write(1, "-", 1);
    write(1, "\n", 1);
}

int main(int arc, char **arv, char **env)
{
    int i = 0;
    init_map();
    while (++i) {
        if (!(i % (SIZE * 2)) || i == 1)
            dot_to_map();
        player_to_map(i);
        print_map();
    }
    return 0;
}
