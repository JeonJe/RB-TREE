

#include "rbtree.h"
#include "rbtree.c"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>




// erase should delete root node
void test_erase_root(const key_t key) {
  rbtree *t = new_rbtree();
  node_t *p = rbtree_insert(t, key);
  assert(p != NULL);
  assert(t->root == p);
  assert(p->key == key);

  rbtree_erase(t, p);
#ifdef SENTINEL
  assert(t->root == t->nil);
#else
  assert(t->root == NULL);
#endif

  delete_rbtree(t);
}

static void insert_arr(rbtree *t, const key_t *arr, const size_t n) {
  for (size_t i = 0; i < n; i++) {
    rbtree_insert(t, arr[i]);
  }
}




void test_find_erase(rbtree *t, const key_t *arr, const size_t n) {
  for (int i = 0; i < n; i++) {
    node_t *p = rbtree_insert(t, arr[i]);
    printf("%d", arr[i]);
    assert(p != NULL);
  }

  for (int i = 0; i < n; i++) {
    node_t *p = rbtree_find(t, arr[i]);
    printf("arr[%d] = %d\n", i, arr[i]);
    assert(p != NULL);
    assert(p->key == arr[i]);
    rbtree_erase(t, p);
  }

  // for (int i = 0; i < n; i++) {
  
  //   node_t *p = rbtree_find(t, arr[i]);
  
  //   assert(p == NULL);
  // }

  // for (int i = 0; i < n; i++) {
  //   node_t *p = rbtree_insert(t, arr[i]);
  //   assert(p != NULL);
  //   node_t *q = rbtree_find(t, arr[i]);
  //   assert(q != NULL);
  //   assert(q->key == arr[i]);
  //   assert(p == q);
  //   rbtree_erase(t, p);
  //   q = rbtree_find(t, arr[i]);
  //   assert(q == NULL);
  // }
}

void test_find_erase_fixed() {
  const key_t arr[] = {10, 5, 8, 34, 67, 23, 156, 24, 2, 12, 24, 36, 990, 25};
  const size_t n = sizeof(arr) / sizeof(arr[0]);
  rbtree *t = new_rbtree();
  assert(t != NULL);
  test_find_erase(t, arr, n);
  delete_rbtree(t);
}


int main(void) {
  rbtree *p_rbt = new_rbtree();
  rbtree_insert(p_rbt, 20);
  rbtree_insert(p_rbt, 10);
  rbtree_insert(p_rbt, 50);
  rbtree_insert(p_rbt, 30);
  rbtree_insert(p_rbt, 80);
  rbtree_insert(p_rbt, 40);
  rbtree_insert(p_rbt, 35);
  rbtree_insert(p_rbt, 25);

  int arr[8] = {0,};
  rbtree_to_array(p_rbt, arr, 8);
  for(int i =0; i<8; i++){
    printf("%d ",arr[i]);
  }
  printf("Passed all tests!\n");
}
