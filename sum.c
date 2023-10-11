#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<limits.h>

//#define MAX_NUM 100000000
//#define MAX_NUM 10000
#define MAX_NUM 100000
//#define MAX_NUM 1000000000
//#define MAX_NUM INT_MAX
//#define MAX_NUM 100000

struct vec {
	int len;
	int *data;
};
typedef struct {
	size_t len;
	data_t *data;
	vec_ptr vec_t;
}

int get_vec_element(vec_ptr v, size_t idx, data_t *val)
{
	assert(v);

	if(idx >= v->len)
		return 0;

	*val = v->data[idx];
	return 1;
}

int vec_length(vec_ptr* v)
{
	assert(v);
	return v->len;
}

void combine_go(vec_ptr v, data_t *dest)
{
	long i;
	long length = vec_length(v);
	data_t *d = get_vec_start(v);
	data_t t = IDENT;
	for (i = 0; i < length; i++)
		t = t OP d[i];
	*dest = t;
}

data_t* get_vec_start(vec_ptr v){
	return v-> data;
}

void init(vec_t* v)
{
	assert(v);
	v->len = MAX_NUM;
	v->data = (int*) malloc(sizeof(int) * MAX_NUM);

	// init 
	for(int i = 0; i < MAX_NUM; i++)
		v->data[i] = i;
}

int main()
{
	printf("This is the naive version .. \n");

	vec_ptr info; 
	int result; 
	// init 
	init(&info);

	// combine 
	combine_go(&info, &result);
	//printf("combined val = %d\n", result);

	return 0;
}
