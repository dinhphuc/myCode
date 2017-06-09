#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>
typedef char item;
typedef struct Node{
	item data;
	Node *next;
};

typedef struct Stack{
	Node *Top;
};

void tao_stack(Stack &S){
	S.Top = NULL;
}

bool IsEmpty(Stack &S)
{

	return(S.Top == NULL) ? true : false;
}

Node *TaoNode(item x)
{

	Node *P = new Node;
	P->data = x;
	P->next = NULL;
	return P;
}

void Push(Stack &S, item x){
	Node *P = TaoNode(x);
	P->next = S.Top;
	S.Top = P;
}

item POP(Stack &S)
{
	if (!IsEmpty(S)){
		item x = S.Top->data;
		S.Top = S.Top->next;
		return x;
	}

}

void readFILE(char filename[50], Stack &S)
{

	FILE *F;
	F = fopen(filename, "r");
	if (F == NULL){
		printf("FILE NOT EXIST !\n\n");
	}
	else{
		int n;
		item x;
		while (!feof(F))
		{
			fscanf(F, "%c", &x);
			Push(S, x);
		}

	}
	fclose(F);

}


bool CheckBracket(char b[100]){
	Stack S;
	tao_stack(S);
	int i = 0;
	for (int i = 0; i<strlen(b); i++){
		if (b[i] == '(' || b[i] == '[' || b[i] == '{'){
			Push(S, b[i]);
		}
		else if (b[i] == ')'){
			if (IsEmpty(S)){
				return false;
			}
			else{
				if (POP(S) != '('){
					return false;
				}
			}
		}
		else if (b[i] == ']'){
			if (IsEmpty(S)){
				return false;
			}
			else{
				if (POP(S) != '['){
					return false;
				}
			}
		}
		else if (b[i] == '}'){
			if (IsEmpty(S)){
				return false;
			}
			else{
				if (POP(S) != '{'){
					return false;
				}
			}
		}
		/*else if (b[i] == '"'){
			i++;
			if (i % 2 != 0){
				Push(S, b[i]);
			}
			else{
				if (POP(S) != '"'){
					return false;
				}
			}
		}*/
	}


	if (IsEmpty(S)){
		return true;
	}
	else{
		return false;
	}
}

void main()
{
	Stack S;
	tao_stack(S);
	printf("\n\n\t1. Kiem Tra Bieu Thuc \n\t2. Thoat\n\n");

	int temp;
	do{
		printf("\n\tChon thao tac: ");
		scanf("%d", &temp);
		switch (temp)
		{
		case 1:
			char b[100];
			fflush(stdin);
			printf("\tNhap vao bieu thuc: ");
			gets(b);
			fflush(stdin);
			if (CheckBracket(b) == true){
				printf("\tBieu thuc ngoac dung");
			}
			else{
				printf("\tBieu thuc ngoac sai");
			}

			break;
		case 2:
			return;
			break;
		}

	} while (temp<2);

	_getch();
}