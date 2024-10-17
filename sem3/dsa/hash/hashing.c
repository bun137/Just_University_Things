#include <stdio.h>
#include <stdlib.h>

typedef struct hashtable {
  int size;
  int *table; //-> can be user defined data type
} HASHI;

HASHI *createHashTable(int size) {
  HASHI *hash = (HASHI *)malloc(sizeof(HASHI));
  hash->size = size;
  hash->table = (int *)malloc(sizeof(int) * size);
  for (int i = 0; i < size; i++) {
    hash->table[i] = -1;
  }
  return hash;
}
// linear probing
void insert(HASHI *hash, int key) { // key is the number you want to store
  int index = key % hash->size;
  if (hash->table[index] == -1) {
    hash->table[index] = key;
  } else {
    int probVal = 1;
    int count = 0;
    while (hash->table[(index)] != -1 && count < (hash->size)) {
      int newIndex = (index + probVal) % hash->size;
      if (hash->table[newIndex] == -1) {
        hash->table[newIndex] = key;
        break;
      } else {
        probVal++;
        count++;
      }
    }
  }
}
// quadratic probing
void insert(HASHI *hash, int key) { // key is the number you want to store
  int index = key % hash->size;
  if (hash->table[index] == -1) {
    hash->table[index] = key;
  } else {
    int probVal = 1;
    int count = 0;
    while (hash->table[(index) != -1 && count < (hash->size)] != -1) {
      int newIndex = (index + probVal * probVal) % hash->size;
      if (hash->table[newIndex] == -1) {
        hash->table[newIndex] = key;
        break;
      } else {
        probVal++;
        count++;
      }
    }
  }
}

// double hashing
void insert(HASHI *hash, int key) { // key is the number you want to store
  int index = key % hash->size;
  if (hash->table[index] == -1) {
    hash->table[index] = key;
  } else {
    int probVal = 5 - (key % 5); // H2 Key
    int count = 0;
    while (hash->table[(index) != -1 && count < (hash->size)] != -1) {
      int newIndex = (index + probVal * (count + 1)) % hash->size;

      if (hash->table[index] == key) {
        printf("Found at %d", index);
      } else {
        probVal++;
        count++;
      }
    }
  }
}

void search(HASHI *hash, int key) { // key is the number you want to store
  int index = key % hash->size;
  if (hash->table[index] == -1) {
    hash->table[index] = key;
  } else {
    int probVal = 1;
    int count = 0;
    while (hash->table[(index) != -1 && count < (hash->size)] != -1) {
      int newIndex = (index + probVal) % hash->size;

      if (hash->table[index] == key) {
        printf("Found at %d", index);
      } else {
        probVal++;
        count++;
      }
    }
  }
}

void delete(HASHI *hash, int key) { // key is the number you want to store
  int index = key % hash->size;
  if (hash->table[index] == -1) {
    hash->table[index] = key;
  } else {
    int probVal = 1;
    int count = 0;
    while (hash->table[(index) != -1 && count < (hash->size)] != -1) {
      int newIndex = (index + probVal) % hash->size;

      if (hash->table[index] == key) {
        hash->table[index] = -1;
      } else {
        probVal++;
        count++;
      }
    }
  }
}

int main() {
  HASHI *ptr_to_hash;
  int size;
  scanf("%d", &size);
  ptr_to_hash = createHashTable(size);
  // for(int i=0;i<size;i++){
  //     printf("%d ",ptr_to_hash->table[i]);
  // }
  insert(ptr_to_hash, 10);
}
