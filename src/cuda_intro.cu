/*
 * This file is part of cuAutotools.
 *
 * cuAutotools is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * cuAutotools is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with cuAutotools.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>

__global__ void kernel(void)
{
}

int main(int argc, char *argv[])
{
  cudaError_t d_error = cudaSuccess;
  printf("[*] Calling useless kernel...\n");
  kernel<<<1,1>>>();
  d_error = cudaGetLastError();
  if(d_error!=cudaSuccess)
  {
    fprintf(stderr,"[ERROR] Error running the simples kernel available\n");
    return EXIT_FAILURE;
  }
  printf("[*] Useless kernel called, runned, and exit normally...\n");
  return EXIT_SUCCESS;
}