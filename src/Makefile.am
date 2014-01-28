.cu.o:
	$(NVCC) -o $@ -c $< $(NVCCFLAGS)
	
.cu.lo:
	$(top_srcdir)/cudalt.py $@ $(NVCC) $(NVCC_CFLAGS) --compiler-options=\"$(CFLAGS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS)\" -c $<
	
CCLD=$(CC)
bin_PROGRAMS = cuda_intro
cuda_intro_SOURCES = cuda_intro.c
cuda_intro_CFLAGS = $(CUDA_CFLAGS)
cuda_intro_LDADD = $(CUDA_LIBS)
cuda_intro_LDFLAGS =
