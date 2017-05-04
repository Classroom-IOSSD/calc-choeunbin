#include <stdio.h>
#include "operators.h"

int main(){
	FILE *fp = NULL;
	int operand1, operand2;
	char operator = ' ';
	int line = 0;
	double result = 0.0;
	double (*calc_function) (int,int);

	fp = fopen("read.txt","r");
	if(fp!=NULL){
		fscanf(fp, "%d", &line);
	
		for(int i=0; i<line-1; i++) {
			fscanf(fp, "%d %c %d",&operand1, &operator, &operand2);
			switch(operator) {
				case '+':
				calc_function = add;
				break;
				case '-':
				calc_function = minus;
				break;
				case '*':
				calc_function = mul;
				break;
				case '/':
				calc_function = div;
				break;
			}
			result = calc_function(operand1, operand2);		
			printf("%d %c %d = %f\n",
				 operand1, operator, operand2, result);
		}
	}
	return 0;
}

