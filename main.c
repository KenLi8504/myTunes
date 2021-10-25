#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkedlist.h"
//#include "library.h"
int main(){
  struct song_node * library[27];
  struct song_node * start = NULL;
  struct song_node * a = makeNode("ab","ab");
  struct song_node * b = makeNode("ad","a");
  struct song_node * c = makeNode("ba","ac");
  struct song_node * d = makeNode("ac","ab");
  struct song_node * e = makeNode("ae","ae");
  printf("TESTING BASIC ADDING IN ORDER\n");
  start = insert_ordered(start,a);
    print_list(start);
    printf("\n");
  start = insert_ordered(start,b);
      print_list(start);
      printf("\n");
  start = insert_ordered(start,c);
      print_list(start);
      printf("\n");
  start = insert_ordered(start,d);
      print_list(start);
      printf("\n");
  start = insert_ordered(start,e);
  print_list(start);

  printf("TESTING BASIC REMOVE\n");
  print_list(start);
  printf("\n");

  printf("Removing ba/ac\n");
  start = remove_node(start,"ba","ac");
  print_list(start);
  printf("\n");

  printf("Removing ab/ab\n");
  start = remove_node(start,"ab","ab");
  print_list(start);
  printf("\n");

  printf("Removing ad/a\n");
  start = remove_node(start,"ad","a");
  print_list(start);
  printf("\n");
  return 0;
}
