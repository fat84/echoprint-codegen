//
//  echoprint-codegen
//  Copyright 2011 The Echo Nest Corporation. All rights reserved.
//



#include "MatrixUtility.h"

// http://www.boost.org/doc/libs/1_35_0/libs/numeric/ublas/doc/matrix.htm

namespace MatrixUtility {

bool TextFileOutputUint(const matrix_u& A, const char* filename) {
    FILE *matrix_file = fopen(filename, "w");
    bool success = (matrix_file != NULL);
    if (success) {
        const uint *d = &A.data()[0];
        for (uint i = 0; i < A.size1(); i++) {
            for (uint j = 0; j < A.size2(); j++)
                fprintf(matrix_file, "%d ", d[i*A.size2() + j]);

            fprintf(matrix_file, "\n");
        }
        fclose(matrix_file);
    }
    return success;
}

bool TextFileOutputVectorUint(const std::vector<uint>& A, int size1, int size2, const char* filename) {
    FILE *matrix_file = fopen(filename, "w");
    bool success = (matrix_file != NULL);
    if (success) {
        for (uint i = 0; i < size1; i++) {
            for (uint j = 0; j < size2; j++)
                fprintf(matrix_file, "%d ", A[i*size2 + j]);

            fprintf(matrix_file, "\n");
        }
        fclose(matrix_file);
    }
    return success;
}

bool TextFileOutput(const matrix_f& A, const char* filename) {
    FILE *matrix_file = fopen(filename, "w");
    bool success = (matrix_file != NULL);
    if (success) {
        const float *d = &A.data()[0];
        for (uint i = 0; i < A.size1(); i++) {
            for (uint j = 0; j < A.size2(); j++)
                fprintf(matrix_file, "%2.3f ", d[i*A.size2() + j]);

            fprintf(matrix_file, "\n");
        }
        fclose(matrix_file);
    }
    return success;
}

bool FileOutput(const matrix_f& A, const char* filename) {
    FILE *matrix_file = fopen(filename, "wb");
    bool success = (matrix_file != NULL);
    if (success) {
        uint mm = A.size1();
        uint mn = A.size2();
        fwrite(&mm, sizeof(int), 1, matrix_file);
        fwrite(&mn, sizeof(int), 1, matrix_file);

        for (uint i = 0; i< A.size1(); i++) {
            for(uint j=0;j<A.size2(); j++) {
                const float d = A(i, j);
                fwrite(&d, sizeof(float), 1, matrix_file);
            }
        }
        fclose(matrix_file);
    }
    return success;
}



} // namespace
