
#include <stdio.h>

void diff1_2o_1d(float *data, float *xs, float *diff, int leni) {
    int idx;
    double alpha;

    diff[0] = (data[1] - data[0]) / (xs[1] - xs[0]);
    for (idx = 1; idx < leni - 1; idx += 1) {
        alpha = ((double)xs[idx + 1] - xs[idx]) / (xs[idx] - xs[idx - 1]);
        diff[idx] = (data[idx + 1] + (alpha - 1) * data[idx] - alpha * data[idx - 1]) 
                  / (2 * alpha * (xs[idx] - xs[idx - 1]));
    }

    diff[leni - 1] = (data[leni - 1] - data[leni - 2]) / (xs[leni - 1] - xs[leni - 2]);
}

void diff1_2o_2di(float **data, float **xs, float **diff, int leni, int lenj) {
    int idx, jdy;
    float alpha;

    for (jdy = 0; jdy < lenj; jdy++) {
        diff[0][jdy] = (data[1][jdy] - data[0][jdy]) 
                     / (xs[1][jdy] - xs[0][jdy]);
    }

    for (idx = 1; idx < leni - 1; idx++) {
        for (jdy = 0; jdy < lenj; jdy++) {
            alpha = (xs[idx + 1][jdy] - xs[idx][jdy]) / (xs[idx][jdy] - xs[idx - 1][jdy]);
            diff[idx][jdy] = (data[idx + 1][jdy] + (alpha - 1) * data[idx][jdy] - alpha * data[idx - 1][jdy])
                           / (2 * alpha * (xs[idx][jdy] - xs[idx - 1][jdy]));
        }
    }

    for (jdy = 0; jdy < lenj; jdy++) {
        diff[leni][jdy] = (data[leni - 1][jdy] - data[leni - 2][jdy]) 
                        / (xs[leni - 1][jdy] - xs[leni - 2][jdy]);
    }
}

void diff1_2o_2dj(float **data, float **ys, float **diff, int leni, int lenj) {
    int idx;

    for (idx = 0; idx < leni; idx += 1) {
        diff1_2o_1d(data[idx], ys[idx], diff[idx], lenj);
    }
}
