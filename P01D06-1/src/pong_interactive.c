#include <ncurses.h>
#include <stdio.h>

void draw(int, int, int, int, int, int, int);  //Функция рисования поля
int ball_x(int, int);                          //Функция движения мяча по оси Х
int ball_y(int, int);                          //Функция движения мяча по оси Y
int direction(int, int, int, int, int);  //Функция направления движения мяча

int main(void) {
    initscr();  //Функция инициализации окна и настроек
    noecho();
    curs_set(0);
    mvprintw(15, 30, "Press any key to start...");
    char c;
    int r1 = 12, r2 = 12, b_x = 39, b_y = 12, dir = 1, s1 = 0, s2 = 0, w = 0;
    do {
        c = getch();  //Сохранение введенного символа в переменную 'c'
        draw(r1, r2, b_x, b_y, s1, s2,
             w);  //Инициализация начальных положений ракеток и мяча, значений счета и флаг победы w
        if ((c == 'k' || c == 'K') && r2 > 1) {
            r2--;
        } else if ((c == 'm' || c == 'M') && r2 < 23) {
            r2++;
        } else if ((c == 'a' || c == 'A') && r1 > 1) {
            r1--;
        } else if ((c == 'z' || c == 'Z') && r1 < 23) {
            r1++;
        }
        b_x = ball_x(b_x, dir);  //Функция обновления положения мяча по оси x
        b_y = ball_y(b_y, dir);  //Функция обновления положения мяча по оси y
        dir = direction(b_x, b_y, dir, r1,
                        r2);  //Функция проверки и обновления направления мяча в пространстве поля
        if (dir == 6) {
            s1++;
            r1 = 12, r2 = 12, b_x = 39, b_y = 12, dir = 1, w = 0;
        } else if (dir == 7) {
            s2++;
            r1 = 12, r2 = 12, b_x = 39, b_y = 12, dir = 4, w = 0;
        }
        if (s1 == 21) {
            w = 1;
            break;
        } else if (s2 == 21) {
            w = 2;
            break;
        }
        timeout(50);  //Число обновления итераций
    } while (1);      //Основной игровой цикл
    draw(r1, r2, b_x, b_y, s1, s2, w);  //Функция вывода игрового поля и описывающая состояние игры
    while (1) {
        mvprintw(15, 30, "Player %d wins!", w);  //Фраза выводимая при победе
        mvprintw(16, 30, "Press \"Space\" to exit");  //Фраза выводимая для окончания программы
        c = getch();
        if (c == 32) break;
    }
    endwin();
    return 0;
}

// Racket 1, Racket 2, Ball - x, Ball - y, Directory, Score 1, Score 2

void draw(int r1, int r2, int b_x, int b_y, int s1, int s2, int w) {
    clear();
    printw("\nplayer 1");
    for (int i = 0; i < 29; i++) printw("%1c", 32);
    printw("%.2d|%.2d", s1, s2);
    for (int i = 0; i < 30; i++) printw("%1c", 32);
    printw("player 2\n");
    for (int i = 0; i < 80; i++)
        printw("%c", 61);  //Верхняя граница поля сделанная при помощи символьной графики
    printw("\n");
    for (int y = 0; y <= 24; y++) {
        for (int x = 0; x < 80; x++) {
            if ((r1 <= 23 && r1 >= 1) && (y == r1 || y == r1 + 1 || y == r1 - 1) && (x == 1) && w == 0) {
                printw("%c", 124);
            } else if ((r2 <= 23 && r2 >= 1) && (y == r2 || y == r2 + 1 || y == r2 - 1) && (x == 78) &&
                       w == 0) {
                printw("%c", 124);
            } else if (x == b_x && y == b_y && w == 0) {
                printw("%c", 42);
            } else {
                printw(" ");
            }
        }
        printw("\n");
    }
    for (int i = 0; i < 80; i++)
        printw("%c", 61);  //Нижняя граница поля сделанная при помощи символьной графики
    printw("\n");
    return;
}

int ball_x(int b_x, int dir) {
    switch (dir) {
        case 0:  //Право-верх
        case 1:  //Право
        case 2:  //Право-низ
            b_x++;
            break;
        case 3:  //Лево-низ
        case 4:  //Лево
        case 5:  //Лево-верх
            b_x--;
            break;
    }
    return b_x;
}

int ball_y(int b_y, int dir) {
    switch (dir) {
        case 0:  //Право-верх
        case 5:  //Лево-верх
            b_y--;
            break;
        case 2:  //Право-низ
        case 3:  //Лево-низ
            b_y++;
            break;
    }
    return b_y;
}

int direction(int b_x, int b_y, int dir, int r1, int r2) {
    mvprintw(0, 35, "%d %d %d", r1, b_x, r2);
    if (b_x == 77) {
        if (r2 == b_y)
            dir = 4;  //направление прямо влево
        else if (r2 - 1 == b_y)
            dir = 3;  //направление вниз влево
        else if (r2 + 1 == b_y)
            dir = 5;  //направление вверх влево
        else
            return 6;
    } else if (b_x == 2) {
        if (r1 == b_y)
            dir = 1;  //направление прямо вправо
        else if (r1 - 1 == b_y)
            dir = 2;  //направление вниз вправо
        else if (r1 + 1 == b_y)
            dir = 0;  //направление вверх вправо
        else
            return 7;
    }
    if (b_y == 0 || b_y == 24) {
        if (dir == 0)
            dir = 2;
        else if (dir == 5)
            dir = 3;
        else if (dir == 2)
            dir = 0;
        else
            dir = 5;
    }
    return dir;
}