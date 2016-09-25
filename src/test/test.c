
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "../taylor.h"

#define MAX(a1, a2) (a1) > (a2) ? (a1) : (a2)

void gen_xs(float* xs, int len, float x_max, float dx_min) {
    int idx;
    float s_max, s_max_sq;

    s_max = (float)len - 1;
    s_max_sq = s_max * s_max;

    for (idx = 0; idx < len; idx += 1) {
        xs[idx] = 12 * (x_max / s_max - dx_min) * (pow(idx, 3) / (3 * s_max_sq) - pow(idx, 2) / (2 * s_max)) 
                + (3 * x_max / s_max - 2 * dx_min) * idx;
    }
}

void test_diff1_2o_1d(int len, int nreps) {
    float *data, *xs, *diff, *ans;
    int idx;
    const float x_max = 100., dx_min = 0.01;
    double ans_mae, ans_max_err;
    clock_t ttot, tstart;
    float total_time;

    data = (float*)malloc(len * sizeof(float));
    xs = (float*)malloc(len * sizeof(float));
    diff = (float*)malloc(len * sizeof(float));
    ans = (float*)malloc(len * sizeof(float));

    gen_xs(xs, len, x_max, dx_min);

    for (idx = 0; idx < len; idx += 1) {
        data[idx] = xs[idx] * xs[idx];
        ans[idx] = 2 * xs[idx];
    }

    ttot = 0;
    for (idx = 0; idx < nreps; idx += 1) {
        tstart = clock(); 
        diff1_2o_1d(data, xs, diff, len);
        ttot += (clock() - tstart);
    }

    ans_mae = 0.;
    ans_max_err = 0.;
    for (idx = 1; idx < len - 1; idx += 1) {
        ans_mae += fabs((double)diff[idx] - ans[idx]);
        ans_max_err = MAX(ans_max_err, (double)diff[idx] - ans[idx]);
    }

    total_time = (float)ttot / CLOCKS_PER_SEC;
    printf("MAE for diff1_2o_1d is %6.4e\n", ans_mae / len);
    printf("Max error for diff1_2o_1d is %6.4e\n", ans_max_err);
    printf("%d iterations took %6.4e s (%6.4e s per iteration)\n", nreps, total_time, total_time / nreps);

    free(ans);
    free(diff);
    free(xs);
    free(data);
}

int main(int argv, char* argc[]) {
    int len;
    int nreps;

    len = 10000;
    nreps = 1000;
    test_diff1_2o_1d(len, nreps);
}
