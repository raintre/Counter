#include <stdio.h>

int NumberOfChars(char *s[], int n);
int NumberOfWords(char *s[], int n);
int NumberOfLines(char *s[], int n);
int NumberOfMatch(char *s[], int n, char m);

int main(void) {
    int i;
    int num_lines;
    char match;

    /* Initialize an array of pointers * lines []
    with "start address" of character string of each line of the lyrics. */
    char *lines[] = {
        "example1",
        "example2",
        "..."
    };

    /* Count lines of lyrics (including blank lines) and output. */
    num_lines = sizeof(lines) / sizeof(char *);
    printf("Number of lines: %d\n\n", num_lines);

    /* Output lyrics */
    printf("--------------------------------\n");
    for (i=0; i < num_lines; i++) {
        printf("%s\n", lines[i]);
    }
    printf("--------------------------------\n");
    printf("\n");

    /* Count the number of characters of lyrics and output. */
    printf("Number of characters: %d\n", NumberOfChars(lines, num_lines) );

    /* Count the number of words of lyrics and output. */
    printf("Number of words: %d\n", NumberOfWords(lines, num_lines) );

    /* Count the number of lines of lyrics and output. */
    printf("Number of lines: %d\n", NumberOfLines(lines, num_lines) );

    /* Read one character from the keyboard,
    count the number of characters in the matching lyrics, and output it. */
    printf("Please type in one letter.\n");
    fflush(0);
    scanf("%c",&match);
    printf("Number of %c: %d\n",match, NumberOfMatch(lines, num_lines, match) );

    return 0;
}

/* ----------------------------------------------------------------------------
   Functions for counting characters

(in)                     s []: Pointer to the character string of each line of the lyric
                                   (pointing to the head address of each line)
Number of elements of n: s []

(out)                     num: Number of characters (excluding white space)
 ---------------------------------------------------------------------------- */
int NumberOfChars(char *s[], int n) {
    int i, j, num = 0;

    /* Check line by line (i corresponds to line number). */
    for (i=0; i<n; i++) {
        j = 0;
        /* Repeat until NULL character (end of line) appears.
        (j represents the number of characters from the beginning of the line) */
        while (s[i][j] != '\0') {
            if (s[i][j] != ' ') num ++; /* Count nonblank characters. */
            j++;
            /* Advance a character by one character. */
        }
    }

    /* Returns the number of characters as an integer return value. */
    return num;
}

/* ----------------------------------------------------------------------------
   Function to count word count
 ---------------------------------------------------------------------------- */
int NumberOfWords(char *s[], int n) {
    int i, j, num = 0, voi = 0;

    /* Check line by line (i corresponds to line number). */
    for (i=0; i<n; i++) {
        j = 0;
        /* Repeat until NULL character (end of line) appears.
          (j represents the number of characters from the beginning of the line) */
        while (s[i][j] != '\0') {
            /*Count words with whitespace behind words.*/
            if (s[i][j] == ' '){
                num++;
                j++;
            }else{
                j++;
            }
        }
        /*\ 0 counts the words at the end of the line,
        except that the blank line is subtracted from voi later.*/
        if (s[i][j] == '\0'){
            if (s[i][0] == '\0'){
                voi++;
                num++;
            } else {
                num++;
            }
        }
    }
    /*Draw empty lines from num.*/
    num = num - voi;

    return num;
}

/* ----------------------------------------------------------------------------
   Function to count the number of rows (excluding blank lines)
 ---------------------------------------------------------------------------- */
int NumberOfLines(char *s[], int n) {
    int i, j, num, voi = 0;

    /* Check line by line (i corresponds to line number).*/
    /*Counts the total number of empty lines
         depending on whether or not
         the first character of the line is at the end of the line (\ 0).*/
    for (i=0; i<n; i++) {
        j = 0;
        if (s[i][j] == '\0') {
            voi++;
        } else {
            j++;
        }
    }
    
    /*Subtract the total number of blank lines
     from the total number of lines including blank lines.*/
    num = n - voi;

    /* Returns the number of rows as an integer return value. */
    return num;
}

/* ----------------------------------------------------------------------------
   Function to count the number of characters matching the character m
 ---------------------------------------------------------------------------- */
int NumberOfMatch(char *s[], int n, char m) {
    int i, j, num = 0;

    /* Check line by line (i corresponds to line number). */
    for (i=0; i<n; i++) {
        j = 0;
        /* Repeat until NULL character (end of line) appears
         (j represents the number of characters from the beginning of the line). */
        while (s[i][j] != '\0') {
            if (s[i][j] == m) {
                num ++; /* Count the number of characters matching m. */
                j++;
                /* Advance a character by one character. */
            } else {
                j++;
            }
        }
    }

    /* Returns the number of characters as an integer return value. */
    return num;
}
