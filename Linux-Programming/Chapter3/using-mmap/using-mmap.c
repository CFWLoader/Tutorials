#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct{
	int integer;
	char string[24];
}Record;

#define NRECORDS (100)

int main(){

	Record record, *mapped;
	int i, f;
	FILE *fp;

	fp = fopen("records.dat","w+");
	for(i = 0; i < NRECORDS; ++i){
		record.integer = i;
		sprintf(record.string, "RECORD-%d", i);
		fwrite(&record, sizeof(record), 1, fp);
	}

	fclose(fp);

	fp = fopen("records.dat", "r+");
	fseek(fp, 43 * sizeof(record), SEEK_SET);		//Find the 43th block.
	fread(&record, sizeof(record), 1, fp);

	record.integer = 143;					//Modify the record to 143
	sprintf(record.string, "RECORD-%d", record.integer);

	fseek(fp, 43 * sizeof(record), SEEK_SET);
	fwrite(&record, sizeof(record), 1, fp);
	fclose(fp);

	f = open("records.dat", O_RDWR);

	mapped = (Record*) mmap(0, NRECORDS * sizeof(record), PROT_READ|PROT_WRITE, MAP_SHARED, f, 0);

	mapped[43].integer = 243;

	sprintf(mapped[43].string, "RECORD-%d", mapped[43].integer);

	msync((void*) mapped, NRECORDS * sizeof(record), MS_ASYNC);
	munmap((void*) mapped, NRECORDS * sizeof(record));

	close(f);

	exit(0);

}
