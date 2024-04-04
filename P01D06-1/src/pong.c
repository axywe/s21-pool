#include <stdio.h>

void draw(int, int, int, int, int, int, int);         //Функция рисования поля
void insert(int, int, int, int, int, int, int, int);  //Функция ввода движения ракеток
void reset(int, int, int);  //Функция обнуления позиций и проверки счета после гола
int ball_x(int, int);                    //Функция движения мяча по оси Х
int ball_y(int, int);                    //Функция движения мяча по оси Y
int direction(int, int, int, int, int);  //Функция направления движения мяча

int main(void) {
    insert(12, 12, 39, 12, 1, 0, 0, 0);  //Вставка стартовых позиций
    return 0;
}

void reset(int dir, int s1, int s2) {
    int w = 0;  //счетчик победы первого или второго игрока
    if (s1 == 21) {
        w = 1;
    } else if (s2 == 21) {
        w = 2;
    }
    insert(12, 12, 39, 12, dir, s1, s2, w);
    return;
}

// Racket 1, Racket 2, Ball - x, Ball - y, Directory, Score 1, Score 2

void insert(int r1, int r2, int b_x, int b_y, int dir, int s1, int s2, int w) {
    draw(r1, r2, b_x, b_y, s1, s2, w);
    if (w != 0) return;
    char c;
    scanf("%c", &c);  //ввод клавиш движения ракеток
    if ((c == 'k' || c == 'K') && r2 > 1) {
        r2--;
    } else if ((c == 'm' || c == 'M') && r2 < 23) {
        r2++;
    } else if ((c == 'a' || c == 'A') && r1 > 1) {
        r1--;
    } else if ((c == 'z' || c == 'Z') && r1 < 23) {
        r1++;
    }
    b_x = ball_x(b_x, dir);
    b_y = ball_y(b_y, dir);
    dir = direction(b_x, b_y, dir, r1, r2);  //счетчик направления движения мяча и голов
    if (dir == 6) {
        s1++;
        dir = 1;
        reset(dir, s1, s2);  //обнуление позиций ракеток и мяча после гола первого игрока
        return;
    } else if (dir == 7) {
        s2++;
        dir = 4;
        reset(dir, s1, s2);  //обнуление позиций ракеток и мяча после гола второго игрока
        return;
    }
    insert(r1, r2, b_x, b_y, dir, s1, s2, w);
    return;
}

void draw(int r1, int r2, int b_x, int b_y, int s1, int s2, int w) {
    printf("\nplayer 1");
    for (int i = 0; i < 29; i++) printf("%1c", 32);
    printf("%.2d|%.2d", s1, s2);  //отрисовка счета
    for (int i = 0; i < 30; i++) printf("%1c", 32);
    printf("player 2\n");
    for (int i = 0; i < 80; i++) printf("=");  //верхняя граница поля
    printf("\n");
    for (int y = 0; y < 25; y++) {
        for (int x = 0; x < 80; x++) {
            if ((r1 <= 23 && r1 >= 1) && (y == r1 || y == r1 + 1 || y == r1 - 1) && (x == 1) && w == 0) {
                printf("|");
            } else if ((r2 <= 23 && r2 >= 1) && (y == r2 || y == r2 + 1 || y == r2 - 1) && (x == 78) &&
                       w == 0) {
                printf("|");
            } else if (x == b_x && y == b_y && w == 0) {
                printf("*");
            } else if (w != 0 && y == 12 && x == 32) {
                printf("Player %d wins!", w);
                x = 60;
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    for (int i = 0; i < 80; i++) printf("=");  //нижняя граница поля
    printf("\n");
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
        case 5:  //Право
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
    printf("%d %d %d", r2, b_x, b_y);
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