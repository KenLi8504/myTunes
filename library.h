int findWhichList(struct song_node *example);
int findWhichListName(char name[]);
struct song_node **makeLibrary();
struct song_node ** addSong(struct song_node **library, struct song_node *example);
struct song_node * findSong(struct song_node **library, char title[], char artist[]);
struct song_node * findArtist(struct song_node **library, char artist[]);
void printOneLetter(struct song_node **library, char letter []);
struct song_node ** clear_library(struct song_node **library);
void printLibrary(struct song_node **library);
void printArtist(struct song_node **library,char letter[]);
struct song_node ** deleteSong(struct song_node ** library, char newName[], char newArtist[]);
void shuffle(struct song_node **library);
