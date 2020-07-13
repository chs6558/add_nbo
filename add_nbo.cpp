#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <netinet/in.h>
uint32_t read_bin_from_file(char*);
uint32_t my_ntohl(uint32_t);

int main(int argc, char* argv[]){
	uint32_t num1, num2, sum;
	num1 = read_bin_from_file(argv[1]);
	num2 = read_bin_from_file(argv[2]);
	sum = num1 + num2;
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", num1, num1, num2, num2, sum, sum);
	return 0;
}


uint32_t read_bin_from_file(char* fname){
	FILE *f = fopen(fname, "rb");
	uint8_t network_buffer[4];
	int i;
	uint32_t result;
	for(i=0; i<4; i++){
		fread(&network_buffer[i],sizeof(network_buffer[i]), 1, f);
	}
	uint32_t* p = reinterpret_cast<uint32_t*>(network_buffer);
	fclose(f);
	result = ntohl(*p);
	return result;
}
