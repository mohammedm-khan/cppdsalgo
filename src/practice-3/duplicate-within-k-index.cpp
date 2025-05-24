#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Hash table node structure
typedef struct HashNode {
    int key;
    int index;
    struct HashNode* next;
} HashNode;

// Hash table structure
typedef struct {
    HashNode** table;
    int size;
} HashMap;

// Hash function
int hash(int key, int size) {
    return abs(key) % size;
}

// Initialize hash map
HashMap* createHashMap(int size) {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    map->size = size;
    map->table = (HashNode**)calloc(size, sizeof(HashNode*));
    return map;
}

// Insert or update in hash map
bool insertOrUpdate(HashMap* map, int key, int index, int k) {
    int hashIndex = hash(key, map->size);
    HashNode* curr = map->table[hashIndex];

    while (curr) {
        if (curr->key == key) {
            if (abs(curr->index - index) <= k) return true;
            curr->index = index;  // Update index
            return false;
        }
        curr = curr->next;
    }

    // Insert new node
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->index = index;
    newNode->next = map->table[hashIndex];
    map->table[hashIndex] = newNode;
    
    return false;
}

// Free hash map
void freeHashMap(HashMap* map) {
    for (int i = 0; i < map->size; i++) {
        HashNode* curr = map->table[i];
        while (curr) {
            HashNode* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(map->table);
    free(map);
}

// Function to check nearby duplicates
bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    if (numsSize < 2 || k == 0) return false;

    HashMap* map = createHashMap(numsSize);
    for (int i = 0; i < numsSize; i++) {
        if (insertOrUpdate(map, nums[i], i, k)) {
            freeHashMap(map);
            return true;
        }
    }
    freeHashMap(map);
    return false;
}

// Driver code
int main() {
    int nums[] = {1, 2, 3, 1};
    int k = 3;
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    if (containsNearbyDuplicate(nums, numsSize, k)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
