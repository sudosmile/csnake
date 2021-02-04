#ifndef HEADER_H_
#define HEADER_H_

#define CLR     "\033[2J"
#define RET     "\033[H"
#define RESET   "\x1b[0m"
#define BOLD    "\x1b[1m"
#define BLACK   "\x1b[30m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define WHITE   "\x1b[37m"

typedef struct {
    int x, y;
} pos;

typedef struct player{
    pos head;
    struct player *next;
} player;

#endif /* HEADER_H_ */
