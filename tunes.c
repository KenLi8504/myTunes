#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct song_node{
  char name [100];
  char artist [100];
  struct song_node *next;
};

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
  if (start == NULL){
    return;
  }
    printf("The song is %s, and the artist is %s.\n",start -> name,start->artist);
    print_list(start -> next);
}

int compareNodes (struct song_node *song1, struct song_node *song2){
  int status = strcasecmp(song1->artist,song2->artist);
  printf("song1 is %s, song2 is %s\n",song1->artist,song2->artist);
  if (status == 0){
    printf("USED THIS \n");
    status = strcasecmp(song1->name,song2->name);
  }
  printf("The status is %d\n",status);
  return status;
}

struct song_node * insert_front (struct song_node * first, struct song_node *newSong){
  newSong -> next = first;
  return newSong;
}

struct song_node * insert_ordered(struct song_node * first, struct song_node *newSong){
  struct song_node * start = first;
  if (first == NULL || compareNodes(first,newSong) > 0){
    newSong -> next = first;
    return newSong;
  }
  while (first -> next != NULL){
    if (compareNodes(first,newSong) > 0){
      first = first -> next;
      printf("THE NEW LETTER IS %s\n",first -> artist);
    }
    else{
      struct song_node * temp = first -> next;
      first -> next = newSong;
      newSong -> next = temp;
      return start;
    }
  }
  struct song_node * temp = first -> next;
  first -> next = newSong;
  newSong -> next = temp;
  return start;
}

int main(){
  //struct song_node * library[27];
  struct song_node * start = NULL;
  struct song_node * a = makeNode("a","a");
  struct song_node * b = makeNode("a","d");
  struct song_node * c = makeNode("a","b");
  struct song_node * d = makeNode("a","c");
  struct song_node * e = makeNode("a","e");
  compareNodes(a,c);
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
  printf("\n");
  return 0;
}
