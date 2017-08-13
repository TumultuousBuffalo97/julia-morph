#include <math.h>
#define FLOAT_TYPE double
struct cmplx {
	FLOAT_TYPE real;
	FLOAT_TYPE imag;
};
struct cmplx cmplx_init(FLOAT_TYPE real, FLOAT_TYPE imag) {
	struct cmplx retnum;
	retnum.real=real;
	retnum.imag=imag;
	return retnum;
}
struct cmplx cmplx_mul(struct cmplx num1, struct cmplx num2) {//6 flops
	struct cmplx retnum;
	retnum.real=num1.real*num2.real-num1.imag*num2.imag;
	retnum.imag=num1.real*num2.imag+num1.imag*num2.real;
	return retnum;
}
struct cmplx cmplx_add(struct cmplx num1, struct cmplx num2) {//2 flops
	struct cmplx retnum;
	retnum.real=num1.real+num2.real;
	retnum.imag=num1.imag+num2.imag;
	return retnum;
}
FLOAT_TYPE cmplx_abs(struct cmplx num) {//3 flops, unkown about sqrt function
	return sqrt(num.real*num.real+num.imag*num.imag);
}
