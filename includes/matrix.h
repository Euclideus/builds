#ifndef MATRIX_H
#define MATRIX_H

#include <arb.h>
#include <doubly_linked_list.h>

typedef struct matrix{

  int32_t rank,size;
  void **t;
}matrix;

matrix *initializeMatrix(int32_t *dims, int32_t rank);
matrix *matrixFromVector(cmplx *v);
matrix *matrixFromRealVector(double *v);
matrix *matrixFromMatrix(cmplx **v);
void freeMatrix(void *t1);
matrix *getMatrixElement(matrix *t,int32_t *indxs);
void *getMatrixElement1(matrix *t,int32_t indx);
int32_t setMatrixElement1(matrix *t,int32_t indx,matrix *t1);
int32_t setMatrixElement(matrix *t,int32_t *indxs,matrix *t1);
matrix *initializeMatrix0(cmplx cval);
cmplx *getMatrixValue(matrix *t,int32_t *indxs);
int32_t setMatrixValue(matrix *t,int32_t *indxs,cmplx cval);
void *copyMatrix(void *t1);
void readMatrixFromStream(matrix **t, void *fs, stream_type st);
void *readMatrix(void *fs, stream_type st);
void writeMatrix(void *t,void *fs,stream_type st);
char *printMatrixDimensions(matrix *t);
void printMatrixDimensionsSub(char **outs,matrix *t);
int32_t addMatrix(matrix *tdest,matrix *tnew);
matrix *diagonalMatrix(matrix *elem);
matrix *addMatrices(matrix *t11, matrix *t22);
int32_t testSquareMatrix(matrix *m);
matrix *subtractMatrices(matrix *t11,matrix *t22);
int32_t subtractMatrix(matrix *tdest,matrix *tnew);
int32_t multiplyScalar(matrix *tdest,cmplx tnew);
cmplx innerProduct(matrix *t1, matrix *t2, int32_t conj, int32_t *success);
matrix *innerProductMul(matrix *t1, matrix *t2);
matrix *multiplyMatrices(matrix *t1, matrix *t2);
dl_list PermutationCycleDecomposition(int32_t *indxs);
int32_t TestEqualValuesL(int32_t *indxs);
int32_t TestEqualValuesLSub(int32_t i1,int32_t *indxs,int32_t ni);
int32_t PermutationParity(int32_t *indxs);
int32_t LeviCivita(int32_t *indxs);
char *PrintPermutationCycles(int32_t *indx);
int32_t *getMatrixDimensions(matrix *m);
void getMatrixDimensionsSub(matrix *m,int32_t *dims);
matrix *identityMatrix(int32_t rank,int32_t size);
matrix *matrixFromScalar(cmplx scal,int32_t *dims);
matrix *numberMatrix(int32_t rank,int32_t size,cmplx v);
matrix *directSum(matrix *m11, matrix *m22);
matrix *directProduct(matrix *m11, matrix *m22);
void transposeMatrix(matrix *m, int32_t recurse);
void conjugateMatrix(matrix *m);
matrix *matrixTrace(matrix *m);
cmplx **matrixToMatrix(matrix *v);
double **matrixToRealMatrix(matrix *v);
matrix *matrixDeterminant(matrix *m);
int32_t invertMatrix(matrix *m);
matrix *matrixEigenvalues(matrix *m);
matrix *matrixEigenvectors(matrix *m);
void vectorizeMatrix(matrix *m);
void matricizeMatrix(matrix *m);
cmplx *getMatrixScalar(matrix *m);
matrix *augmentedMatrix(matrix *m, int32_t cpy);
void freeAugmentedMatrix(matrix *am, int32_t cpy);
matrix *augmentedMatrixLayers(matrix *m,int32_t nlayers,int32_t cpy);
void freeAugmentedMatrixLayers(matrix *am,int32_t nlayers,int32_t cpy);
matrix *initializeMatrixWithElements(matrix *elems,int32_t *dims,int32_t orank);
matrix *augmentedMatrixElements(matrix *m, int32_t depth, int32_t cpy);
void freeAugmentedMatrixElements(matrix *am, int32_t depth, int32_t cpy);
void swapElements(matrix *m,int32_t i1,int32_t i2);
void swapColumns(matrix *m,int32_t i1,int32_t i2);
int32_t appendMatricesV(matrix *mdest,matrix *mnew);
int32_t appendMatricesH(matrix *mdest,matrix *mnew);
int32_t cropMatrix(int32_t pos1,int32_t pos2,matrix *m);
matrix *appendMatrix(matrix *mdest, matrix *mnew, int32_t *success);
void enlargeMatrix(matrix *mdest,int32_t newsize);
matrix *appendColumn(matrix *mdest,matrix *mnew,int32_t *success);
matrix *insertColumn(matrix *mdest,matrix *mnew,int32_t pos,int32_t *success);
matrix *insertMatrix(matrix *mdest,matrix *mnew,int32_t pos,int32_t *success);
void removeNulls(matrix *mdest,int32_t start,int32_t end,int32_t nnulls);
int32_t removeElement(int32_t pos,matrix *m);
int32_t removeElements(int32_t *pos,matrix *m);
int32_t removeColumns(int32_t *pos,matrix *m);

#endif
