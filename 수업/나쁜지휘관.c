#include <stdio.h>
#pragma warning(disable : 4996)

void printSurviver(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) {
			printf("X ");
		}
		else
			printf("%d ", arr[i]);
	}

	printf("\n");
}

int howManySurviver(int arr[], int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] != 0) count++;
	}

	return count;
}

int main() {
	int soldier[100] = { NULL, };

	int n, k;
	int count, i;

	scanf("%d", &n); // 명수
	scanf("%d", &k); // 번째

	for (i = 0; i < n; i++) {
		soldier[i] = i + 1;
	}

	count = 1;
	i = 0;
	while (1) {

		if (soldier[i] == 0) {
			i = (i + 1) % n;
			continue;
		}

		if (howManySurviver(soldier, n) == 1) {
			printf("생존가능위치 = %d", i+1);
			break;
		}

		if (count == k) { // if k = 3 이면 0 , 1, 2 에서 2일때 죽어야함
			soldier[i] = 0;
			count = 0;

			printSurviver(soldier, n);
			printf("%d번 사망..\n\n", i + 1);

		}

		i = (i + 1) % n;
		count++;


	}


}