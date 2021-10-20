#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct song_node{
  char name [100];
  char artist [100];
  struct song_node *next;
};

int compareNodes (struct song_node *song1, struct song_node *song2){
  int status = strcasecmp(song1->artist,song2->artist);
  if (status == 0){
    status = strcasecmp(song1->name,song2->name);
  }
  return status;
}

struct song_node * makeNode(char newName[],char newArtist[]){
  struct song_node *newNode = malloc(sizeof(struct song_node));
  strncpy(newNode -> name, newName,98);
  newNode ->name [99] = '\0';
  strncpy(newNode -> artist, newArtist,98);
  newNode ->artist [99] = '\0';
  return newNode;
}

void print_list (struct song_node * start){
  if (start == NULL){
    return;
  }
    printf("The song is %s, and the artist is %s.\n",start -> name,start->artist);
    print_list(start -> next);
}

int main(){
  //struct song_node * library[27];
  struct song_node * node1 = makeNode("Sound of Silence","Simon and Garfinkel");
  struct song_node * node2 = makeNode("Wonder Wall", "Oasis");
  int output = compareNodes(node1,node2);
  printf("The output is %d",output);
  return 0;
}
