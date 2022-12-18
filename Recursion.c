#include <stdio.h>



void tower (int n, char source, char temp, char destination) {
	if(n==1) {
         printf("MOVE DISK 1 FROM %d TO %d ",source ,destination);
	     return;
	}

	/*moving n-1 disks from A to B using C as auxiliary*/
	tower(n-1, source, destination, temp);
    printf("MOVE DISK %d FROM %d TO %d ",n,source ,destination);
	/*moving n-1 disks from B to C using A as auxiliary*/
	tower(n-1, temp, source, destination);
}


