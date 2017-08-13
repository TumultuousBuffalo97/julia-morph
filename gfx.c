struct window {
	struct RGBpixel *surface;
	int xres,yres;
	FLOAT_TYPE xmin,xmax,ymin,ymax;
};
struct window *window_init_size(int xres, int yres, FLOAT_TYPE cx, FLOAT_TYPE cy, FLOAT_TYPE size) {
	struct window *wind=calloc(1,sizeof(struct window));
	wind->surface=calloc(xres*yres,sizeof(struct RGBpixel));
	wind->xres=xres;
	wind->yres=yres;
	wind->xmin=cx-size*((FLOAT_TYPE)xres/(FLOAT_TYPE)yres);
	wind->xmax=cx+size*((FLOAT_TYPE)xres/(FLOAT_TYPE)yres);
	wind->ymin=cy-size;
	wind->ymax=cy+size;
	return wind;
}
void window_free(struct window *wind) {
	free(wind->surface);
	free(wind);
}
FLOAT_TYPE window_pixel_to_cart_x(struct window *wind, int x) {
	FLOAT_TYPE dist=wind->xmax-wind->xmin;
	FLOAT_TYPE dxdp=dist/wind->xres;
	FLOAT_TYPE cx=wind->xmax+wind->xmin;
	return (FLOAT_TYPE)x*dxdp+cx-wind->xmax;
}
FLOAT_TYPE window_pixel_to_cart_y(struct window *wind, int y) {
	FLOAT_TYPE dist=wind->ymax-wind->ymin;
	FLOAT_TYPE dydp=dist/wind->yres;
	FLOAT_TYPE cy=wind->ymax-wind->ymin;
	return (FLOAT_TYPE)y*dydp-cy-wind->ymin;
}
void window_setpixel(struct window *wind, int x, int y, struct RGBpixel pix) {
	wind->surface[y*wind->xres+x]=pix;
}
void window_setpixel_RGB(struct window *wind, int x, int y, unsigned char r, unsigned char g, unsigned char b) {
	struct RGBpixel *pix=&wind->surface[y*wind->xres+x];
	pix->red=r;
	pix->green=g;
	pix->blue=b;
}
