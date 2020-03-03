/* localtime example */
#include <stdio.h>
#include <time.h>
#include <string.h>

# define INFINITY_POSITIVE_RAW (0x7ff0000000000000)

typedef struct		s_double3
{
	double 			x;
	double 			y;
	double 			z;
}					t_double3;

char	is_inf(double d)
{
	unsigned long long ull;

	ull = INFINITY_POSITIVE_RAW;
	if (memcmp(&d, &ull, sizeof(double)) != 0)
		return (0);
	return (1);
}

#define inf 1.0/0.0
#define d3_inf (t_double3){1.0 / 0.0, 1.0 / 0.0, 1.0 / 0.0}

int main()
{
#ifdef NAN
	printf("SUPPORTED\n");
#endif
#ifdef INFINITY
	printf("SUPPORTED INF\n");
#endif

	clock_t t1, t2;
	t1 = clock();
	int i;
	for(i = 0; i < 1000000; i++)
	{
		int x = 90;
	}

	t2 = clock();

	float diff = ((float)(t2 - t1) / 1000000.0F ) * 1000;
	printf("%f\n",diff);
	printf("int : %lu\n", sizeof(int));
	printf("%f\n", 1.0 / 0.0);

//	t_double3 inf_test = d3_inf;
//	if (inf_test == d3_inf)
//	{
//		printf("SUPPORTED D3\n");
//	}

	double a = inf;
	if (a == inf)
	{
		printf("SUPPORTED\n");
	}

	double f = 1.0 / 0.0;
	unsigned long long nn = 0x7ff0000000000000;
	unsigned long long fn; memcpy(&fn, &f, sizeof f);
	memcpy(&f, &nn, sizeof nn);
	printf("INFINITY:   %f %d\n", f, is_inf(f));
	printf("sizeof:   %lu\n", sizeof(double));

	return 0;
}

//int main ()
//{
//	time_t rawtime;
//	struct tm * timeinfo;
//
//	time ( &rawtime );
//	timeinfo = localtime ( &rawtime );
//	printf ( "Current local time and date: %s", asctime (timeinfo) );
//
//	return 0;
//}
