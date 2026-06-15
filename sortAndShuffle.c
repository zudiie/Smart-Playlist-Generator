//including header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sortAndShuffle.h"


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

void sortArtistsAndSongs(Artist artists[], int numOfArtists) {
    int i, j, k;

    //sort artists using selection sort
	for (i = 0; i < numOfArtists - 1; i++){
		for (j = i + 1; j < numOfArtists; j++){
            // check if the name of the artist at index i comes
            // after the name of the artist at index j in alphabetical order
			if (strcmp(artists[i].name, artists[j].name) > 0){
				char temp[MAX_LENGTH];
				strcpy(temp, artists[i].name);
				strcpy(artists[i].name, artists[j].name);
				strcpy(artists[j].name, temp);
                
                // swap numOfSongs count for artists
                int tempNumSongs = artists[i].numOfSongs;
                artists[i].numOfSongs = artists[j].numOfSongs;
                artists[j].numOfSongs = tempNumSongs;

                // if artists are swapped, their respective songs also need to be swapped
				for (k = 0; k < MAX_SONGS; k++){
					strcpy(temp, artists[i].songs[k]);
					strcpy(artists[i].songs[k], artists[j].songs[k]);
					strcpy(artists[j].songs[k], temp);
				}
				}
			}
		}

	//sort songs alphabetcially using bubble sort
	for (i = 0; i < numOfArtists; i++) {
	        for (j = 0; j < artists[i].numOfSongs - 1; j++) {
	            for (k = j + 1; k < artists[i].numOfSongs; k++) {
                    // check if the name of the song at index j comes
                    // after the name of the song at index k in alphabetical order
	                if (strcmp(artists[i].songs[j], artists[i].songs[k]) > 0) {
	                    char temp[MAX_LENGTH];
	                    strcpy(temp, artists[i].songs[j]);
	                    strcpy(artists[i].songs[j], artists[i].songs[k]);
	                    strcpy(artists[i].songs[k], temp);
	                }
	            }
	        }
	    }
}

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

void duplicateSongs(Artist artists[], int numOfArtists, char songs[2*MAX_TOTAL_SONGS][MAX_LENGTH], char artistsList[2*MAX_TOTAL_SONGS][MAX_LENGTH], int *totalSongs) {
    int i, j, index = 0;
    
    //using for loop, duplicate songs and artists to match their songs
    for (i = 0; i < numOfArtists; i++) {
        for (j = 0; j < artists[i].numOfSongs; j++) {
            strcpy(songs[index], artists[i].songs[j]);
            strcpy(artistsList[index], artists[i].name);
            index++;
            strcpy(songs[index], artists[i].songs[j]);
            strcpy(artistsList[index], artists[i].name);
            index++;
        }
    }

    //pass the value of the index to the pointer to the totalSongs
    *totalSongs = index;
}

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

 void fisherYatesShuffle(char songs[2 * MAX_TOTAL_SONGS][MAX_LENGTH], char artistsList[2 * MAX_TOTAL_SONGS][MAX_LENGTH], int totalSongs){
    // initialise random number generator
     srand(time(NULL));
     
     for (int i = 1; i < totalSongs; i++)
     {
         int j = rand() % (i + 1); //j is a random number between 0 and i   
         if (j != i){ //if i is not equal to j, then we swap the songs at locations i and j
            // swap songs
             char temp[MAX_LENGTH];
             strcpy(temp, songs[j]);
             strcpy(songs[j], songs[i]);
             strcpy(songs[i], temp);
             //swap corresponding artists
             char tempArtist[MAX_LENGTH];
             strcpy(tempArtist, artistsList[j]);
             strcpy(artistsList[j], artistsList[i]);
             strcpy(artistsList[i], tempArtist);
         }
     }
 }

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

 int isValidShuffle(char songs[2 * MAX_TOTAL_SONGS][MAX_LENGTH], int totalSongs) {
    // scan every song
    for (int i = 0; i < totalSongs; i++) {
        //check within next 5 songs
        for (int j = i + 1; j < totalSongs && j <= i + 5; j++) {
            if (strcmp(songs[i], songs[j]) == 0) {
                return 0;  // invalid shuffle
            }
        }
    }
    return 1;  // valid shuffle
}

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

void shuffleSongs(Artist artists[], int numOfArtists) {
    //create arrays to store duplicated songs and their matching artists
    char songs[2*MAX_TOTAL_SONGS][MAX_LENGTH];
    char artistsList[2*MAX_TOTAL_SONGS][MAX_LENGTH];
    int totalSongs;

    duplicateSongs(artists, numOfArtists, songs, artistsList, &totalSongs);
    // if the number of songs is less than or equal to 10, the program prints an error
    if (totalSongs <= 10) {
        printf("Error: Not enough songs to meet the shuffle requirement. (For efficient shuffle, enter at least 8 songs)\n");
        return;
    }
    //shuffle the playlist until we get a valid one
    do {
        fisherYatesShuffle(songs, artistsList, totalSongs);
    } while (!isValidShuffle(songs, totalSongs));
    
    //print out the playlist
    printf("\nShuffled Playlist:\n\n");
    for (int i = 0; i < totalSongs; i++) {
        printf("%s - %s\n", artistsList[i], songs[i]);
    }
}



