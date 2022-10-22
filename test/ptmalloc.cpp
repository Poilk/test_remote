//
// Created by 文欣 on 2022/4/29.
//

/* test_memory.c
 * gcc -g -O0 -W test_memory.c -o tm123 && ./tm123 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BLOCK_CNT (256 * 1024)
#define BLOCK_SIZE (4 * 1024)

int main() {
    void *p = new int;
    void *null = NULL;
    printf("%lld, %lld, %lld, %lld\n", p, (int64_t)(int64_t *) p, null, (int64_t)(int64_t *) null);
    int i;
    char *addr, *blks[BLOCK_CNT];

    for (i = 0; i < BLOCK_CNT; i++) {
        blks[i] = (char *)malloc(BLOCK_SIZE * sizeof(char));
    }

    addr = (char *)malloc(2 * sizeof(char));

    for (i = 0; i < BLOCK_CNT; i++) {
        free(blks[i]);
    }

    // free(addr);
    // malloc_trim(0);

    //malloc_stats();
    for (;;) {
        sleep(1);
    }

    return 0;
}