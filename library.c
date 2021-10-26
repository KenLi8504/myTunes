#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "linkedlist.h"
#include "library.h"

int findWhichList(struct song_node *example){
  int firstLetter = tolower((example->artist)[0]);
  if (firstLetter >= 97 && firstLetter <= 122){
    return firstLetter-97;
  }
  else{
    return 26;
  }
}

int findWhichListName(char artist[]){
  int firstLetter = tolower(artist[0]);
  if (firstLetter >= 97 && firstLetter <= 122){
    return firstLetter-97;
  }
  else{
    return 26;
  }
}

struct song_node **makeLibrary() {
    struct song_node ** library = calloc(27, sizeof(struct song_node *));
    return library;
}

struct song_node ** addSong(struct song_node **library, struct song_node *example) {
  int index = findWhichList(example);
  library[index] = insert_ordered(library[index],example);
  return library;
}

struct song_node * findSong(struct song_node **library, char title[], char artist[]) {
  int index = findWhichListName(artist);
  return nodeGivenArtistAndSong(library[index], title, artist);
}

struct song_node * findArtist(struct song_node **library, char artist[]) {
    int index = findWhichListName(artist);
    return nodeGivenArtist(library[index],artist);
}

void printOneLetter(struct song_node **library, char letter []) {
  int index = findWhichListName(letter);
  print_list(library[index]);
}

struct song_node ** clear_library(struct song_node **library) {
    for (int i = 0; i < 27; i++){
        library[i] = free_list(library[i]);
    }
    return library;
}

void printArtist(struct song_node **library,char letter[]){
  int index = findWhichListName(letter);
  struct song_node *current = library[index];
  while(current != NULL){
    if (strcasecmp(current->artist,letter) == 0){
      printf("The song is %s and the artist is %s\n",current->name,current->artist);
    }
    current = current -> next;
  }
}

struct song_node ** deleteSong(struct song_node ** library, char newName[], char newArtist[]){
  int index = findWhichListName(newArtist);
  library[index] = remove_node(library[index],newName,newArtist);
  return library;
}

void printLibrary(struct song_node **library){
  for (int i = 0; i < 27; i++){
    print_list(library[i]);
    printf("\n");
  }
}

void shuffle(struct song_node **library) {
  for (int i = 0; i < 5; i++){
    int index = rand()%27;
    while (library[index] == NULL){
      index = rand()%27;
    }
    struct song_node *current = findRandomSong(library[index]);
    printf("The song is %s and the artist is %s\n",current->name,current->artist);
  }
}
