#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 25
#define LENGTH 80

int **alloc(int row, int column);
void color(int c);
void draw(int **matrix, int speed, int gen);
int live(int **matrix, int i, int j);
int init(int **matrix);
int change_matrix(int **matrix);

int main() {
    int **matrix = alloc(WIDTH, LENGTH);
    int STATUS = 0;
    if (isatty(0)) STATUS = 1;
    if (STATUS == 0 && matrix != NULL && init(matrix) == 0) STATUS = 1;
    FILE *tty = freopen("/dev/tty", "r", stdin);
    if (tty != NULL && STATUS == 0 && matrix != NULL) {
        initscr();
        cbreak();
        noecho();
        curs_set(0);
        start_color();
        init_pair(1, COLOR_WHITE, COLOR_BLACK);
        init_pair(2, COLOR_WHITE, COLOR_WHITE);
        init_pair(3, COLOR_BLUE, COLOR_BLUE);
        attron(COLOR_PAIR(1));
        mvprintw(10, LENGTH / 2 - 11, "T h e  G a m e   o f  L i f e");
        mvprintw(15, LENGTH / 2 - 10, "Press any key to start...");
        int speed = 50;
        char s = 0, c = 0;
        int generation = 0;
        while (1) {
            s = getch();
            if ((s == 66) && (speed < 2000)) speed += 10;
            if ((s == 65) && (speed > 10)) speed -= 10;
            draw(matrix, speed, ++generation);
            timeout(speed);
            if ((change_matrix(matrix) == 0) || (s == 113)) break;
        };
        while (1) {
            if ((c == 32) || (s == 113)) break;
            mvprintw(15, 30, "Game over!");
            mvprintw(16, 30, "Press \"Space\" to exit");
            c = getch();
        }
        attroff(COLOR_PAIR(1));
        endwin();
    }
    if (matrix == NULL || STATUS == 1) printf("Error while starting game!");
    if (matrix != NULL) free(matrix);
    return STATUS;
}

int **alloc(int row, int column) {
    int **arr = (int **)malloc(row * column * sizeof(int) + row * sizeof(int *));
    int *ptr = (int *)(arr + row);
    for (int r = 0; r < row; r++) {
        arr[r] = ptr + column * r;
    }
    return arr;
}

void color(int c) {
    attron(COLOR_PAIR(c));
    printw("#");
    attroff(COLOR_PAIR(c));
}

void draw(int **matrix, int speed, int gen) {
    clear();
    for (int i = 0; i < WIDTH + 2; i++) {
        for (int j = 0; j < LENGTH + 2; j++) {
            if (i == 0 || i == WIDTH + 1)
                color(3);
            else if (j == 0 || j == LENGTH + 1)
                color(3);
            else if (matrix[i - 1][j - 1] == 1)
                color(2);
            else
                printw(" ");
        }
        printw("\n");
    }
    color(3);
    mvprintw(27, LENGTH / 2 - 20, "Speed: %.1lf gen/sec", 1000.0 / speed);
    color(3);
    mvprintw(27, LENGTH - 21, "Generation: %10d", gen);
    color(3);
    printw("\n");
    for (int i = 0; i < LENGTH + 2; i++) color(3);

    refresh();
}

int live(int **matrix, int i, int j) { return matrix[(i + WIDTH) % WIDTH][(j + LENGTH) % LENGTH]; }

int change_matrix(int **matrix) {
    int **matrix_copy = alloc(WIDTH, LENGTH);
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < LENGTH; j++) {
            matrix_copy[i][j] = matrix[i][j];
        }
    }
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < LENGTH; j++) {
            int counter = 0;
            counter = live(matrix, i - 1, j - 1) + live(matrix, i, j - 1) + live(matrix, i + 1, j - 1) +
                      live(matrix, i - 1, j) + live(matrix, i + 1, j) + live(matrix, i + 1, j + 1) +
                      live(matrix, i - 1, j + 1) + live(matrix, i, j + 1);
            if (counter == 3)
                matrix_copy[i][j] = 1;
            else if ((counter == 2) && (matrix[i][j] == 1))
                matrix_copy[i][j] = 1;
            else
                matrix_copy[i][j] = 0;
        }
    }
    int edit = 0, ones = 0;
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < LENGTH; j++) {
            if (matrix[i][j] != matrix_copy[i][j]) edit++;
            if (matrix_copy[i][j] == 1) ones++;
            matrix[i][j] = matrix_copy[i][j];
        }
    }
    if (matrix_copy != NULL) free(matrix_copy);
    return edit == 0 ? edit : ones;
}

int init(int **matrix) {
    char c;
    int STATUS = 1;
    for (int i = 0; i < WIDTH && STATUS == 1; i++) {
        for (int j = 0; j < LENGTH + 1 && STATUS == 1; j++) {
            scanf("%c", &c);
            if (c == '0')
                matrix[i][j] = 0;
            else if (c == '1')
                matrix[i][j] = 1;
            else if (c != '\n' && j != LENGTH + 1)
                STATUS = 0;
        }
    }
    return STATUS;
}
