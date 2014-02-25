.cu.o:
	$(NVCC) -o $@ -c $< $(NVCCFLAGS)

.cu.lo:
	$(top_srcdir)/cudalt.py $@ $(NVCC) $(NVCC_CFLAGS) --compiler-options=\"$(CFLAGS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS)\" -c $<

CCLD=$(CC)
bin_PROGRAMS = cuda_intro omp_intro pthread_intro mpi_intro

cuda_intro_SOURCES = cuda_intro.cu
cuda_intro_CFLAGS = $(CUDA_CFLAGS)
cuda_intro_LDADD = $(CUDA_LIBS)
cuda_intro_LDFLAGS =

omp_intro_SOURCES = omp_intro.c
omp_intro_CFLAGS = $(OPENMP_CFLAGS)
omp_intro_CXXFLAGS = $(OPENMP_CXXFLAGS)

pthread_intro_SOURCES = pthread_intro.c
pthread_intro_CFLAGS = $(PTHREAD_CFLAGS)
pthread_intro_LDADD = $(PTHREAD_LIBS)

mpi_intro_SOURCES = mpi_intro.c
mpi_intro_CFLAGS = $(MPI_CFLAGS)
mpi_intro_LDFLAGS = $(MPI_CLDFLAGS)

#hw2_SOURCES = hw2.c
#hw2_CFLAGS = $(OPENMP_CFLAGS) $(PTHREAD_CFLAGS)
#hw2_LDADD = $(PTHREAD_LIBS)
#hw2_CXXFLAGS = $(OPENMP_CXXFLAGS)
