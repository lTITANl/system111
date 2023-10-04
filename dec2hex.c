#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef unsigned char* pointer;

bool is64bit()
{
	return sizeof(void*) == 8;
	//sizeof(void*)이 32비트 운영체제에서는 4비트, 64에서는 8비트
}

bool isBigEndian() {
    unsigned int testValue = 1;
    unsigned char* bytePointer = (unsigned char*)&testValue;
    return bytePointer[0] == 0;
}


void le_show_bytes(pointer ptr, size_t size) {
    printf("0x");
    for (int i = size - 1; i >= 0; i--) {
        printf("%.2X", ptr[i]);
    }
    printf("\n");
}
//little endian은 낮은 주소에 데이터의 낮은 바이트(lsb)를 저장

void be_show_bytes(pointer ptr, size_t size) {
    printf("0x");
    for (size_t i = 0; i < size; i++) {
        printf("%.2X", ptr[i]);
    }
    printf("\n");
}
//big endian은 낮은 주소에 데이터의 큰 바이트를 저장

int main(int argc, char* argv[])
{
	if(argc < 2){
		printf("Usage: ./a.out number\n");
		exit(0);
	}
	unsigned int a = atoi(argv[1]);

	printf("ARCH=%d\n", is64bit()? 64 : 32);
	printf("ORDERING=%s\n", isBigEndian()? "BIG_ENDIAN": "LITTLE_ENDIAN");

	printf("MYANS: DEC=%d HEX=", a);
	isBigEndian()? be_show_bytes((pointer)&a, sizeof(unsigned int)): le_show_bytes((pointer)(&a), sizeof(unsigned int));

	printf("CHECK: DEC=%d HEX=%.8X\n", a, a);
	return 0;
}
