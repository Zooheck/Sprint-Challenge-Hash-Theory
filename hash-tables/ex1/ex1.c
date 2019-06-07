#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *createAnswer(int index1, int index2)
{
  Answer *answer = malloc(sizeof(Answer));
  answer->index_1 = index1;
  answer->index_2 = index2;
  return answer;
}
Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);
  // check each item in *weights
  for (int i = 0; i < length; i++)
  {
    int difference = limit - weights[i];
    int potentialKey = hash_table_retrieve(ht, difference);

    // if (ht->storage[difference] != NULL)
    if (potentialKey != -1)
    {
      // we have a match
      Answer *answer = createAnswer(weights[i], difference);
      return answer;
      // check if difference or ht->storage[difference] is bigger
    }
    hash_table_insert(ht, weights[i], difference);
  }
  // weight/(limit - weight)
  // if (limit - weight) is already a key, we have a match

  return NULL;
}

void print_answer(Answer *answer)
{
  if (answer != NULL)
  {
    printf("%d %d\n", answer->index_1, answer->index_2);
  }
  else
  {
    printf("NULL\n");
  }
}

#ifndef TESTING
int main(void)
{
  // TEST 1
  int weights_1 = {9};
  Answer *answer_1 = get_indices_of_item_weights(&weights_1, 1, 9);
  print_answer(answer_1); // NULL

  // TEST 2
  int weights_2[] = {4, 4};
  Answer *answer_2 = get_indices_of_item_weights(weights_2, 2, 8);
  print_answer(answer_2); // {1, 0}

  // TEST 3
  int weights_3[] = {4, 6, 10, 15, 16};
  Answer *answer_3 = get_indices_of_item_weights(weights_3, 5, 21);
  print_answer(answer_3); // {3, 1}

  // TEST 4
  int weights_4[] = {12, 6, 7, 14, 19, 3, 0, 25, 40};
  Answer *answer_4 = get_indices_of_item_weights(weights_4, 9, 7);
  print_answer(answer_4); // {6, 2}

  return 0;
}

#endif
