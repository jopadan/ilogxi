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
	quad_t i = strtoq(argv[1], NULL, 10);
	fprintf(stdout, "%lu %lu %ld\n", u, base, i);
	fprintf(stdout, "C/C++ ilog%lui(%ld): %d\n",
	                base,
			i,
	                ilogxid(i,base));
	fprintf(stdout, "C/C++ ilog%luu(%ld): %ld\n",
	                base,
			u,
	                ilogxuq(u,base));
	fprintf(stdout, "C/C++ ilog%luimax(%ld): %ld\n",
	                base,
			u,
	                ilogximax(u,base));
	fprintf(stdout, "C/C++ ilog%luumax(%lu): %lu\n",
	                base,
			u,
	                ilogxumax(u,base));
	#ifdef __cplusplus
	fprintf(stdout, "C++   ilog%lu(%ld): %ld\n",
	                base,
			u,
	                ilogx<intmax_t>(u,base));
	#endif
	exit(EXIT_SUCCESS);
}
