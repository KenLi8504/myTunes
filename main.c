#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "library.h"

//THIS IS FOR TESTING
void printNode(struct song_node *node){
  printf("The song is %s and the songName is %s\n",node->name,node->artist);
}

int main(){
  printf("\nTHIS IS THE START OF THE LIBRARY TESTS.\n");
  struct song_node ** library = makeLibrary();
  struct song_node * a = makeNode("GANGNAM STYLE","PSY");
  struct song_node * b = makeNode("Bang Bang","Arena Grenade");
  struct song_node * c = makeNode("Rich and Blind","Juice WRLD");
  struct song_node * d = makeNode("Counting Stars","One Republic");
  struct song_node * e = makeNode("Apologize","One Republic");
  struct song_node * f = makeNode("the nights","Avicii");
  struct song_node * g = makeNode("levels","avicii");
  struct song_node * h = makeNode("keyboard smash","!@#$!$!");

  printf("\nTESTING ADDING SONG NODES AND FOR PRINTING OUT SPECIFIC LETTERS\n");
  library = addSong(library,a);
  printOneLetter(library,"P");
  printf("\n");
  library = addSong(library,b);
  printOneLetter(library,"A");
  printf("\n");
  library = addSong(library,c);
  printOneLetter(library,"J");
  printf("\n");
  library = addSong(library,d);
  printOneLetter(library,"O");
  printf("\n");
  library = addSong(library,e);
  printOneLetter(library,"O");
  printf("\n");
  library = addSong(library,f);
  printOneLetter(library,"a");
  printf("\n");
  library = addSong(library,g);
  printOneLetter(library,"a");
  printf("\n");
  library = addSong(library,h);
  printOneLetter(library,"!");
  printf("\n");

  printf("\nTESTING FOR PRINTING OUT THE ENTIRE LIBRARY\n");
  printLibrary(library);

  printf("\nTESTING FOR FINDING A SONG AND ARTIST PAIR\n");
  struct song_node * temp = findSong(library,"the nights", "Avicii");
  printNode(temp);
  temp = findSong(library,"Rich and Blind","Juice WRLD");
  printNode(temp);
  temp = findSong(library,"keyboard smash","!@#$!$!");
  printNode(temp);

  printf("\nTESTING FOR FINDING AN ARTIST\n");
  temp = findArtist(library,"One Republic");
  printNode(temp);
  temp = findArtist(library,"Avicii");
  printNode(temp);

  printf("\nTESTING FOR PRINTING ALL SONGS OF ONE ARTIST\n");
  printf("PRINTING ALL AVICII SONGS\n");
  printArtist(library,"avicii");
  printf("PRINTING ALL ONE REPUBLIC SONGS\n");
  printArtist(library,"One republic");

  printf("\nTESTING REMOVING SONGS FROM THE LIBRARY\n");

  printf("DELETING GANGNAM STYLE");
  printOneLetter(library,"P");
  library = deleteSong(library,"GANGNAM STYLE","PSY");
  printf("\n");
  printOneLetter(library,"P");
  printf("\n");

  printf("DELETING THE ARIANA GRANDE SONG\n");
  printOneLetter(library,"A");
  printf("\n");
  library = deleteSong(library, "BANG BANG","ARENA GRENADE");
  printOneLetter(library,"A");
  printf("\n");

  printf("\n TESTING SHUFFLE \n");
  for (int i = 0; i < 3; i++){
    shuffle(library);
    printf("\n");
  }
  printf("\n TESTING OUT CLEARING ALL THE LINKED LISTS\n");
  clear_library(library);
  printLibrary(library);

  printf("\nTESTING THE LINKED LIST ASPECT.\n");
  struct song_node * start = NULL;
  struct song_node * a = makeNode("GANGNAM STYLE","PSY");
  struct song_node * b = makeNode("Bang Bang","Arena Grenade");
  struct song_node * c = makeNode("Rich and Blind","Juice WRLD");
  struct song_node * d = makeNode("Counting Stars","One Republic");
  struct song_node * e = makeNode("Apologize","One Republic");

  printf("\nTESTING INSERTING AT FRONT.\n");
  start = insert_front(start,a);
  print_list(start);
  printf("\n");
  start = insert_front(start,b);
  print_list(start);
  printf("\n");
  start = insert_front(start,c);
  print_list(start);
  printf("\n");
  start = insert_front(start,d);
  print_list(start);
  printf("\n");
  start = insert_front(start,e);
  print_list(start);
  printf("\n");

  printf("\nTESTING REMOVE\n");
  start = remove_node(start,"GANGNAM STYLE","PSY");
  print_list(start);
  printf("\n");
  start = remove_node(start,"Bang Bang","Arena Grenade");
  print_list(start);
  printf("\n");
  start = remove_node(start,"Rich and Blind","Juice WRLD");
  print_list(start);
  printf("\n");
  start = remove_node(start,"Counting Stars","One Republic");
  print_list(start);
  printf("\n");
  start = remove_node(start,"Apologize","One Republic");
  print_list(start);
  printf("\n");

  start = NULL;
  a = makeNode("GANGNAM STYLE","PSY");
  b = makeNode("Bang Bang","Arena Grenade");
  c = makeNode("Rich and Blind","Juice WRLD");
  d = makeNode("Counting Stars","One Republic");
  e = makeNode("Apologize","One Republic");

  printf("\nTESTING BASIC ADDING IN ORDER\n");
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

  printf("\nTESTING FINDING A POINTER BASED ON ARTIST AND SONG NAME\n");
  struct song_node *node = nodeGivenArtistAndSong(start, "Counting Stars", "One Republic");
  printNode(node);
  node = nodeGivenArtistAndSong(start,"GANGNAM STYLE", "PSY");
  printNode(node);

  printf("\nTESTING FINDING A POINTER FOR THE FIRST SONG BY AN ARTIST\n");
  node = nodeGivenArtist(start,"PSY");
  printNode(node);
  node = nodeGivenArtist(start,"One Republic");
  printNode(node);

  printf("\nTESTING RETURNING A POINTER TO A RANDOM ELEMENT\n");
  for (int i = 1; i <= 10; i++){
    printf("ROLL #%d\n",i);
    node = findRandomSong(start);
    printNode(node);
  }

  printf("\nFREEING EVERYTHING");
  start = free_list(start);
  printf("\nTHE LINKED LIST SHOULD NOW BE EMPTY\n");
  print_list(start);
   return 0;
 }
