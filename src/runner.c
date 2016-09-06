#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "runner.h"
#include "download.h"

void wait(unsigned int sec);
char *replace(char *s, char old, char new);
void replace_multi_space_with_single_space(char *str);
char *trimwhitespace(char *str);
void getOList(char *fileName, char oList[5000][60]);

int main()
{
	char line[2056];
	char *newFile = downloadArrests();
	
	FILE *openedFile;
	printf("Attempting to open %s\n",newFile);
	openedFile = fopen(newFile,"r");
	if (openedFile == NULL)
	{
		printf("FILE NOT OPENED\n");
		exit(1);
	}
	char oList[5000][60]={0};
	getOList("oList.txt",oList);

	while(fgets(line, 2057, openedFile) != NULL)
	{
		replace_multi_space_with_single_space(line);
		strcpy(line,replace(line,'\t',' '));
		strcpy(line,trimwhitespace(line));
	
		int numberOfOff = strlen(oList);
		int i;
		char *sub = NULL;
		for(i=0; i<numberOfOff -1; i++)
		{
			sub = strstr(line,oList[i]);
			if(sub!=NULL)
			{
				printf("FOUND\n");
				break;
			}
		}
		if(sub==NULL)
		{
			printf("NOT FOUND\n");
		}	
		printf("%s\n", line);
		wait(1);
	}
}

char *replace(char *s, char old, char new)
{
	char *p = s;

	while(*p)
	{	
		if(*p == old)
		{
			*p = new;
		}
	
		++p;
	}
	return s;
}
void wait(unsigned int sec)
{
	unsigned int playTime = time(0)+sec;
	while ((unsigned int)time(0) < playTime);
}



void replace_multi_space_with_single_space(char *str)
{
	char *dest = str;
	while (*str != '\0')
	{
		while (*str == ' ' && *(str + 1) == ' ')
		{
			str++;
		}
		*dest++ = *str++;
	}

	*dest = '\0';
}

char *trimwhitespace(char *str)
{
	char *end;
	while(isspace(*str)) str++;

	if(*str == 0)
	{
		return str;
	}
	end = str + strlen(str) - 1;
	while(end > str && isspace(*end)) end--;

	*(end+1) = 0;
	return str;
}

void getOList(char *fileName, char oList[5000][60])
{
	char filePath [500]={0};
	strcat(filePath, "../resources/");
	strcat(filePath,fileName);
	FILE *oListF;
	oListF = fopen(filePath,"r");
	if(oListF == NULL)
	{
		printf("oList couldnt be opened\n");
		exit(1);
	}
	char line[60]={0};
	int i =0;
	while(fgets(line, 59, oListF) != NULL)
	{
		strcpy(oList[1], line);
		i++;
	}
	fclose(oListF);
}
