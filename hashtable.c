#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define INIT_SIZE (10)
#define MAX_LINK (5)

typedef struct LinkNode LinkNode;
struct LinkNode {
	char* key;
	char* value;
	LinkNode* next;
};

typedef struct _HashMap {
	int length;
	int totalSize;
	LinkNode* data[];
} HashMap;

HashMap* createHash(int length);
void setElement(HashMap *hash, int index, char* key, char* value);
LinkNode* findAvailableNode(LinkNode* currNode, char* key);
LinkNode* allocateNode();
char* getElement(HashMap *hash, int index, char* key);
char* recurseLinkedListForKey(LinkNode* currNode, char* key);
int doHash(int length, char* key);
char* get (HashMap *hash, char* key);
void set(HashMap *hash, char* key, char* value);

int main () {
	struct timespec time1, time2;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);
	
	HashMap* hash = createHash(INIT_SIZE);
	set(hash, "Sam", "Alexander");
	set(hash, "Joe", "William");
	set(hash, "Elliott", "James");
	set(hash, "David", "John");
	set(hash, "Reggie", "Craig");
	set(hash, "Colin", "Keith");
	set(hash, "Anna", "Stephanie");
	set(hash, "Matt", "Cyl");
	set(hash, "Sue", "Careless");
	set(hash, "Alison", "Crisp");

	char* res = get(hash, "Sam");
	char* res2 = get(hash, "Elliott");
	char* res3 = get(hash, "Joe");
	char* res4 = get(hash, "David");
	char* res5 = get(hash, "Reggie");
	char* res6 = get(hash, "Colin");
	char* res7 = get(hash, "Anna");
	char* res8 = get(hash, "Matt");
	char* res9 = get(hash, "Sue");
	char* res10 = get(hash, "Alison");

	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
	printf("%.9ld \n", (long)time1.tv_nsec);
	printf("%.9ld \n", (long)time2.tv_nsec);
	printf("%.9ld \n\n", (long)time2.tv_nsec - time1.tv_nsec);

	printf("Sam's middlename is %s \n", res);
	printf("Ell's middlename is %s \n", res2);
	printf("Joe's middlename is %s \n", res3);
	printf("Dave's middlename is %s \n", res4);
	printf("Reg's middlename is %s \n", res5);

	printf("Colin's middlename is %s \n", res6);
	printf("Anna's middlename is %s \n", res7);
	printf("Matt's middlename is %s \n", res8);
	printf("Sue's middlename is %s \n", res9);
	printf("Alison's middlename is %s \n", res10);

}

char* get (HashMap *hash, char* key) {
	int hashRes = doHash(hash->length, key);
	return getElement(hash, hashRes, key);
}

void set(HashMap *hash, char* key, char* value) {
	int hashRes = doHash(hash->length, key);
	setElement(hash, hashRes, key, value);
}

HashMap* createHash(length) {
	HashMap *hash = malloc(sizeof(HashMap) + (sizeof(LinkNode*) * length));

	hash->length = length;
	hash->totalSize = 0;

	for(int i = 0; i < length; i++) {
		hash->data[i] = NULL;
	}

	return hash;
}

int doHash(int length, char* key) {
	int total = 0;
	for (int i = 0; i < strlen(key); i++) {
		total += (int) key[i];
	}
	return total % length;
}

void setElement(HashMap *hash, int index, char* key, char* value) {
	LinkNode *node = hash->data[index];
	if (!node) {
		hash->data[index] = node = allocateNode();
	} else {
		node = findAvailableNode(node, key);
	}

	node->key = key;
	node->value = value;
}

LinkNode* allocateNode() {
	LinkNode *node = (LinkNode*) malloc(sizeof(LinkNode));
	node->next = NULL;
	return node;
}

LinkNode* findAvailableNode(LinkNode *currNode, char* key) {
	while(1) {
		if (!currNode->next) {
			currNode->next = allocateNode();
			currNode = currNode->next;
			break;
		}

		if (strcmp(currNode->key, key) == 0) {
			break;
		}

		currNode = currNode->next;
	}
	return currNode;
}

char* getElement(HashMap *hash, int index, char* key) {
	LinkNode* firstNode = hash->data[index];
	if (!firstNode) {
		return NULL;
	}
	return recurseLinkedListForKey(firstNode, key);
}

char* recurseLinkedListForKey(LinkNode* currNode, char* key) {
	if (!currNode) {
		return NULL;
	}
	if (currNode->key == key) {
		return currNode->value;
	}
	return recurseLinkedListForKey(currNode->next, key);
}

