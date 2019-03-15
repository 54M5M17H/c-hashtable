#include <stdio.h>
#include <time.h>
#include "hashtable.h"

int main () {

	struct timespec time1, time2;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);
	
	HashMap* hash = createHash(INIT_SIZE);
	set(hash, "Sam", "Alexander");
	set(hash, "Joe", "William");
	set(hash, "Elliott", "James");
	set(hash, "David", "John");
	set(hash, "Reggie", "Craig");
	set(hash, "Colin", "Keith");
	set(hash, "Anna", "Stephanie");
	set(hash, "Matt", "Cyl");
	set(hash, "Sue", "Careless");
	set(hash, "Alison", "Crisp");

	char* res = get(hash, "Sam");
	char* res2 = get(hash, "Elliott");
	char* res3 = get(hash, "Joe");
	char* res4 = get(hash, "David");
	char* res5 = get(hash, "Reggie");
	char* res6 = get(hash, "Colin");
	char* res7 = get(hash, "Anna");
	char* res8 = get(hash, "Matt");
	char* res9 = get(hash, "Sue");
	char* res10 = get(hash, "Alison");

	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
	printf("%.9ld \n", (long)time1.tv_nsec);
	printf("%.9ld \n", (long)time2.tv_nsec);
	printf("%.9ld \n\n", (long)time2.tv_nsec - time1.tv_nsec);

	printf("Sam's middlename is %s \n", res);
	printf("Ell's middlename is %s \n", res2);
	printf("Joe's middlename is %s \n", res3);
	printf("Dave's middlename is %s \n", res4);
	printf("Reg's middlename is %s \n", res5);

	printf("Colin's middlename is %s \n", res6);
	printf("Anna's middlename is %s \n", res7);
	printf("Matt's middlename is %s \n", res8);
	printf("Sue's middlename is %s \n", res9);
	printf("Alison's middlename is %s \n", res10);
}
