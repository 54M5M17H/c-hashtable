#include <stdio.h>
#include <time.h>
#include "hashtable.h"

int main () {

	struct timespec time1, time2;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);
	
	HashMap* hash = createHash(INIT_SIZE, 1);
	hash = set(hash, "Sam", "Alexander");
	hash = set(hash, "Joe", "William");
	hash = set(hash, "Elliott", "James");
	hash = set(hash, "David", "John");
	hash = set(hash, "Reggie", "Craig");
	hash = set(hash, "Colin", "Keith");
	hash = set(hash, "Anna", "Stephanie");
	hash = set(hash, "Matt", "Cyl");
	hash = set(hash, "Sue", "Careless");
	hash = set(hash, "Alison", "Crisp");
	hash = set(hash, "Arian", "Daniel");
	hash = set(hash, "Adam", "Welham");
	hash = set(hash, "Toby", "Charter");
	hash = set(hash, "Andrew", "Baldwin");
	hash = set(hash, "James", "Cantwell");
	hash = set(hash, "Steven", "Knott");
	hash = set(hash, "Harry", "Worboys");
	hash = set(hash, "Katie", "Bowler");
	hash = set(hash, "Nisha", "Gogna");

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
	char* res11 = get(hash, "Arian");
	char* res12 = get(hash, "Adam");
	char* res13 = get(hash, "Toby");
	char* res14 = get(hash, "Andrew");
	char* res15 = get(hash, "James");
	char* res16 = get(hash, "Steven");
	char* res17 = get(hash, "Harry");
	char* res18 = get(hash, "Katie");
	char* res19 = get(hash, "Nisha");

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
	
	printf("Arian: %s \n", res11);
	printf("Adam: %s \n", res12);
	printf("Toby: %s \n", res13);
	printf("Andrew: %s \n", res14); 
	printf("James: %s \n", res15); 
	printf("Steven: %s \n", res16); 
	printf("Harry: %s \n", res17); 
	printf("Katie: %s \n", res18); 
	printf("Nisha: %s \n", res19);

	// test delete
	deleteKey(hash, "Sam");
	char* shouldBeNull = get(hash, "Sam");
	printf("Sam's middlename should now be NULL >> %s \n", shouldBeNull);

	// free hash to clear up
	freeHash(hash);
}
