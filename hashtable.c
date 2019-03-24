#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hashtable.h"

char* get (HashMap *hash, char* key) {
	int hashRes = doHash(hash->length, key);
	return getElement(hash, hashRes, key);
}

HashMap* set(HashMap *hash, char* key, char* value) {
	if (hash->isFull) hash = rehash(hash);
	int hashRes = doHash(hash->length, key);
	setElement(hash, hashRes, key, value);
	return hash;
}

HashMap* createHash(length, maxLinks) {
	HashMap *hash = malloc(sizeof(HashMap) + (sizeof(LinkNode*) * length));

	hash->length = length;
	hash->totalSize = 0;
	hash->isFull = 0;
	hash->maxLinks = maxLinks || MAX_LINK;

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
		node = findAvailableNode(hash, node, key);
	}

	node->key = key;
	node->value = value;
}

LinkNode* allocateNode() {
	LinkNode *node = (LinkNode*) malloc(sizeof(LinkNode));
	node->next = NULL;
	return node;
}

LinkNode* findAvailableNode(HashMap *hash, LinkNode *currNode, char* key) {
	int loopCounter = 1;
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
		loopCounter++;
	}
	hash->isFull = loopCounter > hash->maxLinks ? 1 : 0;
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
	if (strcmp(currNode->key, key) == 0) {
		return currNode->value;
	}
	return recurseLinkedListForKey(currNode->next, key);
}

HashMap* rehash(HashMap* oldHash) {
	printf("Rehashing... \n");
	HashMap* newHash = createHash(oldHash->length * 2, oldHash->maxLinks);
	LinkNode* currNode;
	LinkNode* nextNode;
	for(int i = 0, l = oldHash->length; i < l; i++) {
		currNode = oldHash->data[i];
		while(currNode) {
			set(newHash, currNode->key, currNode->value);
			nextNode = currNode->next;
			free(currNode);
			currNode = nextNode;
		}
	}
	free(oldHash);
	return newHash;
}

void deleteKey(HashMap *hash, char* key) {
	int index = doHash(hash->length, key);
	LinkNode *currNode = hash->data[index];
	LinkNode *nextNode;
	if (!currNode) return;
	if (strcmp(key, currNode->key) == 0) {
		currNode = currNode->next;
		free(hash->data[index]);
		hash->data[index] = currNode;
		return;
	}

	while(1) {
		if (!currNode->next) {
			return;
		}

		if (strcmp(currNode->next->key, key) == 0) {
			nextNode = currNode->next->next;
			free(currNode->next);
			currNode->next = nextNode;
			return;
		}

		currNode = currNode->next;
	}
}

void freeHash(HashMap *hash) {
	LinkNode* currNode;
	LinkNode* nextNode;
	for(int i = 0, l = hash->length; i < l; i++) {
		currNode = hash->data[i];
		while(currNode) {
			nextNode = currNode->next;
			free(currNode);
			currNode = nextNode;
		}
	}
	free(hash);
}

