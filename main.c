//including header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortAndShuffle.h"

//function prototypes
void printAscii();
int insertArtists(Artist artists[]);
void printArtists(Artist artists[], int numOfArtists);

/*
 * This method prints an ASCII art at the end of the execution of this program
 *
 * There is no input or output.
 */
void printAscii(){
	puts("");
	printf("     ;\n"); 
	printf("     ;;\n");
	printf("     ;';.\n");
	printf("     ;  ;;\n");
	printf("     ;   ;;\n");
	printf("     ;    ;;\n");
	printf("     ;    ;;\n");
	printf("     ;   ;'\n");
	printf("     ;  \n");
	printf(",;;;,;  \n");
	printf(";;;;;;  \n");
	printf("`;;;;'  \n");
	puts("");
}

/*
 * This function writes the artist and a set of songs provided from the command line
 * in an array provided as input.
 *
 * Input:
 * Artist artists[]: The array of artists structures, which contains the name of the artist
 * song titles and the number of songs.
 *
 * Output: The number of artists provided as input
 */

int insertArtists(Artist artists[]) {
    int i, j, length;
	// initialise a variable for the number of artists
    int numOfArtists = 0;

	printf("Weclome to Playlist Generator!\n");

    // use a for loop to insert the artists and their songs into artists[]
    for (i = 0; i < MAX_ARTISTS; i++){

    	printf("Insert an artist/group name:\n");

    	fflush(stdout); // this ensures that any buffered output is immediately printed to the console

    	// get artist's name from the user using fgets()
    	fgets(artists[i].name, MAX_LENGTH, stdin);

		//find length of the string with the name in order to remove the newline character at the end of the string for correct output
		length = strlen(artists[i].name);

		//if there is empty input (no artists) skip to the next artist
    	if (artists[i].name[0] == '\n'){
    		artists[i].name[length -1] = '\0';
			break;
    	}

		artists[i].name[length -1] = '\0';
    	artists[i].numOfSongs = 0;

    	// insert up to 3 songs per artist
		for(j = 0; j < MAX_SONGS; j++){
			printf("Insert Song %d for %s\n", j+1, artists[i].name);
			fflush(stdout);
			//get songs from artist using fgets()
			fgets(artists[i].songs[j], MAX_LENGTH, stdin);
			//If the return command is pressed it exits
			if(artists[i].songs[j][0] =='\n'){
				break;
			}
			// increment number of songs
			artists[i].numOfSongs++;
			//Remove the newline character from the song
			length = strlen(artists[i].songs[j]);
			artists[i].songs[j][length -1] = '\0';
		}
		printf("\n");
		numOfArtists++; //increase the number of artists by 1
    }
    // return number of artists
    return numOfArtists;
}


/*
 * This method prints the songs provided as input
 *
 * Inputs:
 * Artist artists[]: The array of artists structures, which contains the name of the artist
 * song titles and the number of songs.
 * numOfArtists: the number of artists
 * 
 * There is no output.
 */

void printArtists(Artist artists[], int numOfArtists){
    int i, j;
    printf("\nSorted list of songs:\n\n");
    fflush(stdout);

    for(i = 0; i < numOfArtists; i++){
    	// print artist name
        printf("%s\n", artists[i].name); //print artist's name
        // go through the songs of that artist using for loop
        for (j = 0; j < MAX_SONGS; j++) {
        	if (j < artists[i].numOfSongs) {
        		printf("- %s\n", artists[i].songs[j]); //print songs
        	}
        }
        printf("\n");
    }

}

int main(void)
{
    // an array of Artist structures to keep track of songs linked to a particular artist
    Artist artists[MAX_ARTISTS];
    // variable to count the number of artists
    int numOfArtists;

    // insert songs and artists from the command line and return the number of artists
    numOfArtists = insertArtists(artists);

    // this call will sort songs alphabetically
    sortArtistsAndSongs(artists, numOfArtists);

    // print the list with artists and their songs
    printArtists(artists, numOfArtists);

	// this function shuffles the songs
	shuffleSongs(artists, numOfArtists);

	// this call prints ASCII art at the end of the execution of this program
	printAscii();

    return 0;
}
