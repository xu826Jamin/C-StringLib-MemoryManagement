    #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"

char **read_words(const char *input_filename, int *nPtr){
	
    char **wordArray = NULL;
    FILE *filePtr;
    char tempLine[100];  // Temporary storage for each line
    int wordCount, index;
    int strLength;
    
    // Step 1: Open file in ASCII read mode
    filePtr = fopen(input_filename, "r");
    if (!filePtr) {
        printf("Cannot open input file\n");
        return NULL;
    }
    
    // Step 2: Read the first line as integer into nPtr
    if (fscanf(filePtr, "%d", nPtr) != 1) {
        fclose(filePtr);
        return NULL;
    }
    fgetc(filePtr);  // Skip newline
    
    // Step 3: Allocate array of char pointers
    wordArray = (char**)malloc(*nPtr * sizeof(char*));
    if (!wordArray) {
        fclose(filePtr);
        return NULL;
    }
    
    // Step 4: Read each line and allocate space for each word
    for (wordCount = 0; wordCount < *nPtr; wordCount++) {
        if (fgets(tempLine, sizeof(tempLine), filePtr)) {
            // Clean up newline
            strLength = strlen(tempLine);
            if (strLength > 0 && tempLine[strLength-1] == '\n') {
                tempLine[--strLength] = '\0';
            }
            
            // Create space for word
            wordArray[wordCount] = (char*)malloc((strLength + 1) * sizeof(char));
            if (!wordArray[wordCount]) {
                // Clean up on failure
                for (index = 0; index < wordCount; index++) {
                    free(wordArray[index]);
                }
                free(wordArray);
                fclose(filePtr);
                return NULL;
            }
            strcpy(wordArray[wordCount], tempLine);
        }
    }
    
    // Step 5: Close file
    fclose(filePtr);
    
    return wordArray;
}

void swap(char **str1, char **str2)
{    
    // Hint: str1 and str2 are not just double pointers - they are single pointers passed-by-reference
    //       Therefore, you should treat *str1 and *str2 as changeable addresses of the start of their
    //       respective strings.

    // Hint 2: Swapping two strings in an array of strings is as easy as swapping the starting addresses
    //         of the two target strings to be swapped.  Review Lecture Contents!

    char *tempStr;
    tempStr = *str1;
    *str1 = *str2;
    *str2 = tempStr;
}

void delete_wordlist(char **word_list, int size)
{
    /*This is a helper function that you MUST IMPLEMENT and CALL at the end of every test case*/
    /*THINK ABOUT WHY!!!*/

    // implement your table deletion code here //
    int index;
    
    // Safety check
    if (!word_list) return;
    
    // First deallocate each word
    for (index = 0; index < size; index++) {
        if (word_list[index]) {
            free(word_list[index]);
            word_list[index] = NULL;  // Prevent dangling pointers
        }
    }
    
    // Finally deallocate the array
    free(word_list);
}

void sort_words_Bubble(char **words, int size)
{   
    // !!IMPLEMENT SWAP() BEFORE ATTEMPTING THIS FUNCTION!! //

    // By this time you should be able to implement bubble sort with your eyes closed ;)

    // Hint: Use your own my_strcmpOrder to compare the ASCII size of the two strings, and
    //       use the returned result as the sorting reference.  

    // Hint: Use swap() if string swapping is required
    
    int outer, inner;
    int didSwap;
    int lastUnsorted;
    
    lastUnsorted = size - 1;
    
    while (lastUnsorted > 0) {
        didSwap = 0;
        for (inner = 0; inner < lastUnsorted; inner++) {
            if (my_strcmpOrder(words[inner], words[inner + 1]) == 1) {
                swap(&words[inner], &words[inner + 1]);
                didSwap = 1;
            }
        }
        if (!didSwap) {
            return;  // Early exit if sorted
        }
        lastUnsorted--;
    }
}



void sort_words_Selection(char **words, int size){

    // This implementation of string-sorting function using Selection Sort contains 2 semantic bugs

    // Fix the code, and document how you've found the bugs using GNU debugger.
    // Take screenshots of the debugger output at the instance where you've determined every bug.

    // You will be tested again at the cross exam.

    // If you forgot how Selection Sort works, review Lab 2 document.

    int i, j;    
    int minIndex;
    
    for(i = 0; i < size; i++)
    {
        minIndex = i;

        // Find minimum element in remaining unsorted array
        for(j = i + 1; j < size; j++)
        {
            // Fixed Bug 1: Using words[minIndex] for correct minimum element comparison
            if(my_strcmpOrder(words[minIndex], words[j]) == 1)
            {
                minIndex = j;
            }                        
        }
       
        // Fixed Bug 2: Compare with i instead of j for correct swap condition
        if(minIndex != i)
        {
            swap(&words[i], &words[minIndex]);
        }
    }
}

