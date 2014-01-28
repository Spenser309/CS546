dnl Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT(cs546, 0.0.1)

AC_CANONICAL_SYSTEM
AM_INIT_AUTOMAKE()

AC_PROG_CC
AC_PROG_CXX
AC_PROG_LIBTOOL
AM_PROG_CC_C_O
AC_CONFIG_MACRO_DIR([m4])

# Checks for libraries.
AC_CHECK_LIB([m], [pow])

# Checks for header files.
AC_CHECK_HEADERS([limits.h stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

#find out what version we are running
ARCH=`uname -m`
if [[ $ARCH == "x86_64" ]];
then
  SUFFIX="64"
else
  SUFFIX=""
fi

# Setup CUDA paths
# ------------------------------------------------------------------------------
AC_ARG_WITH([cuda],
   [  --with-cuda=PATH  		    prefix where cuda is installed [default=auto]])
if test -n "$with_cuda"
then
   CUDA_CFLAGS="-I$with_cuda/include"
   CUDA_LIBS="-L$with_cuda/lib$SUFFIX"
   CUDA_LDFLAGS="-L$with_cuda/lib$SUFFIX"
   NVCC="$with_cuda/bin/nvcc"
else
   CUDA_CFLAGS="-I/usr/local/cuda/include"
   CUDA_LIBS="-L/usr/local/cuda/lib$SUFFIX"
   CUDA_LDFLAGS="-L/usr/local/cuda/lib$SUFFIX"
   NVCC="nvcc"
fi
AC_ARG_ENABLE([debug],
              [--enable-debug               enable nVidia CUDA debug mode [default=no]],
              [NVCCFLAGS="-G -g"],
              [NVCCFLAGS=""]
              )
AC_SUBST(CUDA_CFLAGS)
AC_SUBST(CUDA_LIBS)
AC_SUBST(NVCC)
AC_SUBST(NVCCFLAGS)

#Check for CUDA libraries
save_LDFLAGS="$LDFLAGS"
LDFLAGS="$LDFLAGS $CUDA_LDFLAGS"
AC_CHECK_LIB([cudart], [cudaMalloc], [], [
	echo "ERROR: CUDA must be installed."
	exit -1
])
LDFLAGS="$save_LDFLAGS"

ACX_PTHREADS([], [
	echo "ERROR: Could not determine pthreads flags."
	exit -1
])

AC_CONFIG_FILES(Makefile src/Makefile)
AC_OUTPUT

