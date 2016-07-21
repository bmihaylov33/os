#include <stdio.h>

int main(int argc, char** argv)
{
    if (argc < 4) return -1; /* quit if argument list not there */

    FILE* fp = fopen(argv[3], "r+"); /* open the file for reading and updating */

    if (fp == NULL) return -1; /* if file not found quit */

    char current_char = 0;
    char to_replace = argv[1][0]; /* get the character to be replaced */
    char replacement = argv[2][0]; /* get the replacing character */

    while ((current_char  = fgetc(fp)) != EOF) /* while it's not the end-of-file */
    {                                              /*   read a character at a time */

        if (current_char == to_replace) /* if we've found our character */
        {
            fseek(fp, ftell(fp) - 1, SEEK_SET); /* set the position of the stream
                                                           one character back, this is done by
                                                           getting the current position using     
                                                           ftell, subtracting one from it and 
                                                           using fseek to set a new position */

            fprintf(fp, "%c", replacement); /* write the new character at the new position */
        }
    }

    fclose(fp); /* it's important to close the file_handle 
                       when you're done with it to avoid memory leaks */

    return 0;
}