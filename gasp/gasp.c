#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAXLINE 500   // maximum line size
#define MAXPATTERN 100  // maximum pattern size

/*Rogers Xiang
  April 23, 2018

  The command
     $ ./gasp [options] STRING FILE...
  should read the listed files (FILE...) and copy each line
  from the input to stdout if it contains STRING anywhere.
  Each output line is preceded by the name of the file it is in. 

  Options (does not handle multi-character combinations)
  -i: Ignore case when searching for lines that contain STRING
  -n: Number lines in output
*/

/* Global variables (for command line options) */
int ignoreCase;  // for -i option (0 = false, 1 = true)
int numberLines;  // for -n option (0 = false, 1 = true)

/* Function declarations */
int checkflags(int argc, char *argv[]);
void parsefile(FILE *file, char *match, char *filename);
char* lowercase(char *str);

/*The main function handles error checking and parses the command line arguments.
  argc: number of arguments (program name counts as first argument)
  argv: vector of arguments
*/
int main(int argc, char *argv[]) {
  FILE *fp;  // file pointer
  char match[MAXPATTERN];  // to store STRING
  ignoreCase = 0;
  numberLines = 0;
  int i;  // argv index of STRING

  if (argc < 3) {
    fprintf(stderr, "gasp: need at least two arguments\n");
    return EXIT_FAILURE;
  }
  if ((i = checkflags(argc, argv)) == -1) {
    fprintf(stderr, "gasp: invalid argument(s)\n");
    return EXIT_FAILURE;
  }
  if (ignoreCase == 1) {
    strncpy(match, lowercase(argv[i]), MAXPATTERN);
  } else {
    strncpy(match, argv[i], MAXPATTERN);
  }
  for (i+=1; i < argc; ++i) {
    fp = fopen(argv[i], "r");
    if (fp == NULL) {
      fprintf(stderr, "gasp: unable to open %s\n", argv[i]);
    } else {
      parsefile(fp, match, argv[i]);
      fclose(fp);  // frees the file pointer
    }
  }
  return EXIT_SUCCESS;
}

/*Returns the argv index of the first non-flag argument.
  Also sets ignoreCase and/or numberLines to 1 depending on arguments.
  argc: argv index to stop at
  argv: vector of arguments to program
*/
int checkflags(int argc, char *argv[]) {
  int i;
  for (i = 1; i < argc; ++i) {
    if (strncmp(argv[i], "-i", 3) == 0) {
       ignoreCase = 1;
    } else if (strncmp(argv[i], "-n", 3) == 0) {
       numberLines = 1;
    } else return (i == (argc - 1)) ? -1 : i;  // invalid number of arguments
  }
  return -1;  // we may assume options won't occur more than once
}

/*Reads the file and prints matching lines to stdout.
  file: pointer to file
  match: STRING to search for
  filename: name of file
*/
void parsefile(FILE *file, char *match, char *filename) {
  char line[MAXLINE];  // to store the orignal line
  char copy[MAXLINE];  // to store copy of line (if necessary)
  char *compare;  // pointer to line used for comparison
  int i = 0;  // line number

  compare = (ignoreCase == 1) ? copy : line;
  
  while (fgets(line, MAXLINE, file) != NULL) {
    ++i;
    if (ignoreCase == 1) {
      strncpy(copy, line, MAXLINE);
      lowercase(copy);
    }
    if (strstr(compare, match) != NULL) {
      printf("%s", filename);
      if (numberLines == 1) {
        printf("(%d)", i);
      }
      printf(":");
      fputs(line, stdout);
    }
  }
}

/*Modifies the string by converting it to lowercase, and returns the result.
  str: string to convert
*/
char* lowercase(char *str) {
  int length = strlen(str);
  int i;
  for (i = 0; i < length; ++i) {
    str[i] = tolower(str[i]);
  }
  return str;
}
