# Smart-Playlist-Generator

## Overview
This project implements an interactive command-line playlist manager in C. It allows users to manage music artists and their songs, automatically sorts them alphabetically, and generates a randomized tracklist using a smart duplication and spacing validation loop.

---

## Implementation Details

### 1. Sorting Algorithm
* **Algorithms used:** Selection Sort (for artists) and Bubble Sort (for songs).
* **Details:** **Artist Sorting:** Uses selection sort to evaluate and order artist names alphabetically via `strcmp`. When two artists are swapped, their corresponding song matrices and track counters are swapped alongside them to maintain data integrity.
  * **Song Sorting:** Executes a nested bubble sort pass to arrange each individual artist's song collection in alphabetical order.
  * **Efficiency:** Tailored directly for lightweight local playlist arrays defined by explicit constants (`MAX_ARTISTS 4`, `MAX_SONGS 3`), eliminating unnecessary overhead from external libraries.

### 2. Shuffling Algorithm
* **Algorithm used:** Fisher-Yates Shuffle with Lookahead Validation.
* **Steps:**
  * **Duplicate the List:** The program copies every input track sequentially into a separate streaming array, tracking both the song and the matching artist so each track plays exactly twice.
  * **Apply Fisher-Yates Shuffle:** Loops forward through the expanded array, using `rand()` to swap the current song and artist with an element at a randomly calculated preceding index.
  * **Ensure Spacing Constraints:** A lookahead validation loop checks the next 5 songs in the sequence. If an identical song is found within this 5-position window, the shuffle is marked invalid, triggering a `do-while` loop to reshuffle the entire array until the condition is met.
  * **Output the Shuffled Playlist:** Displays the validated, double-capacity playlist directly to the command-line console.

---

## Algorithms Used
* **Selection Sort** -> For sorting multi-artist datasets alphabetically.
* **Bubble Sort** -> For alphabetizing individual track catalogs per artist.
* **Fisher-Yates Shuffle** -> For generating an unbiased, randomized starting queue.
* **Lookahead Validation Window** -> Custom constraint checking that guarantees a minimum 5-song gap between recurring duplicates.

---

## Conclusion
This program successfully demonstrates:
* Synchronized sorting across interconnected data structures to preserve track ownership metadata.
* A strict constraint-driven randomizer framework that effectively eliminates repetitive audio clusters.

The implementation provides an effective balance between deterministic alphabetical organization and controlled, non-repetitive random playback.

---

## Installation & Usage
To compile and run this project locally, ensure you have a standard C compiler (like `gcc`) installed, then run:

```bash
# Compile the source files
gcc main.c sortAndShuffle.c -o playlist_generator

# Run the executable
./playlist_generator
