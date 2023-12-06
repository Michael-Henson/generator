#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
	int i = 0, j = 0, k = 575;
	for(j = 0; j < 24; ++j){
		printf("//Row %i\n", j + 1);
		for(i = 0; i < 24; ++i){
			printf("if((cy >= START+SEGMENT*%i) && (cy <= START+SEGMENT*%i-SKIP) && (cx >= START+SEGMENT*%i) && (cx <= START+SEGMENT*%i-SKIP))\n", j, j + 1, i, i + 1);
			printf("\tif (n2[%i] == 1'b0)\n", k);
			printf("\t\tDataIn <= dead;\n");
			printf("\telse\n");
			printf("\t\tDataIn <= alive;\n");
			printf("\n");
			
			--k;
		}
		printf("// Begining/End of Row\n");
		printf("if ((cy >= START+SEGMENT*%i) && (cy <= START+SEGMENT*%i-SKIP+ && (cx < START))\n", j, j + 1);
		printf("\tDataIn <= {8'h00, 8'h00, 8'h00);\n");
		printf("if ((cy >= START+SEGMENT*%i) && (cy <= START+SEGMENT*%i-SKIP+ && (cx < START+SEGMENT*24))\n", j, j + 1);
		printf("\tDataIn <= {8'h00, 8'h00, 8'h00);\n");
		printf("\n");
		
		printf("// Skip Row\n");
		for(i = 0; i < 24; ++i){
			printf("if((cy >= START+SEGMENT*%i) && (cy <= START+SEGMENT*%i-SKIP) && (cx >= START+SEGMENT*%i-SKIP) && (cx <= START+SEGMENT*%i))\n", j, j + 1, i + 1, i + 1);
			printf("\tDataIn <= {8'h00, 8'h00, 8'h00);\n");
		}
		printf("\n");
		
		printf("//Skip Column\n");
		printf("if ((cy >= START+SEGMENT*%i-SKIP) && (cy <= START+SEGMENT*%i))\n", j + 1, j + 1);
		printf("\tDataIn <= {8'h00, 8'h00, 8'h00);\n");
		printf("\n");
	}
	printf("//Skip\n");
	printf("if (cy >= START+SEGMENT*%i-SKIP)\n", j + 1);
	printf("\tDataIn <= {8'h00, 8'h00, 8'h00);\n");
	printf("\n");
}
