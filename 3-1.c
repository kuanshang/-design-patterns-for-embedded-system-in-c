#include<stdlib.h>
#include<stdio.h>

#define TURN_OFF (0x00)
#define INITIALIZE (0x61)
#define RUN (0x69)
#define CHECK_ERROR (0x02)
#define DEVICE_ADDRESS (0x1FFAFD0)

void emergencyShutDown(void) {
	printf("OMG we're all gone die!\n");
}

int main() {
	unsigned char* pDevice;

	//pDevice = (unsigned char*) DEVICE_ADDRESS;
	pDevice = malloc(1);

	*pDevice = 0xFF;
	printf("Device bits %X \n", *pDevice);

	*pDevice &= INITIALIZE;
	printf("Device bits %X \n", *pDevice);

	if( *pDevice & CHECK_ERROR ) {
		emergencyShutDown();
		//abort();
		return 0;
	} else {
		*pDevice &= RUN;
		printf("Device bits %X \n", *pDevice);
	}
	
	free(pDevice);

	return 0;
}
