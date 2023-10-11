#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

#define MAX_NUM 10000

struct vec {
    int len;
    int *data;
};
typedef struct vec vec_t;

int get_vec_element(vec_t* v, int idx, int *val)
{
    assert(v);

    if (idx >= v->len)
        return 0;

    *val = v->data[idx];
    return 1;
}

int vec_length(vec_t* v)
{
    assert(v);
    return v->len;
}

void combine(vec_t* v, int *dest)
{
    assert(dest);
    *dest = 0;

    for (int i = 0; i < v->len; i++) {
        *dest += v->data[i];
    }
}

void init(vec_t* v)
{
    assert(v);
    v->len = MAX_NUM;
    v->data = (int*)malloc(sizeof(int) * MAX_NUM);

    // Initialize data
    for (int i = 0; i < MAX_NUM; i++)
        v->data[i] = i;
}

void cleanup(vec_t* v)
{
    assert(v);
    free(v->data);
}

int main()
{
    printf("This is the optimized version .. \n");

    vec_t info;
    int result;
    // Initialize
    init(&info);

    // Combine
    combine(&info, &result);
    printf("Combined value = %d\n", result);

    // Clean up
    cleanup(&info);

    return 0;
}
