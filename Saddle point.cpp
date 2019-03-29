#include<stdio.h>
#include<stdlib.h>
typedef struct saddle
{
	int rw, cl;
}saddle;
saddle function(int row, int col, int *arr)
{	
	saddle 
}
int main()
{
	int row, col;
	printf("Enter number of row and col:");
	scanf("%d %d",&row, &col);
	int arr[row][col];
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	saddle sdde = function(row, col, &arr[0][0]);
	printf("Saddle point : Col :: %d And Row :: %d ",sdde.cl , sdde.rw);
}
////finding sadle point in the matrix;
//saddle point in a mtrix is point which::
//it is minimum in row and max in column