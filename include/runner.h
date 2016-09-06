#ifndef RUNNER_H
#define RUNNER_H

typedef struct arrestRecord{
	char lastName[50];
	char firstName[50];
	char middleName[50];
	int age;
	char arrestDate[12];
	char law[15];
	char lawDesc[256];
	char address[512];
}record;

#endif
