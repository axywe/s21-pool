#ifndef DATA_IO_MACRO
#define DATA_IO_MARCO

#define input(a, n)                   \
    {                                 \
        for (int i = 0; i < n; i++) { \
            scanf("%lf", (a + i));    \
        }                             \
    }

#define output(a, n)                        \
    {                                       \
        for (int i = 0; i < n; i++) {       \
            if (i == n - 1)                 \
                printf("%.2lf", *(a + i));  \
            else                            \
                printf("%.2lf ", *(a + i)); \
        }                                   \
    }

#endif