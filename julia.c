#include <stdio.h>
#include <pthread.h>
#include "cmplx.c"
#include "png_helper.c"
#include "color.c"
#include "gfx.c"
#include "fractal.c"
int main(int argc, char *argv[]) {
	int i;
	struct window *wind;
	if(argc==1) {
		printf("arguments: xres yres size iterations x y filename\n");
		return 0;
	}
	int xres,yres,its;
	FLOAT_TYPE size,x,y;
	xres=atoi(argv[1]);
	yres=atoi(argv[2]);
	its=atoi(argv[3]);
	size=atof(argv[4]);
	x=atof(argv[5]);
	y=atof(argv[6]);
	wind=window_init_size(xres,yres,0,0,size);
	fract_julia_image_single(its,cmplx_init(x,y),wind);
	writePNGimage(argv[7],NULL,wind->surface,wind->xres,wind->yres);
	return 0;
}
