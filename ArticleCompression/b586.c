#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Alphabet{
	char value[100];
	struct Alphabet *next;
};

struct Alphabet *head = NULL;

void deleteNode(struct Alphabet *ptr){
	struct Alphabet *temp = ptr->next;
	ptr->next = temp->next;
	free(temp);
}

int compareWord(char *data){

	struct Alphabet *current = head;
	int index = 1, ret = 0;

	if( strncmp(data, current->value, sizeof(data)) == 0 )
		return 1;

	while(current->next != NULL){
		index++;
		int ret = strncmp(data, current->next->value, sizeof(data));
		if(ret == 0){
			deleteNode(current);
			return index;
		}
		else
			current = current->next;
	};
	return 0;
}

int main(int argc, char *argv[]){

	char str[100];
	char ch;
	int count = 0, cmp = 0;

	scanf("%c", &ch);

	while(ch != '0'){
		count = 0;
		memset(str, 0, sizeof(str));
		while((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
			str[count++] = ch;
			scanf("%c", &ch);
		}
		if(count != 0){

			if(head == NULL){
				head = malloc(sizeof(struct Alphabet));
				strcpy(head->value, str);
				printf("%s", str);
			}
			else{
			cmp = compareWord(str);
			if(cmp == 0)
				printf("%s", str);
			else
				printf("%d", cmp);
				if(cmp != 1){
					struct Alphabet *current = head;
					struct Alphabet *newnode = malloc(sizeof(struct Alphabet));
					strcpy(newnode->value, str);
					newnode->next = current;
					head = newnode;
				}
			}
		}
		if(ch == '0')
			break;
		else{
			printf("%c", ch);
			scanf("%c", &ch);
		}
	}

//	while(head != NULL){
//		printf("value is %s\n", head->value);
//		head = head->next;
//	}

	return 0;
}
