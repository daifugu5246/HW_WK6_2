#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int numsquare[50][50];
int sum[100];
int size,i,temp1,temp2, x = 0, y = 0,j=0;
int check;
void Inputnum(); 
void Sumrow();
void Sumcols();
void Sumdiag();
void Checksamenum();
void Checkmagic();

int main() {
	printf("Enter square size : ");
	scanf("%d",&size);			//Identify size of Magic square
	i = ( size  *  2 ) + 2;
	printf("Enter element : \n");
	Inputnum();
	Sumrow();
	Sumcols();
	Sumdiag();
	for (int s = 0; s <= i - 1; s++) {
		printf("%d ",sum[s]);
	}
	Checksamenum();
	Checkmagic();
	return 0;
}
//Input Element
void Inputnum() {
	while (x <= size - 1) {
		while (y <= size - 1) {
			scanf("%d", (*(numsquare + x) + y));
			y++;
		}
		y = 0;
		x++;
	}
	x = 0;//reset value of x
	y = 0;//reset value of y
}
//Sum of rows
void Sumrow() {
	while (x <= size - 1 && x >= 0) {
		sum[j] = 0;
		while (y <= size - 1 && y >= 0) {
			sum[j] =sum[j] + *(*(numsquare + x) + y);
			y++;
		}
		y = 0;
		x++;
		j++;
	}
	x = 0; //reset value of x
	y = 0; //reset value of y
}
//Sum of colums
void Sumcols() {
	while (y <= size - 1 && y >= 0) {
		sum[j] = 0;
		while (x <= size - 1 && x >= 0) {
			sum[j] = sum[j] + *(*(numsquare + x) + y);
			x++;
		}
		x = 0;
		y++;
		j++;
	}
	x = 0; //reset value of x
	y = 0; //reset value of y
}
void Sumdiag() {
	while (y <= size - 1 && y >= 0) {
		sum[j] = 0;
		while (x <= size - 1 && x >= 0) {
			sum[j] = sum[j] + *(*(numsquare + x) + y);
			x++;
			y++;
		}
		j++;
	}
	x = 0; //set value of x for next diagonal
	y = size - 1; //set value of y for next diagonal
	while (y <= size - 1 && y >= 0) {
		sum[j] = 0;
		while (x <= size - 1 && x >= 0) {
			sum[j] = sum[j] + *(*(numsquare + x) + y);
			x++;
			y--;
		}
		j++;
	}
	x = 0;//reset value of x
	y = 0;//reset value of y
}
void Checksamenum() {
	while (x < size - 1) { 
		while (y < size - 1) {
			temp1 = *(*(numsquare + x) + y);
			for (int r = x  ; r < size - 1;r++) {
				for (int c = y+1 ; c < size - 1;c++) {
					temp2 = *(*(numsquare + r) + c);
					if (temp1 == temp2) {
						check = 0;
					}
					else {
						check = 1;
					}
				}
			}
			y++;
		}
		y = 0;
		x++;
	}
	x = 0;//reset value of x
	y = 0;//reset value of y
}
//check magic square
void Checkmagic() {
	for (int p = 0; p < i - 1; p++) { 
		if (sum[p] == sum[p + 1] && check != 0) {
			check = 1;
		}
		else {
			check = 0;
		}
	}
	if (check == 1) {
		printf("Yes");
	}
	else {
		printf("No");
	}
}
