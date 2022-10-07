#include <stdlib.h>
#include <stdio.h>
#include "ilogxi.h"

int main(int argc, char** argv)
{
	if(argc < 2)
	{
		fprintf(stderr, "Usage: %s INTEGER [BASE=2]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	u_quad_t base = argc > 2 ? strtouq(argv[2], NULL, 10) : 2;
	u_quad_t u = strtouq(argv[1], NULL, 10);
	int32_t i = atoi(argv[1]);

	fprintf(stdout, "ilog%lui(%d): %d\n",
	                base,
			i,
	                ilogxid(i,base));
	fprintf(stdout, "ilog%luu(%ld): %ld\n",
	                base,
			u,
	                ilogxuq(u,base));
	fprintf(stdout, "ilog%lu(%ld): %ld\n",
	                base,
			u,
	                ilogxi(u,base));
	exit(EXIT_SUCCESS);
}
