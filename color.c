//depends on RGBpixel from png_helper.c
//and FLOAT_TYPE being defined as either float or double
#define PI 3.1415926535898
struct RGBpixel color_HSV_to_RGB255(FLOAT_TYPE h, FLOAT_TYPE s, FLOAT_TYPE v) {
	struct RGBpixel rgb;
	int i;
	FLOAT_TYPE chroma;
	FLOAT_TYPE hprime;
	FLOAT_TYPE x;
	FLOAT_TYPE rgbprime[3];
	FLOAT_TYPE m;
	int thing;
	h*=(PI/180.0)*360.0;
	chroma=s*v;
	hprime=h/(60.0*(PI/180.0));
	x=chroma*(1.0-(double)fabs(fmod(hprime,2)-1.0));
	m=v-chroma;
	switch((int)hprime) {
		case 0:
			rgbprime[0]=chroma;
			rgbprime[1]=x;
			rgbprime[2]=0;
		break;
		case 1:
			rgbprime[0]=x;
			rgbprime[1]=chroma;
			rgbprime[2]=0;
		break;
		case 2:
			rgbprime[0]=0;
			rgbprime[1]=chroma;
			rgbprime[2]=x;
		break;
		case 3:
			rgbprime[0]=0;
			rgbprime[1]=x;
			rgbprime[2]=chroma;
		break;
		case 4:
			rgbprime[0]=x;
			rgbprime[1]=0;
			rgbprime[2]=chroma;
		break;
		case 5:
			rgbprime[0]=chroma;
			rgbprime[1]=0;
			rgbprime[2]=x;
		break;
		default:
			rgbprime[0]=0;
			rgbprime[1]=0;
			rgbprime[2]=0;
		break;
	}
	rgb.red=(int)(255*rgbprime[0]+m);
	rgb.green=(int)(255*rgbprime[1]+m);
	rgb.blue=(int)(255*rgbprime[2]+m);
	return rgb;
}
