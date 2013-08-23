
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>

/* constants */
static const long def_log2_busy_loop_iter		= 18;
static const int def_usleep_val				= 2;
static const char *cmd_name = "spinner";

/* other globals */
static bool verbose = false;

/** Spin cpu, doing some stuff, 'iter' times, then usleep(usleep_val). */
static int spin(const long log2_iter, const int usleep_val)
{
	unsigned long i;
	if (verbose)
		printf("%s: l2_iter %ld, usec %d.\n", __func__, log2_iter,
			usleep_val);

	/* Code does nothing useful except trick gcc to not optimize it out. */
	for (i = 0; ; i++) {
		if ((i & 0x111) == i)
			i++;
		if ((i & ((1<<log2_iter)-1)) == 0) 
			usleep(usleep_val);
	}
	return EXIT_SUCCESS;
}

static void usage(void)
{
	printf("Usage: %s [-h] [-v] [-i log2_iterations] [-s usleep-val]\n",
		cmd_name);
	exit(EXIT_FAILURE);
}

/**
 * Like atoi(), but checks for, you know, errors.
 * @param out_val	if success, returns value here.
 * @param str		string to parse
 * @return 		zero on success.
 */
static int atol_only_cooler(const char *str, long *out_val)
{
	long val;
	char *bad_charp;
	val = strtol(str, &bad_charp, 10);
	if (*bad_charp == '\0') {
		*out_val = val;
		return 0;
	} else {
		return EINVAL;
	}
}

int main(int argc, char *argv[])
{
	int opt, error = 0;
	long iter = def_log2_busy_loop_iter, usec = def_usleep_val;
	while ((opt = getopt(argc, argv, "hi:s:v")) != -1) {
		switch (opt) {
		case 'i':
			error = atol_only_cooler(optarg, &iter);
			if (error)
				usage();
			break;
		case 's':
			error = atol_only_cooler(optarg, &usec);
			if (error)
				usage();
			break;
		case 'v':
			verbose = true;
			break;
		default: 
			usage();
		}
	}

	spin(iter, usec);
	return EXIT_SUCCESS;
}
