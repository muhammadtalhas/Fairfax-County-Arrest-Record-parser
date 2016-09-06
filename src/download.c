#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>


char *downloadArrests()
{
	long int now = (long int)time(NULL);
	char path[80]={0};
	char epoch[12]={0};
	char fileName[30]={0};
	sprintf(epoch, "%d", now);
	
	strcat(fileName, epoch);
	strcat(fileName, "-arrests.txt");
	
	strcat(path,"curl -o ../resources/");
	strcat(path,fileName);
	strcat(path, " http://www.fairfaxcounty.gov/police/crime/arrest.txt");
	
	printf("Executing command %s\n", path);
	system(path);

	static char returnFile[50]={0};
	strcat(returnFile, "../resources/");
	strcat(returnFile, fileName);	
	
	printf("Returning %s\n",returnFile);
	return returnFile;

}


