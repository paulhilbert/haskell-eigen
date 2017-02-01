#include <string.h>
#include <stdio.h>
#include <complex>
#include <memory>


#define EIGEN_MPL2_ONLY
#define EIGEN2_SUPPORT
#define EIGEN_NO_EIGEN2_DEPRECATED_WARNING
#define EIGEN_INITIALIZE_MATRICES_BY_ZERO

#define GUARD_START try { do {
#define GUARD_END } while(false); return 0; } catch (const std::exception& ex) { return strdup(ex.what()); }

#define RET const char*

#define API(name,args,call) \
extern "C" RET eigen_##name args {\
	GUARD_START\
	switch (code) {\
		case 0: return name<T0>call;\
		case 1: return name<T1>call;\
		case 2: return name<T2>call;\
		case 3: return name<T3>call;\
	}\
	GUARD_END\
}

typedef float T0;
typedef double T1;
typedef std::complex<float> T2;
typedef std::complex<double> T3;
