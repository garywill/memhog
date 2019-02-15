#include <sys/mman.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, const char* argv[]) {
	long mbs;
	unsigned char * mem;
    long times;


    /* must be base 10 */
    mbs = strtol(argv[1], NULL, 10);
    times = strtol(argv[2], NULL, 10);

    for (int t = 0; t < times; ++t)
    {
        printf("%d Attempting to hog %li MB of RAM.\n", t, mbs);
        mem = (unsigned char *)malloc(mbs * 1024 * 1024);
        if (!mem) {
            printf("Couldn't malloc.\n");
            //return 1;
        }
        for (int i = 0; i < mbs * 1024 * 1024; ++i)
        {
            *mem = (unsigned char)rand();
            mem++;
        }
        printf("Finished writing random bytes to allocated memory.\n");
    }
	
	/*
	if (mlock(mem, mbs)) {
		printf("Failed! Couldn't mlock.\n");
		//return 1;
	}
	*/
	printf("Success! Press any key to kill me and get back the RAM.\n");
	getchar();
	return 0;
}
