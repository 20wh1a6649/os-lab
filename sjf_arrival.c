#include<stdio.h>
void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
int main() {
	int n, i, j,av_wt = 0, av_at = 0,  p[10], bt[10], at[10], tat[10], wt[10], st[10];
	printf("Enter no of process : ");
	scanf("%d",&n);
	printf("Enter Burst time and arrival time : ");
	for (i = 0; i < n; i++) {
		scanf("%d %d", &bt[i], &at[i]);
		p[i] = i + 1;
	}
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (at[i] > at[j]) {
				swap(&at[i], &at[j]);
				swap(&bt[i], &bt[j]);
				swap(&p[i], &p[j]);
			}
			else if (at[i] == at[j] && bt[i] > bt[j]) {
				swap(&bt[i], &bt[j]);
				swap(&p[i], &p[j]);
			}
		}
	}
	st[i] = bt[i];
	st[0] = at[0];
	wt[0] = 0;
	
	for (i = 1; i < n; i++) {
		st[i] = st[i - 1] + bt[i - 1];
		wt[i] = st[i] - at[i];
	
	}
	for (i = 0; i < n; i++) {
		tat[i] = wt[i] + bt[i];
	}
	printf("process\twaiting time\t total arrival time\n");
	for (i = 0; i < n; i++) {
		printf("%d\t%d\t%d\t\n", p[i], wt[i], tat[i]);
		av_wt += wt[i];
		av_at += tat[i];
	}
	
	printf("Average waiting time : %d\n", av_wt/n);
	printf("Average tat : %d\n", av_at/n);
	
	

}

/*
Enter no of process : 4
Enter Burst time and arrival time : 6 1
5 1
5 2
3 2
process waiting time total arrival time
2 0 5
1 5 11
4 10 13
3 13 18
Average waiting time : 7
Average tat : 11


*/
