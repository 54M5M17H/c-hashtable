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

