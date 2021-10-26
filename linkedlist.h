struct song_node{
  char name [100];
  char artist [100];
  struct song_node *next;
};
struct song_node * makeNode(char newName[],char newArtist[]);
void print_list (struct song_node * start);
int compareNodes (struct song_node *song1, struct song_node *song2);
struct song_node * insert_front(struct song_node * first, struct song_node *newSong);
struct song_node *insert_ordered(struct song_node *first, struct song_node *newSong);
struct song_node *nodeGivenArtistAndSong(struct song_node *start, char newName[],char newArtist[]);
struct song_node *nodeGivenArtist(struct song_node *start,char newArtist[]);
struct song_node *remove_node(struct song_node *first, char newName[],char artist[]);
struct song_node *free_list(struct song_node *first);
struct song_node *findRandomSong(struct song_node *first);
