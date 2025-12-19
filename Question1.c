#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"


int my_strlen(const char * const str1)
{
	// Returns the length of the string - the number of characters, but IGNORING the terminating NULL character
	int count = 0;
	while (1) {
		if (str1[count] == '\0') {
			return count;
		}
		count++;
	}
}

int my_strcmp(const char * const str1, const char * const str2)
{
	// Return 0 if the two strings are not identical.  Return 1 otherwise.
	
	// Criteria 1: Check their lenghts.  If not the same length, not equal
	int length1 = my_strlen(str1);
	int length2 = my_strlen(str2);
	int idx;
	
	if (length1 != length2) 
		return 0;

	// Criteria 2: Check their contents char-by-char.  If mismatch found, not equal
	idx = 0;
	while(idx < length1) {
		if(str1[idx] != str2[idx])
			return 0;
		idx++;
	}

	// if passing the two criteria, strings equal
	return 1;
}


int my_strcmpOrder(const char * const str1, const char * const str2)
{
	/*compare_str alphabetically compares two strings.
    	If str2 is alphabetically smaller than str1 (comes before str1),
    	the function returns a 1, else if str1 is smaller than str2, the
    	function returns a 0.*/

	// if two strings are completely identical in order, return -1.

	// We are NOT looking for any custom alphabetical order - just use the integer values of ASCII character
	int i = 0;
	
	// Compare characters until we find a difference or reach the end of either string
	while (str1[i] != '\0' && str2[i] != '\0') {
		if (str1[i] > str2[i]) return 1;      // str1 is larger
		if (str1[i] < str2[i]) return 0;      // str2 is larger
		i++;
	}
	
	// If we get here, one string might be longer than the other, or they're identical
	if (str1[i] == '\0' && str2[i] == '\0') return -1;  // identical strings
	if (str1[i] == '\0') return 0;  // str1 is shorter (smaller)
	return 1;  // str2 is shorter (smaller)
}


char *my_strcat(const char * const str1, const char * const str2){

	/* this is the pointer holding the string to return */
	char *newStr = NULL;
	
	/*write your implementation here*/
	int len1 = my_strlen(str1);
	int len2 = my_strlen(str2);
	int i;
	
	// Allocate memory for combined string plus null terminator
	newStr = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if(!newStr) return NULL;
	
	// Copy first string
	for(i = 0; i < len1; i++) {
		newStr[i] = str1[i];
	}
	
	// Copy second string
	for(i = 0; i < len2; i++) {
		newStr[len1 + i] = str2[i];
	}
	
	// Add null terminator
	newStr[len1 + len2] = '\0';

	/* finally, return the string*/
	return newStr;

	// IMPORTANT!!  Where did the newly allocated memory being released?
	// THINK ABOUT MEMORY MANAGEMENT
	// Note: The memory will need to be freed by the caller using free()
	// This is because we're returning the pointer to the allocated memory
}