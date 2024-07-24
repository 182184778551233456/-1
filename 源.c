#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int DataType;
typedef struct SqList {
	DataType *memory;
	int count;
	int maxSize;
}Sqlist;

Sqlist* creat_sqlist(void) {
	Sqlist* sqlist = (Sqlist*)calloc(1, sizeof(Sqlist));
	assert(sqlist);
	return sqlist;
}

void insert_qlist(Sqlist* sqlist, DataType data) {
	assert(sqlist);
	if (sqlist->count == sqlist->maxSize) {
		sqlist->maxSize += 10;
		DataType* temp = (DataType*)realloc(sqlist->memory, sqlist->maxSize * sizeof(DataType));
		assert(temp);
		sqlist->memory = temp;
	}

#if 0
	sqlist->memory[sqlist->count++] = data;

#endif

	sqlist->memory[sqlist->count] = data;
	for (int i = sqlist->count; i > 0; i--) {
		if (sqlist->memory[i - 1] > sqlist->memory[i]) {
			DataType temp = sqlist->memory[i];
			sqlist->memory[i] = sqlist->memory[i - 1];
			sqlist->memory[i - 1] = temp;
		}
		else {
			break;
		}
	}
	sqlist->count++;
}

void print_sqlist(Sqlist* sqlist) {
	assert(sqlist);
	for (int i = 0; i < sqlist->count; i++)
		printf("%d ", sqlist->memory[i]);
}

void ereas_sqlist_index(Sqlist*sqlist,int index) {
	assert(sqlist);
	if (index <= 0 || index > sqlist->count) {
		printf("ÎŞĞ§ĞòºÅ\n");
		return;
	}
	for (int i = index - 1; i < sqlist->count - 1; i++) {
		sqlist->memory[i] = sqlist->memory[i+1];
	}
	sqlist->count--;

}

int search_sqlist(Sqlist* sqlist, DataType data) {
	for (int i = 0; i < sqlist->count; i++) {
		if (sqlist->memory[i] == data) {
			return i;
		}
	}
	return -1;
}

bool empty_sqlist(Sqlist* sqlist) {
	return sqlist->count == 0;
}
int size_sqlist(Sqlist* sqlist) {
	return sqlist->count;
}

void destory(Sqlist* sqlist) {
	assert(sqlist);
	free(sqlist->memory);
}

int main(void) {

	Sqlist* sqlist = creat_sqlist();
	insert_qlist(sqlist, 1);
	insert_qlist(sqlist, 9);
	insert_qlist(sqlist, 3);
	insert_qlist(sqlist, 1);
	ereas_sqlist_index(sqlist, 1);
	print_sqlist(sqlist);


	return 0;
}