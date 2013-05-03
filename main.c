#ifndef _MAIN_C_
#define _MAIN_C_

#include "collision.h"
#include "streaming.h"
#include "initLB.h"
#include "visualLB.h"
#include "boundary.h"

int main(int argc, char *argv[]) {
	/* TODO */
	int xlength, timesteps, timestepsPerPlotting, returnFlag;
	double tau, velocityWall;
	/* read the parameters */
	returnFlag = readParameters(&xlength, &tau, &velocityWall, &timesteps,
			&timestepsPerPlotting, argc, argv);
	/* return in case of wrong command line arguments */
	if (returnFlag == -1){
		return -1;
	}

	return 0;
}

#endif

