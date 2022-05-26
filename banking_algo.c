#include <stdio.h>
void read_arr(int n, int r, int a[n][r]){
	printf("Enter resources\n");
	for (int i = 0; i < n; i++){
		for (int j = 0 ;j < r; j++){		
			scanf("%d", &a[i][j]);
		}
	}
}
void write_arr(int n, int r, int a[n][r]){
	for (int i = 0; i < n; i++){
        for (int j = 0 ;j < r; j++){        
            printf("%d\t", a[i][j]);
        }
		printf("\n");
     }
}
void calc_need(int n, int r, int a[n][r], int max[n][r], int allocated[n][r]){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < r; j++){
			a[i][j] = max[i][j] - allocated[i][j];
		}
	}	
}

int main(){
	int i, j, k, n, r, flag = 1;
	printf("Enter no.of processes and r: ");
	scanf("%d %d", &n, &r);
	int max[n][r], allocated[n][r], available[r], need[n][r], status[n];
	printf("Enter max\n");
	read_arr(n, r, max);
	printf("Enter allocated\n");
    read_arr(n, r, allocated);
	printf("Enter available\n");
	for (i = 0; i < r; i++){
		scanf("%d", &available[i]);
	}
	for (i = 0; i < n; i++){
		status[i] = 0;
	}
	calc_need(n, r, need, max, allocated);
	while(flag){
		flag = 0;
		for(i = 0; i < n; i++){
			int c = 0;
			for (j = 0; j < r; j++){
				if (status[i] == 0 & available[j] >= need[i][j]){
					c++;
					if(c == r){
						for (k = 0; k < r; k++){
							available[k] += allocated[i][k];
							status[i] = 1;
							printf("P[%d]\n", i);
							flag = 1;
						}
					}
				}
			}
		}
	}
	
	int c1 = 0;
	for(i = 0; i < n; i++){
		if (status[i] == 1)
			c1++;
	}
	
	if (c1 == n)
		printf("Safe state\n");
	else
		printf("Dead Lock state\n");
	return 0;
}
