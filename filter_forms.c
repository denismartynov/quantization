#include <stdlib.h>

void iir_df2_double(double* input, double* output, int s, double **sos, double g, int n)
{
    int i,j;
    double **w = malloc(n*sizeof(double*));
    for(i=0; i<n; i++) w[i] = malloc (3 * sizeof(double));
    for(i=0; i<n; i++) for(j=0; j<3; j++) w[i][j] = 0;

    double out;

    for(j=0; j<s; j++) {
        out = g*input[j];
        for(i=0; i<n; i++) {
            w[i][2] = w[i][1];
            w[i][1] = w[i][0];
            w[i][0] = out - sos[i][0]*w[i][1] - sos[i][1]*w[i][2];
            out = w[i][0] + sos[i][2]*w[i][1] + sos[i][3]*w[i][2];
        }
        output[j] = out;
    }
}

void iir_df2_single(double* input, double* output, int s, double **sos, double g, int n)
{
    int i,j;

    float **w = (float **)malloc(n*sizeof(float*));
    for(i=0; i<n; i++) w[i] = (float *)malloc (3 * sizeof(float));
    for(i=0; i<n; i++) for(j=0; j<3; j++) w[i][j] = 0;
       
    float out;

    for(j=0; j<s; j++) {
        out = g * input[j];
        for(i=0; i<n; i++) {
            w[i][2] = w[i][1];
            w[i][1] = w[i][0];
            w[i][0] = out - sos[i][0]*w[i][1] - sos[i][1]*w[i][2];
            out = w[i][0] + sos[i][2]*w[i][1] + sos[i][3]*w[i][2];
        }
        output[j] = out;
    }
}

void iir_bqf_double(double* input, double* output, int s, double **sos, double g, int n)
{
    int i,j;

    double **w = malloc(n*sizeof(double*));
    for(i=0; i<n; i++) w[i] = malloc (2 * sizeof(double));
    for(i=0; i<n; i++) for(j=0; j<2; j++) w[i][j] = 0;

    double **u = malloc(n*sizeof(double*));
    for(i=0; i<n; i++) u[i] = malloc (2 * sizeof(double));
    for(i=0; i<n; i++) for(j=0; j<2; j++) u[i][j] = 0;

    double out;

    for(j=0; j<s; j++) {
        out = g*input[j];
        for(i=0; i<n; i++) {
            w[i][1] = w[i][0];
            u[i][1] = u[i][0];
            w[i][0] = out + sos[i][0]*w[i][1] + sos[i][1]*u[i][1];
            u[i][0] = w[i][1] + u[i][1];
            out += sos[i][2]*w[i][1] + sos[i][3]*u[i][1];
        }
        output[j] = out;
    }
}

void iir_bqf_single(double* input, double* output, int s, double **sos, double g, int n)
{
    int i,j;

    float **w = (float **)malloc(n*sizeof(float*));
    for(i=0; i<n; i++) w[i] = (float *)malloc (2 * sizeof(float));
    for(i=0; i<n; i++) for(j=0; j<2; j++) w[i][j] = 0;

    float **u = (float **)malloc(n*sizeof(float*));
    for(i=0; i<n; i++) u[i] = (float *)malloc (2 * sizeof(float));
    for(i=0; i<n; i++) for(j=0; j<2; j++) u[i][j] = 0;

    float out;

    for(j=0; j<s; j++) {
        out = g*input[j];
        for(i=0; i<n; i++) {
            w[i][1] = w[i][0];
            u[i][1] = u[i][0];
            w[i][0] = out + sos[i][0]*w[i][1] + sos[i][1]*u[i][1];
            u[i][0] = w[i][1] + u[i][1];
            out += sos[i][2]*w[i][1] + sos[i][3]*u[i][1];
        }
        output[j] = out;
     }
}