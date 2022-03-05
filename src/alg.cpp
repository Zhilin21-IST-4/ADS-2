// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double k = value;
  if (n == 0) {
    return 1;}
  if (n == 1) {
    return value;}
  k *= pown(value, n - 1);
  return k;
}

uint64_t fact(uint16_t n) {
  if (n == 0) {
    return 1;
  }
  return n * fact(n - 1);
}

double calcItem(double x, uint16_t n) {
  double k = pown(x, n) / fact(n);
  return k;
}

double expn(double x, uint16_t count) {
  double exp1 = 1;
  int z = 1;
  while (count > z-1) {
    exp1 += calcItem(x, z);
    z++;
  }
  return exp1;
}

double sinn(double x, uint16_t count) {
  double sin1 = 0;
  for (uint16_t i = 1; i <= count; i++) {
    sin1 += pown(-1, i-1) * calcItem(x, (2 * (i - 1)));
  }
  return sin1;
}

double cosn(double x, uint16_t count) {
  double cos1 = 0;
  for (uint16_t i = 1; i <= count; i++) {
    cos1 += pown(-1, i-1) * calcItem(x, (2 * (i - 2)));
  }
  return cos1;
}
