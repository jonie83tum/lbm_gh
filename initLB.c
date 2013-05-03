#include "initLB.h"

int readParameters(int *xlength, double *tau, double *velocityWall,
		int *timesteps, int *timestepsPerPlotting, int argc, char *argv[]) {

	const char *szFileName;
	/* Check if there is only one command line argument */
	if (argc != 2) {
		printf("One command line argument = file name of initialization\n");
		return -1;
	}

	szFileName = argv[1];
	read_int(szFileName, "xlength", xlength);
	read_double(szFileName, "tau", tau);
	read_double(szFileName, "velocityWall", velocityWall);
	read_int(szFileName, "timesteps", timesteps);
	read_int(szFileName, "timestepsPerPlotting", timestepsPerPlotting);

	return 0;
}

void initialiseFields(double *collideField, double *streamField, int *flagField,
		int xlength) {
	/* TODO */
}

