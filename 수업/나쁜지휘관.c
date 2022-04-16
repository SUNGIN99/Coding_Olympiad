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

	scanf("%d", &n); // ���
	scanf("%d", &k); // ��°

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
			printf("����������ġ = %d", i+1);
			break;
		}

		if (count == k) { // if k = 3 �̸� 0 , 1, 2 ���� 2�϶� �׾����
			soldier[i] = 0;
			count = 0;

			printSurviver(soldier, n);
			printf("%d�� ���..\n\n", i + 1);

		}

		i = (i + 1) % n;
		count++;


	}


}