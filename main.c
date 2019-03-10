#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define INIT_SIZE (10)

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
void setElement(HashMap hash, int index, char* key, char* value);
LinkNode* findAvailableNode(LinkNode* currNode, char* key);
char* getElement(HashMap hash, int index, char* key);
char* recurseLinkedListForKey(LinkNode* currNode, char* key);
int doHash(int length, char* key);
char* get (HashMap hash, char* key);
void set(HashMap hash, char* key, char* value);

int main () {
	HashMap* hash = createHash(INIT_SIZE);
	set(*hash, "Sam", "Smith");
	char* res = get(*hash, "Sam");
	printf("Sam's surname is %s", res);
}

char* get (HashMap hash, char* key) {
	int hashRes = doHash(hash.length, key);
	return getElement(hash, hashRes, key);
}

void set(HashMap hash, char* key, char* value) {
	int hashRes = doHash(hash.length, key);
	setElement(hash, hashRes, key, value);
}

HashMap* createHash(length) {
	HashMap* hash = calloc(1, sizeof(HashMap)); 
	hash->length = length;		
	return hash;
}

int doHash(int length, char* key) {
	int total = 0;
	for (int i = 0; i < strlen(key); i++) {
		total += (int) key[i];
	}
	return total % length;
}

void setElement(HashMap hash, int index, char* key, char* value) {
	LinkNode* firstNode = hash.data[index];
	LinkNode* node;

	if (!firstNode) {
		node = firstNode;
	} else {
		node = findAvailableNode(firstNode, key);
	}

	node->key = key;
	node->value = value;
}

LinkNode* findAvailableNode(LinkNode* currNode, char* key) {
	if (currNode->key == key) {
		return currNode;
	}
	if(currNode->next) {
		return findAvailableNode(currNode->next, key);
	}
	currNode->next = (LinkNode*) malloc(sizeof(LinkNode*));
	currNode->next->next = NULL;
	return currNode->next;
}

char* getElement(HashMap hash, int index, char* key) {
	LinkNode* firstNode = hash.data[index];
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
	return recurseLinkedListForKey(currNode, key);
}

