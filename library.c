#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "linkedlist.h"
#include "library.h"

int findWhichList(struct song_node *example){

  int firstLetter = example -> artist;
  firstLetter = tolower(firstLetter);
  return firstLetter-97;
}

int findWhichListName(char name[]){
  int firstLetter = tolower(name[0]);
  return firstLetter-97;
}

struct song_node **makeLibrary(struct song_node **library) {
    library = calloc(27, sizeof(struct song_node *));
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
  print_list(library[letter]);
}

struct song_node ** clear_library(struct song_node **library) {
    for (int i = 0; i < 27; i++){
        library[i] = free_list(library[i]);
    }
    return library;
}
