#include <string.h>
#include "ecc.h"

#define TRUE 1
#define FALSE 0

void get_curve_param(curve_params_t *para)
{
#ifdef EIGHT_BIT_PROCESSOR
  memset(para->p, 0, NUMWORDS * NN_DIGIT_LEN);
  para->p[31] = 0xFF;
  para->p[30] = 0xFF;
  para->p[29] = 0xFF;
  para->p[28] = 0xFF;
  para->p[27] = 0xFF;
  para->p[26] = 0xFF;
  para->p[25] = 0xFF;
  para->p[24] = 0xFF;
  para->p[23] = 0xFF;
  para->p[22] = 0xFF;
  para->p[21] = 0xFF;
  para->p[20] = 0xFF;
  para->p[19] = 0xFF;
  para->p[18] = 0xFF;
  para->p[17] = 0xFF;
  para->p[16] = 0xFF;
  para->p[15] = 0xFF;
  para->p[14] = 0xFF;
  para->p[13] = 0xFF;
  para->p[12] = 0xFF;
  para->p[11] = 0xFF;
  para->p[10] = 0xFF;
  para->p[9] = 0xFF;
  para->p[8] = 0xFF;
  para->p[7] = 0xFF;
  para->p[6] = 0xFF;
  para->p[5] = 0xFF;
  para->p[4] = 0xFE;
  para->p[3] = 0xFF;
  para->p[2] = 0xFF;
  para->p[1] = 0xFC;
  para->p[0] = 0x2F;

  memset(para->omega, 0, NUMWORDS * NN_DIGIT_LEN);
  para->omega[4] = 0x01;
  para->omega[1] = 0x03;
  para->omega[0] = 0xD1;
  // curve that will be used
  // a = 0
  memset(para->E.a, 0, NUMWORDS * NN_DIGIT_LEN);

  para->E.a_minus3 = FALSE;
  para->E.a_zero = TRUE;

  // b = 7
  memset(para->E.b, 0, NUMWORDS * NN_DIGIT_LEN);
  para->E.b[0] = 0x7;

  // base point
  memset(para->G.x, 0, NUMWORDS * NN_DIGIT_LEN);
  para->G.x[31] = 0x79;
  para->G.x[30] = 0xBE;
  para->G.x[29] = 0x66;
  para->G.x[28] = 0x7E;
  para->G.x[27] = 0xF9;
  para->G.x[26] = 0xDC;
  para->G.x[25] = 0xBB;
  para->G.x[24] = 0xAC;
  para->G.x[23] = 0x55;
  para->G.x[22] = 0xA0;
  para->G.x[21] = 0x62;
  para->G.x[20] = 0x95;
  para->G.x[19] = 0xCE;
  para->G.x[18] = 0x87;
  para->G.x[17] = 0x0B;
  para->G.x[16] = 0x07;
  para->G.x[15] = 0x02;
  para->G.x[14] = 0x9B;
  para->G.x[13] = 0xFC;
  para->G.x[12] = 0xDB;
  para->G.x[11] = 0x2D;
  para->G.x[10] = 0xCE;
  para->G.x[9] = 0x28;
  para->G.x[8] = 0xD9;
  para->G.x[7] = 0x59;
  para->G.x[6] = 0xF2;
  para->G.x[5] = 0x81;
  para->G.x[4] = 0x5B;
  para->G.x[3] = 0x16;
  para->G.x[2] = 0xF8;
  para->G.x[1] = 0x17;
  para->G.x[0] = 0x98;

  memset(para->G.y, 0, NUMWORDS * NN_DIGIT_LEN);
  para->G.y[31] = 0x48;
  para->G.y[30] = 0x3A;
  para->G.y[29] = 0xDA;
  para->G.y[28] = 0x77;
  para->G.y[27] = 0x26;
  para->G.y[26] = 0xA3;
  para->G.y[25] = 0xC4;
  para->G.y[24] = 0x65;
  para->G.y[23] = 0x5D;
  para->G.y[22] = 0xA4;
  para->G.y[21] = 0xFB;
  para->G.y[20] = 0xFC;
  para->G.y[19] = 0x0E;
  para->G.y[18] = 0x11;
  para->G.y[17] = 0x08;
  para->G.y[16] = 0xA8;
  para->G.y[15] = 0xFD;
  para->G.y[14] = 0x17;
  para->G.y[13] = 0xB4;
  para->G.y[12] = 0x48;
  para->G.y[11] = 0xA6;
  para->G.y[10] = 0x85;
  para->G.y[9] = 0x54;
  para->G.y[8] = 0x19;
  para->G.y[7] = 0x9C;
  para->G.y[6] = 0x47;
  para->G.y[5] = 0xD0;
  para->G.y[4] = 0x8F;
  para->G.y[3] = 0xFB;
  para->G.y[2] = 0x10;
  para->G.y[1] = 0xD4;
  para->G.y[0] = 0xB8;

  // prime divide the number of points
  memset(para->r, 0, NUMWORDS * NN_DIGIT_LEN);
  para->r[31] = 0xFF;
  para->r[30] = 0xFF;
  para->r[29] = 0xFF;
  para->r[28] = 0xFF;
  para->r[27] = 0xFF;
  para->r[26] = 0xFF;
  para->r[25] = 0xFF;
  para->r[24] = 0xFF;
  para->r[23] = 0xFF;
  para->r[22] = 0xFF;
  para->r[21] = 0xFF;
  para->r[20] = 0xFF;
  para->r[19] = 0xFF;
  para->r[18] = 0xFF;
  para->r[17] = 0xFF;
  para->r[16] = 0xFE;
  para->r[15] = 0xBA;
  para->r[14] = 0xAE;
  para->r[13] = 0xDC;
  para->r[12] = 0xE6;
  para->r[11] = 0xAF;
  para->r[10] = 0x48;
  para->r[9] = 0xA0;
  para->r[8] = 0x3B;
  para->r[7] = 0xBF;
  para->r[6] = 0xD2;
  para->r[5] = 0x5E;
  para->r[4] = 0x8C;
  para->r[3] = 0xD0;
  para->r[2] = 0x36;
  para->r[1] = 0x41;
  para->r[0] = 0x41;

  /* EIGHT_BIT_PROCESSOR */
#elif defined(SIXTEEN_BIT_PROCESSOR)
  memset(para->p, 0, NUMWORDS * NN_DIGIT_LEN);
  para->p[15] = 0xFFFF;
  para->p[14] = 0xFFFF;
  para->p[13] = 0xFFFF;
  para->p[12] = 0xFFFF;
  para->p[11] = 0xFFFF;
  para->p[10] = 0xFFFF;
  para->p[9] = 0xFFFF;
  para->p[8] = 0xFFFF;
  para->p[7] = 0xFFFF;
  para->p[6] = 0xFFFF;
  para->p[5] = 0xFFFF;
  para->p[4] = 0xFFFF;
  para->p[3] = 0xFFFF;
  para->p[2] = 0xFFFE;
  para->p[1] = 0xFFFF;
  para->p[0] = 0xFC2F;

  memset(para->omega, 0, NUMWORDS * NN_DIGIT_LEN);
  para->omega[2] = 0x0001;
  para->omega[0] = 0x03D1;
  // curve that will be used
  // a = 0
  memset(para->E.a, 0, NUMWORDS * NN_DIGIT_LEN);

  para->E.a_minus3 = FALSE;
  para->E.a_zero = TRUE;

  // b = 7
  memset(para->E.b, 0, NUMWORDS * NN_DIGIT_LEN);
  para->E.b[0] = 0x7;

  // base point
  memset(para->G.x, 0, NUMWORDS * NN_DIGIT_LEN);
  para->G.x[15] = 0x79BE;
  para->G.x[14] = 0x667E;
  para->G.x[13] = 0xF9DC;
  para->G.x[12] = 0xBBAC;
  para->G.x[11] = 0x55A0;
  para->G.x[10] = 0x6295;
  para->G.x[9] = 0xCE87;
  para->G.x[8] = 0x0B07;
  para->G.x[7] = 0x029B;
  para->G.x[6] = 0xFCDB;
  para->G.x[5] = 0x2DCE;
  para->G.x[4] = 0x28D9;
  para->G.x[3] = 0x59F2;
  para->G.x[2] = 0x815B;
  para->G.x[1] = 0x16F8;
  para->G.x[0] = 0x1798;

  memset(para->G.y, 0, NUMWORDS * NN_DIGIT_LEN);
  para->G.y[15] = 0x483A;
  para->G.y[14] = 0xDA77;
  para->G.y[13] = 0x26A3;
  para->G.y[12] = 0xC465;
  para->G.y[11] = 0x5DA4;
  para->G.y[10] = 0xFBFC;
  para->G.y[9] = 0x0E11;
  para->G.y[8] = 0x08A8;
  para->G.y[7] = 0xFD17;
  para->G.y[6] = 0xB448;
  para->G.y[5] = 0xA685;
  para->G.y[4] = 0x5419;
  para->G.y[3] = 0x9C47;
  para->G.y[2] = 0xD08F;
  para->G.y[1] = 0xFB10;
  para->G.y[0] = 0xD4B8;

  // prime divide the number of points
  memset(para->r, 0, NUMWORDS * NN_DIGIT_LEN);
  para->r[15] = 0xFFFF;
  para->r[14] = 0xFFFF;
  para->r[13] = 0xFFFF;
  para->r[12] = 0xFFFF;
  para->r[11] = 0xFFFF;
  para->r[10] = 0xFFFF;
  para->r[9] = 0xFFFF;
  para->r[8] = 0xFFFE;
  para->r[7] = 0xBAAE;
  para->r[6] = 0xDCE6;
  para->r[5] = 0xAF48;
  para->r[4] = 0xA03B;
  para->r[3] = 0xBFD2;
  para->r[2] = 0x5E8C;
  para->r[1] = 0xD036;
  para->r[0] = 0x4141;
  /* SIXTEEN_BIT_PROCESSOR */
#elif defined(THIRTYTWO_BIT_PROCESSOR)
  // init parameters
  // prime
  memset(para->p, 0, NUMWORDS * NN_DIGIT_LEN);
  para->p[7] = 0xFFFFFFFF;
  para->p[6] = 0xFFFFFFFF;
  para->p[5] = 0xFFFFFFFF;
  para->p[4] = 0xFFFFFFFF;
  para->p[3] = 0xFFFFFFFF;
  para->p[2] = 0xFFFFFFFF;
  para->p[1] = 0xFFFFFFFE;
  para->p[0] = 0xFFFFFC2F;

  memset(para->omega, 0, NUMWORDS * NN_DIGIT_LEN);
  para->omega[1] = 0x00000001;
  para->omega[0] = 0x000003D1;
  // curve that will be used
  // a = 0
  memset(para->E.a, 0, NUMWORDS * NN_DIGIT_LEN);

  para->E.a_minus3 = FALSE;
  para->E.a_zero = TRUE;

  // b = 7
  memset(para->E.b, 0, NUMWORDS * NN_DIGIT_LEN);
  para->E.b[0] = 0x7;

  // base point
  memset(para->G.x, 0, NUMWORDS * NN_DIGIT_LEN);
  para->G.x[7] = 0x79BE667E;
  para->G.x[6] = 0xF9DCBBAC;
  para->G.x[5] = 0x55A06295;
  para->G.x[4] = 0xCE870B07;
  para->G.x[3] = 0x029BFCDB;
  para->G.x[2] = 0x2DCE28D9;
  para->G.x[1] = 0x59F2815B;
  para->G.x[0] = 0x16F81798;

  memset(para->G.y, 0, NUMWORDS * NN_DIGIT_LEN);
  para->G.y[7] = 0x483ADA77;
  para->G.y[6] = 0x26A3C465;
  para->G.y[5] = 0x5DA4FBFC;
  para->G.y[4] = 0x0E1108A8;
  para->G.y[3] = 0xFD17B448;
  para->G.y[2] = 0xA6855419;
  para->G.y[1] = 0x9C47D08F;
  para->G.y[0] = 0xFB10D4B8;

  // prime divide the number of points
  memset(para->r, 0, NUMWORDS * NN_DIGIT_LEN);
  para->r[7] = 0xFFFFFFFF;
  para->r[6] = 0xFFFFFFFF;
  para->r[5] = 0xFFFFFFFF;
  para->r[4] = 0xFFFFFFFE;
  para->r[3] = 0xBAAEDCE6;
  para->r[2] = 0xAF48A03B;
  para->r[1] = 0xBFD25E8C;
  para->r[0] = 0xD0364141;

#endif /* THIRTYTWO_BIT_PROCESSOR */
}

NN_UINT omega_mul(NN_DIGIT *a, NN_DIGIT *b, NN_DIGIT *omega, NN_UINT digits)
{
#ifdef EIGHT_BIT_PROCESSOR
  a[digits] += NN_AddDigitMult(a, a, omega[0], b, digits);
  a[digits + 2] += NN_AddDigitMult(a + 1, a + 1, omega[1], b, digits + 1);
  a[digits + 4] = NN_Add(&a[4], &a[4], b, digits);
  return (digits + 5);
#elif defined(SIXTEEN_BIT_PROCESSOR)
  a[digits] += NN_AddDigitMult(a, a, omega[0], b, digits);
  a[digits + 2] = NN_Add(&a[2], &a[2], b, digits);
  return (digits + 3);
#elif defined(THIRTYTWO_BIT_PROCESSOR)
  a[digits] += NN_AddDigitMult(a, a, omega[0], b, digits);
  a[digits + 1] = NN_Add(&a[1], &a[1], b, digits);
  return (digits + 2);
#endif
}
