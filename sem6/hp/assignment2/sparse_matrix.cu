#include <stdio.h>
#include <stdlib.h>
#include <cuda_runtime.h>

__global__ void spmv_csr_kernel(const int num_rows,
                                const int *row_ptr,
                                const int *col_idx,
                                const float *values,
                                const float *x,
                                float *y)
{
    int row = blockIdx.x * blockDim.x + threadIdx.x;
    if (row < num_rows)
    {
        float dot_product = 0.0f;
        int row_start = row_ptr[row];
        int row_end = row_ptr[row + 1];

        for (int i = row_start; i < row_end; i++)
            dot_product += values[i] * x[col_idx[i]];
        y[row] = dot_product;
    }
}

void spmv_csr(const int num_rows, const int num_cols, const int nnz,
              const int *h_row_ptr, const int *h_col_idx, const float *h_values,
              const float *h_x, float *h_y)
{

    int *d_row_ptr, *d_col_idx;
    float *d_values, *d_x, *d_y;

    cudaMalloc((void **)&d_row_ptr, (num_rows + 1) * sizeof(int));
    cudaMalloc((void **)&d_col_idx, nnz * sizeof(int));
    cudaMalloc((void **)&d_values, nnz * sizeof(float));
    cudaMalloc((void **)&d_x, num_cols * sizeof(float));
    cudaMalloc((void **)&d_y, num_rows * sizeof(float));

    cudaMemcpy(d_row_ptr, h_row_ptr, (num_rows + 1) * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_col_idx, h_col_idx, nnz * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_values, h_values, nnz * sizeof(float), cudaMemcpyHostToDevice);
    cudaMemcpy(d_x, h_x, num_cols * sizeof(float), cudaMemcpyHostToDevice);

    int block_size = 256;
    int grid_size = (num_rows + block_size - 1) / block_size;

    spmv_csr_kernel<<<grid_size, block_size>>>(num_rows, d_row_ptr, d_col_idx, d_values, d_x, d_y);

    // Check for errors
    cudaError_t err = cudaGetLastError();
    if (err != cudaSuccess)
    {
        printf("CUDA Error: %s\n", cudaGetErrorString(err));
    }

    cudaMemcpy(h_y, d_y, num_rows * sizeof(float), cudaMemcpyDeviceToHost);

    cudaFree(d_row_ptr);
    cudaFree(d_col_idx);
    cudaFree(d_values);
    cudaFree(d_x);
    cudaFree(d_y);
}

void verify_results(const int num_rows, const int *row_ptr, const int *col_idx,
                    const float *values, const float *x, const float *y)
{
    float *y_verify = (float *)malloc(num_rows * sizeof(float));

    for (int i = 0; i < num_rows; i++)
    {
        float sum = 0.0f;
        for (int j = row_ptr[i]; j < row_ptr[i + 1]; j++)
        {
            sum += values[j] * x[col_idx[j]];
        }
        y_verify[i] = sum;
    }

    float max_error = 0.0f;
    for (int i = 0; i < num_rows; i++)
    {
        float error = fabs(y_verify[i] - y[i]);
        if (error > max_error)
        {
            max_error = error;
        }
    }

    printf("Max Error: %f\n", max_error);
    free(y_verify);
}

int main()
{
    // Sample matrix in CSR format
    // This represents a 5x5 sparse matrix:
    // [ 1.0  0.0  0.0  2.0  0.0 ]
    // [ 0.0  3.0  0.0  0.0  0.0 ]
    // [ 0.0  0.0  4.0  0.0  5.0 ]
    // [ 6.0  0.0  0.0  7.0  0.0 ]
    // [ 0.0  8.0  0.0  0.0  9.0 ]

    const int num_rows = 5;
    const int num_cols = 5;
    const int nnz = 9;

    int h_row_ptr[6] = {0, 2, 3, 5, 7, 9};                             // size = num_rows + 1
    int h_col_idx[9] = {0, 3, 1, 2, 4, 0, 3, 1, 4};                    // size = nnz
    float h_values[9] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0}; // size = nnz

    float h_x[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    float h_y[5] = {0.0};

    spmv_csr(num_rows, num_cols, nnz, h_row_ptr, h_col_idx, h_values, h_x, h_y);

    printf("Result vector y:\n");
    for (int i = 0; i < num_rows; i++)
    {
        printf("%f\n", h_y[i]);
    }

    verify_results(num_rows, h_row_ptr, h_col_idx, h_values, h_x, h_y);

    return 0;
}