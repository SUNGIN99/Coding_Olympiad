#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

typedef struct Soldier {
	int num; //�ش� ��� ��
	struct Soldier* next_Man; // ���� ���

}soldier;

typedef soldier* soldierPointer;

void printNode(soldier* start, int n);

int main() {
	int n, k;

	// 1) ������ ����ŭ ��带 �����ϰ� ���Ḯ��Ʈ�� ����------------------------------------------------------------

	scanf("%d", &n); // ���
	scanf("%d", &k); // ��°

	soldier* start_Point = (soldier*)malloc(sizeof(soldier)); // ���� ���
	soldier* temp1 = NULL;									  // �ݺ������� ����� �ӽ� ���

	// 0 ~ n-1 : �� n��
	for (int i = 0; i < n; i++) { 

		// 1-1) ���ʳ�� ����(1�� ����)
		if (i == 0) { 
			soldier* first_Soldier = (soldier*)malloc(sizeof(soldier)); 
			first_Soldier->num = i + 1;

			//printf("����) %p\n", first_Soldier);

			start_Point->next_Man = first_Soldier;  // ������ ��Ÿ���� ��尡 ���� ����(���)�� ����Ŵ
			temp1 = first_Soldier;					// Ž���� ��忡 ���ʺ���(���) ����
		}

		// 1-2)  ���� ��� ���簡 ���� �� ��
		else { 
			soldier* next_Soldier = (soldier*)malloc(sizeof(soldier)); // 2�� ����(���)���� ����
			next_Soldier->num = i + 1;								   // 2, 3, 4, 5, ...

			//printf("���� %d) %p\n", i + 1, next_Soldier);

			temp1->next_Man = next_Soldier; // �������� ������忡 ���� ���� ����(���)�� ����
			temp1 = next_Soldier;		    // �� �ٸ� ���� ��尡 ���� �ɽÿ� ���� ���� ��忡 ���� �غ�
		}
	}

	// ���������� ������ ��带 ��ȯ ��Ű�� ���� ���� ���� ��带 ����(cycled linked list ����)
	temp1->next_Man = start_Point->next_Man; 

	
	// �ϼ��� ���� ��� Ȯ��
	printNode(start_Point->next_Man, n);
	

	// 2) ������� �Ѹ� ������ k ������� ����
	soldier* current = start_Point->next_Man; // ���� ������ Ȯ��
	soldier* temp2 = NULL;					  // �ݺ������� ����� �ӽ� ���

	// 2-0) k��° ���縶�� ���õ�, remain = �����ִ� ������ ��
	int count = 1, remain = n;
	while (1) {
		
		// 2-1) ���� ������� 1���̶�� �ݺ��� Ż��
		if (remain == 1) break;

		// 2-2) k��° ���縶�� ���ý�Ű�� ���� ���ǹ�
		// ���� ���� �������� ���ϰ� ���� ��常(��ȯ���·�) Ȯ�� �����ϱ� ������ ���� ����� ���� ������ k��°���
		// ���� ����� ���� ������ ���� ��������� �������� ���Խ�Ŵ.
		// �׸��� ���õ� ��� free�Լ��� �޸� �ݳ�
		if (count + 1 == k) {
			temp2 = current->next_Man;
			current->next_Man = current->next_Man->next_Man; // �������� �������� = ���� ��������� �������
			printf("%d�� ���...", temp2->num);

			free(temp2);

			remain--; // ���� ��� ��

			current = current->next_Man;
			count = 1;

			// ������ Ȯ��
			printNode(current, remain);

			continue;
		}

		// ��� Ž��
		current = current->next_Man;
		count++;

	}

	// ���� ���
	current->next_Man = NULL;
	printf("����������ġ = %d\n", current->num);

}

// 3) ���� ���Ḯ��Ʈ ���� ��� �Լ�
void printNode(soldier* start, int n) {
	soldier* temp = start;

	printf("(%d�� ������)\n ������ : ", n);
	for (int i = 0; i < n; i++) {
		//printf("%p", temp);
		printf("%d ", temp->num);
		temp = temp->next_Man;
	}
	printf("\n\n");
}