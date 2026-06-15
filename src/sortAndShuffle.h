//max number of songs per artist
#define MAX_SONGS 3
//max number of artists
#define MAX_ARTISTS 4
//max length of a string for each song/artist
#define MAX_LENGTH 80
//max number of songs that user can input
#define MAX_TOTAL_SONGS 12

//struct to represent an artist
typedef struct {
	char name[MAX_LENGTH];
	char songs[MAX_SONGS][MAX_LENGTH];
	int numOfSongs;
} Artist;

/*
 * This method sorts the artists and their songs alphabetically
 *
 * Inputs:
 * Artist artists[]: The array of artists structures, which contains the name of the artist
 * song titles and the number of songs.
 * numOfArtists: the number of artists
 * 
 * There is no output.
 */

void sortArtistsAndSongs(Artist artists[], int numOfArtists);

/*
 * This method duplicates the songs and puts them into one array
 *
 * Inputs:
 * Artist artists[]: The array of artists structures, which contains the name of the artist
 * song titles and the number of songs.
 * numOfArtists: the number of artists
 * char songs[2*MAX_TOTAL_SONGS][MAX_LENGTH]: array of where duplicated songs are stored
 * char artistsList[2*MAX_TOTAL_SONGS][MAX_LENGTH]: array of artists stored to match their songs
 * int *totalSongs: pointer to a variable storing the number of songs
 * 
 * There is no output.
 */

void duplicateSongs(Artist artists[], int numOfArtists, char songs[2*MAX_TOTAL_SONGS][MAX_LENGTH], char artistsList[2*MAX_TOTAL_SONGS][MAX_LENGTH], int *totalSongs);

/*
 * This method shuffles the songs using Fisher Yates algorithm
 *
 * Inputs:
 * char songs[2*MAX_TOTAL_SONGS][MAX_LENGTH]: array of duplicated songs
 * char artistsList[2*MAX_TOTAL_SONGS][MAX_LENGTH]: array of artists stored to match their songs
 * int totalSongs: number of songs
 * 
 * There is no output.
 */

void fisherYatesShuffle(char songs[2*MAX_TOTAL_SONGS][MAX_LENGTH], char artistsList[2*MAX_TOTAL_SONGS][MAX_LENGTH], int totalSongs);

/*
 * This method checks if the shuffled list of songs is valid.
 * A shuffled list of songs is valid if no song appears more than once within a 5-song interval
 *
 * Inputs:
 * char songs[2*MAX_TOTAL_SONGS][MAX_LENGTH]: array of shuffled songs
 * int totalSongs: number of songs
 * 
 * Output:
 * 0 (False) - if the list is NOT valid
 * 1 (True) - if the list is valid
 */

int isValidShuffle(char songs[2*MAX_TOTAL_SONGS][MAX_LENGTH], int totalSongs);

/*
 * This method shuffles the songs
 *
 * Inputs:
 * Artist artists[]: The array of artists structures, which contains the name of the artist
 * song titles and the number of songs.
 * int numOfArtists: the number of artists
 * 
 * There is no output.
 */

void shuffleSongs(Artist artists[], int numOfArtists);


