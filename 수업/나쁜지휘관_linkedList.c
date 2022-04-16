#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

typedef struct Soldier {
	int num; //해당 노드 값
	struct Soldier* next_Man; // 다음 노드

}soldier;

typedef soldier* soldierPointer;

void printNode(soldier* start, int n);

int main() {
	int n, k;

	// 1) 병사의 수만큼 노드를 생성하고 연결리스트로 만듬------------------------------------------------------------

	scanf("%d", &n); // 명수
	scanf("%d", &k); // 번째

	soldier* start_Point = (soldier*)malloc(sizeof(soldier)); // 시작 노드
	soldier* temp1 = NULL;									  // 반복문에서 사용할 임시 노드

	// 0 ~ n-1 : 총 n명
	for (int i = 0; i < n; i++) { 

		// 1-1) 최초노드 생성(1번 병사)
		if (i == 0) { 
			soldier* first_Soldier = (soldier*)malloc(sizeof(soldier)); 
			first_Soldier->num = i + 1;

			//printf("생성) %p\n", first_Soldier);

			start_Point->next_Man = first_Soldier;  // 시작을 나타내는 노드가 최초 병사(노드)를 가르킴
			temp1 = first_Soldier;					// 탐색할 노드에 최초병사(노드) 대입
		}

		// 1-2)  최초 노드 병사가 생성 된 후
		else { 
			soldier* next_Soldier = (soldier*)malloc(sizeof(soldier)); // 2번 병사(노드)부터 생성
			next_Soldier->num = i + 1;								   // 2, 3, 4, 5, ...

			//printf("다음 %d) %p\n", i + 1, next_Soldier);

			temp1->next_Man = next_Soldier; // 현재노드의 다음노드에 새로 생긴 병사(노드)를 대입
			temp1 = next_Soldier;		    // 또 다른 다음 노드가 생성 될시에 새로 만든 노드에 넣을 준비
		}
	}

	// 마지막으로 생성된 노드를 순환 시키기 위해 최초 병사 노드를 연결(cycled linked list 형태)
	temp1->next_Man = start_Point->next_Man; 

	
	// 완성된 병사 목록 확인
	printNode(start_Point->next_Man, n);
	

	// 2) 병사들을 한명씩 정해진 k 순서대로 선택
	soldier* current = start_Point->next_Man; // 현재 병사노드 확인
	soldier* temp2 = NULL;					  // 반복문에서 사용할 임시 노드

	// 2-0) k번째 병사마다 선택됨, remain = 남아있는 병사의 수
	int count = 1, remain = n;
	while (1) {
		
		// 2-1) 생존 병사수가 1명이라면 반복문 탈출
		if (remain == 1) break;

		// 2-2) k번째 병사마다 선택시키기 위한 조건문
		// 이전 노드는 접근하지 못하고 다음 노드만(순환형태로) 확인 가능하기 때문에 현재 노드의 다음 순서가 k번째라면
		// 현재 노드의 다음 순서를 원래 다음노드의 다음노드로 대입시킴.
		// 그리고 선택된 노드 free함수로 메모리 반납
		if (count + 1 == k) {
			temp2 = current->next_Man;
			current->next_Man = current->next_Man->next_Man; // 현재노드의 다음순서 = 원래 다음노드의 다음노드
			printf("%d번 사망...", temp2->num);

			free(temp2);

			remain--; // 남은 사람 수

			current = current->next_Man;
			count = 1;

			// 생존자 확인
			printNode(current, remain);

			continue;
		}

		// 노드 탐색
		current = current->next_Man;
		count++;

	}

	// 생존 노드
	current->next_Man = NULL;
	printf("생존가능위치 = %d\n", current->num);

}

// 3) 현재 연결리스트 상태 출력 함수
void printNode(soldier* start, int n) {
	soldier* temp = start;

	printf("(%d명 생존중)\n 생존자 : ", n);
	for (int i = 0; i < n; i++) {
		//printf("%p", temp);
		printf("%d ", temp->num);
		temp = temp->next_Man;
	}
	printf("\n\n");
}