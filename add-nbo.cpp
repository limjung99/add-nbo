#include <arpa/inet.h>
#include <stdio.h>
#include <stdint.h>

uint32_t readNumber(const char* filename){
	FILE* file = fopen(filename,"rb");

	uint32_t number;
	fread(&number,sizeof(number),1,file);

	fclose(file);

	return ntohl(number);
}


int main(int argc,char* argv[]){

	uint32_t num1 = readNumber(argv[1]);
	uint32_t num2 = readNumber(argv[2]);

	uint32_t sum = num1 + num2;

	printf("%u(0x%x) + %u(0x%x) = %u(0x%x) \n",num1,num1,num2,num2,sum,sum);

}

