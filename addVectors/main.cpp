#include "occa.hpp"

int main(int argc, char **argv){
  occa::device device;
  device.setup("mode = OpenMP");
  // device.setup("mode = OpenCL, platformID = 0, deviceID = 1");

  int *a, *b, *ab;
  const int N = 5;

  a  = new int[N];
  b  = new int[N];
  ab = new int[N];

  for(int i = 0; i < N; ++i){
    a[i]  = i;
    b[i]  = 1 - i;  // i + 1 - i = 1
    ab[i] = 0;
  }

  occa::memory o_a, o_b, o_ab;

  o_a  = device.malloc(N * sizeof(int), a);
  o_b  = device.malloc(N * sizeof(int));
  o_ab = device.malloc(N * sizeof(int), ab);

  o_b.copyFrom(b);

  occa::kernel addVectors = device.buildKernelFromSource("addVectors.okl",
                                                         "addVectors");

  addVectors(N, o_a, o_b, o_ab);

  o_ab.copyTo(ab);

  for(int i = 0; i < N; ++i)
    std::cout << "ab[" << i << "] = " << ab[i] << '\n';

  return 0;
}