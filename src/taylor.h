
#ifndef __TAYLOR_H__
#define __TAYLOR_H__

void diff1_2o_1d(float *data, float *xs, float *diff, int leni);

void diff1_2o_2di(float **data, float **xs, float **diff, int leni, int lenj);
void diff1_2o_2dj(float **data, float **ys, float **diff, int leni, int lenj);

#endif
