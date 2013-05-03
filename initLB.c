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
	int i, x, y, z, index;
	const int Q = 19, x2 = xlength + 2;
	/* allocate memory for the flag field */
	flagField = (int*) malloc(sizeof(int) * Q * pow(xlength + 2, 3));
	/* initialize the flag field */
	for (z = 0; z < xlength + 2; z++) {
		for (y = 0; y < xlength + 2; y++) {
			for (x = 0; x < xlength + 2; x++) {
				for (i = 0; i < Q; i++) {
					index = Q* (z * pow(xlength + 2, 2) + y * (xlength + 2) + x)+ i;
				if (y == x2)		/* MOVING_WALL */
					flagField(index) = 2;
				else if (y == 0 || x == 0 || x == x2 || z == 0 || z == x2) /* NO_SLIP */
					flagField(index) = 1;
				else /* FLUID */
					flagField(index) = 0;
			}
		}
	}
}
}

