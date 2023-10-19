//pipe1.cpp
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argv, char *argc[]){
	// Parse commands and store them in a string
	char cmd[60];
	strcat(cmd, argc[1]);
	strcat(cmd, " ");
	strcat(cmd, argc[2]);

	FILE *fpi; //for reading a pipe

	char buffer[BUFSIZ+1]; //BUFSIZ defined in <stdio.h>

	int chars_read;
	memset (buffer, 0,sizeof(buffer)); //clear buffer
	fpi = popen (cmd, "r"); //pipe to command "ps -auxw"
	if (fpi != NULL) {
		//read data from pipe into buffer
		chars_read = fread(buffer, sizeof(char), BUFSIZ, fpi);
		if (chars_read > 0){
			cout << "Output from pipe: " << buffer << endl;
		}
		pclose (fpi); //close the pipe
		return 0;
	}
	return 1;
}
