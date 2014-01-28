dnl Process this file with autoconf to produce a configure script.

AC_PREREQ([2.59])
AC_INIT([cs546], [0.0.1], [spenser@gillilanding.com])

AC_CANONICAL_SYSTEM
AM_INIT_AUTOMAKE

AC_CONFIG_SRCDIR([src/cuda_intro.cu])
AC_CONFIG_HEADERS([config.h])

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

AC_CHECK_FUNCS([pow])

AC_CONFIG_FILES([Makefile
                 src/Makefile])

dnl Check for Pthreads
AX_PTHREAD(HAVE_PTHREAD=yes, HAVE_PTHREAD=no)

if test "x$HAVE_PTHREAD" = "xno"; then
	AC_MSG_ERROR(Pthread library not found. Please set PTHREAD_CFLAGS and PTHREAD_LIBS correctly for your setup)
fi

AC_SUBST(PTHREAD_LIBS)
AC_SUBST(PTHREAD_CFLAGS)
AC_SUBST(PTHREAD_CC)

dnl Check for openmp
AX_OPENMP(HAVE_OPENMP=yes, HAVE_OPENMP=no)

if test "x$HAVE_OPENMP" = "xno"; then
	AC_MSG_ERROR(OpenMP libraries are not found. Please set OPENMP_CFLAGS and OPENMP_LIBS correctly for your setup)
fi

AC_SUBST(OPENMP_CFLAGS)
AC_SUBST(OPENMP_CXXFLAGS)

dnl Check for openmpi
AX_MPI(HAVE_MPI=yes, HAVE_MPI=no)

if test "x$HAVE_MPI" = "xno"; then
	AC_MSG_ERROR(MPI libraries are not found.  Please set MPICC, MPICXX, and MPILIBS)
fi

AC_SUBST(MPICC)
AC_SUBST(MPICXX)
AC_SUBST(MPILIBS)

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

#Check for CUDA libraries
save_LDFLAGS="$LDFLAGS"
LDFLAGS="$LDFLAGS $CUDA_LDFLAGS"
AC_CHECK_LIB([cudart], [cudaMalloc], HAVE_CUDA=yes, HAVE_CUDA=no)
LDFLAGS="$save_LDFLAGS"

if test "x$HAVE_CUDA" = "xno"; then
	AC_MSG_ERROR(CUDA libraries could not be found.)
fi

CUDA_LIBS="$CUDA_LIBS -lcudart"

AC_SUBST(CUDA_CFLAGS)
AC_SUBST(CUDA_LIBS)
AC_SUBST(NVCC)
AC_SUBST(NVCCFLAGS)

AC_OUTPUT

