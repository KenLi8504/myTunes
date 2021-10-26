#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "linkedlist.h"

struct song_node * makeNode(char newName[],char newArtist[]){
  struct song_node *newNode = malloc(sizeof(struct song_node));
  strncpy(newNode -> name, newName,98);
  newNode ->name [99] = '\0';
  strncpy(newNode -> artist, newArtist,98);
  newNode ->artist [99] = '\0';
  newNode -> next = NULL;
  return newNode;
}

void print_list (struct song_node * start){
  printf("[");
  while (start != NULL){
    printf("\"%s\",%s; ",start -> name,start->artist);
    start = start -> next;
  }
  printf("]");
}

int compareNodes (struct song_node *song1, struct song_node *song2){
  int status = strcasecmp(song1->artist,song2->artist);
  if (status == 0){
    status = strcasecmp(song1->name,song2->name);
  }
  return status;
}

struct song_node * insert_front (struct song_node * first, struct song_node *newSong){
  newSong -> next = first;
  return newSong;
}

// Inserts A Song Node Into The Proper Order Of A Linked List
struct song_node *insert_ordered(struct song_node *first, struct song_node *newSong) {
  struct song_node *start = first;
    if (first == NULL || compareNodes(newSong, first) <= 0){
      newSong -> next = first;
      return newSong;
    }
    while (first ->next != NULL) {
        if (compareNodes(newSong,first ->next) <= 0) {
          struct song_node * temp = first -> next;
          first -> next = newSong;
          newSong -> next = temp;
          return start;
        }
        first = first ->next;
      }
    struct song_node * temp = first -> next;
    first -> next = newSong;
    newSong -> next = temp;
    return start;
}

struct song_node *nodeGivenArtistAndSong(struct song_node *start, char newName[],char newArtist[]){
  while (start != NULL){
    if (strcasecmp(start -> name,newName) || strcasecmp(start -> artist,newArtist)){
      start = start ->next;
    }
    else{
      return start;
    }
  }
  return NULL;
}

struct song_node *nodeGivenArtist(struct song_node *start,char newArtist[]){
  while (start != NULL){
    if (strcasecmp(start -> artist,newArtist)){
      start = start ->next;
    }
    else{
      return start;
    }
  }
  return NULL;
}

struct song_node * remove_node(struct song_node *start, char *song, char *artist) {
    struct song_node *beg = start;
    struct song_node *temp = start;
    if ( strcasecmp(start->name,song)== 0 && strcasecmp(start->artist,artist) == 0){
      if (start-> next == NULL){
        struct song_node *new = NULL;
        return new;
      }
      else{
        beg = start->next;
      }
    }
    while (start != NULL && ( (strcasecmp(start->name,song)!= 0 || strcasecmp(start->artist,artist)!=0 ) )) {
        temp = start;
        start = start->next;
    }
    if (start != NULL){
        temp->next = start->next;
        free(start);
    }
    return beg;
}

struct song_node *findRandomSong(struct song_node *first) {
  struct song_node *temp = first;
  int counter = 0;
  while (first != NULL){
    counter++;
    first = first -> next;
  }
  int index = rand();
  index = index % counter;
  for (int i = 0; i < index; i++){
    temp = temp -> next;
  }
  return temp;
}


struct song_node *free_list(struct song_node *first) {
    struct song_node *temp = first;
    while (first != NULL) {
        first = first->next;
        free((void *) first);
        temp = first;
    }
    return first;
}
