#include <stdio.h>
#include "NYXPNGTools.h"

int main(int argc, char **argv) {
	if (argc < 3) {
		fprintf(stderr, "%s [input.png] [output.png]", argv[0]);
		return -1;
	}
	const char *path = argv[1];
	const char *opath = argv[2];
	int error = 0;
	if (npt_is_apple_crushed_png(path, &error)) {
		unsigned int size = 0;
		/// Uncrush the PNG
		unsigned char* pngData = npt_create_uncrushed_from_file(path, &size, &error);
		if (!pngData) {
			fprintf(stderr, "Failed to create uncrushed png from '%s', %s\n", path, npt_error_message(error));
		} else {
			//printf("pngData == %d\n", size);
			FILE *fp = fopen(opath, "wb+");
			if (fp != NULL) {
				fwrite(pngData, 1, size, fp);
				fflush(fp);
				fclose(fp);
			} else {
				fprintf(stderr, "Failed to create out.png\n");
			}
		}
	}
	return 0;
}
