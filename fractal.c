/* requires 'cmplx.c' */
/* FLOAT_TYPE is defined there */
struct cmplx fract_zsquaredplusc(struct cmplx z,struct cmplx c) {//fractal equation
	return cmplx_add(cmplx_mul(z,z),c);
}
FLOAT_TYPE fract_julia_isinset(int iterations, struct cmplx z, struct cmplx c) {
	int i;
	double modval=1;
	for(i=0;i<iterations;++i) {
		z=fract_zsquaredplusc(z,c);//8 flops
		if(cmplx_abs(z)>=2) {//3? flops
			//return (FLOAT_TYPE)i/(FLOAT_TYPE)iterations;//if the number is not in the set, return the ratio of completed iterations
			return modf((FLOAT_TYPE)i/7.0,&modval);//if the number is not in the set, return the ratio of completed iterations
		}
	}
	return -1;//if the number is in the set, return -1
}
void fract_julia_image_single(int iterations, struct cmplx z, struct window *wind) {
	int x, y;
	FLOAT_TYPE inset;
	for(y=0;y<wind->yres;++y) {
		//printf("%f%%\n",100.0*((float)y/(float)wind->yres));
		for(x=0;x<wind->xres;++x) {
			inset=fract_julia_isinset(\
				iterations,\
				cmplx_init(\
					window_pixel_to_cart_x(wind,x),\
					window_pixel_to_cart_y(wind,y)
				),\
				z\
			);
			if(inset==-1) {
				window_setpixel(wind,x,y,\
					color_HSV_to_RGB255(0,0,0)
				);
			}
			else {
				window_setpixel(wind,x,y,\
					color_HSV_to_RGB255(inset,1,1)
				);
			}
		}
	}
}
