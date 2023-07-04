#include  <stdio.h>
#include  <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

/* Splits the string by space and returns the array of tokens
*
*/
char **tokenize(char *line) //this is the code provided to us
{
    //this function takes a string (the line entered by the user) and returns an array of tokens
  char **tokens = (char **)malloc(MAX_NUM_TOKENS * sizeof(char *));
  char *token = (char *)malloc(MAX_TOKEN_SIZE * sizeof(char));
  int i, tokenIndex = 0, tokenNo = 0;

  for(i =0; i < strlen(line); i++){

    char readChar = line[i];

    if (readChar == ' ' || readChar == '\n' || readChar == '\t'){
      token[tokenIndex] = '\0';
      if (tokenIndex != 0){
	tokens[tokenNo] = (char*)malloc(MAX_TOKEN_SIZE*sizeof(char));
	strcpy(tokens[tokenNo++], token);
	tokenIndex = 0; 
      }
    } else {
      token[tokenIndex++] = readChar;
    }
  }
 
  free(token);
  tokens[tokenNo] = NULL ;
  return tokens;
}

int execute(char **tokens) //this is the code i created
{
//execute function takes an array of tokens and executes the command

    // // Built-in commands

    //if (strcmp(tokens[0], "cat") == 0) {//this is for cat command
    //     if (tokens[1] == NULL) {
    //         fprintf(stderr, "cat: expected argument\n");
    //     } else {
    //         int i;
    //         for (i = 1; tokens[i] != NULL; i++) {
    //             FILE *file = fopen(tokens[i], "r");
    //             if (file == NULL) {
    //                 perror("fopen");
    //             } else {
    //                 char buffer[1024];
    //                 while (fgets(buffer, 1024, file) != NULL) {
    //                     printf("%s", buffer);
    //                 }
    //                 fclose(file);
    //             }
    //         }
    //     }
    //     return 0;
    // } else if (strcmp(tokens[0], "wait") == 0) {//this code is for wait command
    // int pid = wait(NULL);
    // printf("Child process with PID %d has terminated.\n", pid);
    // return 0;
    // }else if (strcmp(tokens[0], "echo") == 0) {//this is for echo command
    //     int i;
    //     for (i = 1; tokens[i] != NULL; i++) {
    //         printf("%s ", tokens[i]);
    //     }
    //     printf("\n");
    //     return 0;
    // } else if (strcmp(tokens[0], "sleep") == 0) {//this is for sleep command
    //     int seconds = atoi(tokens[1]);
    //     sleep(seconds);
    //     return 0;
    // }else if (strcmp(tokens[0], "exit") == 0) {//this part c of the worksheet
    //     return 1;
    // }

    // Check if the command should be executed in the background
    int background = 0;
    int last_token_index = 0;
    for (last_token_index = 0; tokens[last_token_index] != NULL; last_token_index++);
    last_token_index--;
    if (strcmp(tokens[last_token_index], "&") == 0) {
        background = 1;
        tokens[last_token_index] = NULL;
    }

    // Non-built-in commands
    pid_t pid = fork();
    int status;

    if (pid == -1) {
        perror("Failed to create child process");
        return 1;
    } else if (pid == 0) {
        // Child process
        if (execvp(tokens[0], tokens) == -1) {
            perror("Failed to execute command");
            exit(1);
        }
    } else {
        // Parent process
        if (!background) {
            if (waitpid(pid, &status, 0) == -1) {
                perror("Failed to wait for child process");
                return 1;
            }
        } else {
            printf("Running %s in the background (PID %d)\n", tokens[0], pid);
        }
    }

    return 0;
}



int main(int argc, char* argv[]) {//the shell implements a few built-in commands (cd, cat, echo, and sleep)
//As well as the ability to execute non-built-in commands.
	char  line[MAX_INPUT_SIZE];            
	char  **tokens;              
	int i;

	while(1) {			
		/* BEGIN: TAKING INPUT */
		bzero(line, sizeof(line));
		printf("$ ");//this code will print $ just like in linux
		scanf("%[^\n]", line);//this will scan the command given by us
		getchar();

		//printf("Command entered: %s (remove this debug output later)\n", line);
		/* END: TAKING INPUT */

		line[strlen(line)] = '\n'; //terminate with new line
		tokens = tokenize(line);

		// Execute the command
    if (strcmp(tokens[0], "exit") == 0) {//this part c of the worksheet
        return 1;
    }
    
    if (strcmp(tokens[0], "cd") == 0) {//this for cd
        if (tokens[1] == NULL) {
            fprintf(stderr, "cd: expected argument to \"cd\"\n");
        } else {
            if (chdir(tokens[1]) != 0) {
                perror("chdir");
            }
        }
        ;
    } else if (execute(tokens) == 1) {
    break;
}// If the first token is neither "exit" nor "cd", the shell will execute the command using the execute function

		// Freeing the allocated memory	
		for(i=0;tokens[i]!=NULL;i++){
			free(tokens[i]);
		}
		free(tokens);
  }
}

