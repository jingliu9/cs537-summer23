#ifndef MY_LINKEDLIST_H
#define MY_LINKEDLIST_H

struct lst_node {
  void *val;
  struct lst_node *prev;
  struct lst_node *next;
};

struct lst {
  struct lst_node *head;
  struct lst_node *tail;
};

struct lst *ll_init();
void ll_push_back(struct lst *ll, void *value);
void *ll_remove(struct lst *ll, struct lst_node *node);

#endif  // MY_LINKEDLIST_H