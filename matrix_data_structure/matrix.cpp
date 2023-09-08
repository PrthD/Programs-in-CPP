#include <iostream>
#include "matrix.h"
using namespace std;

/*
    Description: This is the default constructor for the Matrix class which
                 initializes a 2D Array with 0 rows and 0 columns, pointer to
                 which is initialized as NULL.

    Arguments: The default constructor takes no arguments.
*/
Matrix::Matrix()
{   
    // assigning attribute values
    this->rows = 0;
    this->columns = 0;
    this->size = 0;
    this->matrix = NULL;
}

/*
    Description: This is the first parametrized constructor for the Matrix class
                 which initializes a 2D Array with "num_rows" rows and "num_columns"
                 columns whose all elements equals the float "init".
                 
    Arguments:
        num_rows (size_t): number of rows of the 2D Array to be initialized
        num_columns (size_t): number of columns of the 2D Array to be initialized
        init (float): The value of all elements of the 2D Arrat to be initialized
*/
Matrix::Matrix(size_t num_rows, size_t num_columns, float init)
{
    // assigning attribute values
    this->rows = num_rows;
    this->columns = num_columns;
    this->size = (num_rows * num_columns);

    this->matrix = new float *[num_rows]; // allocating memory for the "num_rows" rows of matrix

    for (int i = 0; i < num_rows; i++)
    {
        matrix[i] = new float[num_columns]; // allocating memory for the "num_columns" columns of matrix
    }

    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_columns; j++)
        {
            matrix[i][j] = init; // initializing all elements of matrix to "init"
        }
    }
}

/*
    Description: This is the second parametrized constructor for the Matrix class
                 which initializes a 2D Array with "num_rows" rows and "num_columns"
                 columns whose all elements are initialized using the data stored in
                 a 1D float array, arr ptr. This array will contain exactly
                 "num_rows" × "num_columns" elements.

    Arguments:
        num_rows (size_t): number of rows of the 2D Array to be initialized
        num_columns (size_t): number of columns of the 2D Array to be initialized
        arr_ptr (float*): pointer to a 1D array whose elements are to be
                                 used to initialize the 2D array
*/
Matrix::Matrix(size_t num_rows, size_t num_columns, float *arr_ptr)
{
    // assigning attribute values
    this->rows = num_rows;
    this->columns = num_columns;
    this->size = (num_rows * num_columns);

    this->matrix = new float *[num_rows]; // allocating memory for the "num_rows" rows of matrix

    for (int i = 0; i < num_rows; i++)
    {
        matrix[i] = new float[num_columns]; // allocating memory for the "num_columns" columns of matrix
    }

    unsigned int array_indx = 0; //initializing the index incrementor
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_columns; j++)
        {
            matrix[i][j] = arr_ptr[array_indx]; // initializing all elements of matrix using data stored in array pointed by "arr_ptr"
            array_indx++;
        }
    }
}

/*
    Description: This is the copy constructor for the Matrix class which is
                 responsible for making a deep copy of an instance of the Matrix class.
                 
    Arguments:
        copy (Matrix&): A matrix instance of the Matrix class whose copy is to be
                       initialized
*/
Matrix::Matrix(const Matrix &copy)
{
    // assigning attribute values
    this->rows = copy.rows;
    this->columns = copy.columns;
    this->size = ((copy.rows) * (copy.columns));

    this->matrix = new float *[rows]; // allocating memory for the "rows" rows of matrix

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new float[columns]; // allocating memory for the "columns" columns of matrix
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            this->matrix[i][j] = copy.matrix[i][j]; // initializing the elements of matrix which are the copy of the instance "copy"
        }
    }
}

/*
    Description: This is the destructor for the Matrix class which frees the
                 dynamically allocated memory when an instance of this class goes
                 out of scope.
                 
    Arguments: The dustructor takes no arguments.
*/
Matrix::~Matrix()
{
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i]; // deleting the allocated memory for every row pointers of matrix
        matrix[i] = NULL; // assigning the stale row pointer NULL
    }
    delete[] matrix; // deleting the allocated memory for the entire matrix
    matrix = NULL; //assigning the stale matrix pointer NULL
}

/*
    Description: This constant matrix operator performs the matrix addition on
                 instances of the Matrix class by overloading the operator "+".

    Arguments:
        rhs (Matrix&): Reference to the Matrix instance on which the addition
                       needs to be performed
    
    Returns: 
        result_mtrx (Matrix): The resultant Matrix instance after the addition
                              is performed
*/
Matrix Matrix::operator+(const Matrix &rhs) const
{
    Matrix result_mtrx = Matrix(this->rows, this->columns, 0.0); // initializing the resulting matrix instance

    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < columns; j++)
        {
            result_mtrx.matrix[i][j] = this->matrix[i][j] + rhs.matrix[i][j]; // adding the elements of matrices individually
        }
    }
    return result_mtrx;
}

/*
    Description: This constant matrix operator performs the matrix subtraction on
                 instances of the Matrix class by overloading the operator "-".

    Arguments:
        rhs (Matrix&): Reference to the Matrix instance on which the subtraction
                       needs to be performed
    
    Returns: 
        result_mtrx (Matrix): The resultant Matrix instance after the subtraction
                              is performed
*/
Matrix Matrix::operator-(const Matrix &rhs) const
{
    Matrix result_mtrx = Matrix(this->rows, this->columns, 0.0); // initializing the resulting matrix instance

    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < columns; j++)
        {
            result_mtrx.matrix[i][j] = this->matrix[i][j] - rhs.matrix[i][j]; // subtracting the elements of matrices individually
        }
    }
    return result_mtrx;
}

/*
    Description: This constant matrix operator performs the matrix multiplication on
                 instances of the Matrix class by overloading the operator "*".

    Arguments:
        rhs (Matrix&): Reference to the Matrix instance on which the multiplication
                       needs to be performed
    
    Returns: 
        result_mtrx (Matrix): The resultant Matrix instance after the multiplication
                              is performed
*/
Matrix Matrix::operator*(const Matrix &rhs) const
{
    Matrix result_mtrx = Matrix(this->rows, rhs.columns, 0.0); // initializing the resulting matrix instance

    for (unsigned int i = 0; i < this->rows; i++)
    {
        for (unsigned int j = 0; j < rhs.columns; j++)
        {
            float result = 0.0; // initializing the multiplication sum
            for (unsigned int k = 0; k < this->columns; k++)
            {
                result += this->matrix[i][k] * rhs.matrix[k][j]; // multiplying the row and column of the respective matrices
            }
            result_mtrx.matrix[i][j] = result; // storing the multiplication sum in the resultant matrix instance
        }
    }
    return result_mtrx;
}

/*
    Description: This constant matrix operator performs the matrix negation on
                 instances of the Matrix class by overloading the operator "-".

    Arguments: This Matrix operator takes no arguments.
    
    Returns: 
        result_mtrx (Matrix): The resultant Matrix instance after the negation
                              is performed
*/
Matrix Matrix::operator-() const
{
    Matrix result_mtrx = Matrix(this->rows, this->columns, 0.0); // initializing the resulting matrix instance

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            result_mtrx.matrix[i][j] = -(this->matrix[i][j]); // additive inversing all elements of the matrix
        }
    }
    return result_mtrx;
}

/*
    Description: This constant matrix operator performs the matrix transposition on
                 instances of the Matrix class.

    Arguments: This Matrix operation takes no arguments.
    
    Returns: 
        result_mtrx (Matrix): The resultant Matrix instance after the transposition
                              is performed
*/
Matrix Matrix::transpose() const
{
    Matrix result_mtrx = Matrix(this->columns, this->rows, 0.0); // initializing the resulting matrix instance

    for (int i = 0; i < this->columns; i++)
    {
        for (int j = 0; j < this->rows; j++)
        {
            result_mtrx.matrix[i][j] = this->matrix[j][i]; // interchanging the row and colum of the matrix
        }
    }
    return result_mtrx;
}

/*
    Description: This matrix operator returns the "index"th row of matrix of an instance of
                 the Matrix class as a float pointer by overloading the operator "[]".

    Arguments:
        index (unsigned int): The row of the matrix that is to be returned as a float pointer
    
    Returns: This operation returns the "index"th row of the matrix of a Matrix class instance
             as a float pointer.
*/
float *Matrix::operator[](unsigned int index)
{
    return this->matrix[index];
}

/*
    Description: This matrix operator returns the "index"th row of matrix of an instance of
                 the Matrix class as a float pointer by overloading the operator "[]". This
                 is the constant version of the Matrix operator "[]".

    Arguments:
        index (unsigned int): The row of the matrix that is to be returned as a float pointer
    
    Returns: This operation returns the "index"th row of the matrix of a Matrix class instance
             as a float pointer.
*/
const float *Matrix::operator[](unsigned int index) const
{
    return this->matrix[index];
}

/*
    Description: This is the Insertion operator which allows the printing of elements, row by
                 row, of a matrix of a Matrix class instance by overloading the operator "<<".

    Arguments:
        out (ostream&): Reference to an output stream
        rhs (Matrix&): Reference to a Matrix class instance whose elements are to be printed
    
    Returns:
        out (ostream&): Reference to the output stream
*/
ostream &operator<<(ostream &out, const Matrix &rhs)
{
    for (int i = 0; i < rhs.rows; i++)
    {
        for (int j = 0; j < rhs.columns; j++)
        {
            if (j != rhs.columns - 1)
            {
                out << rhs.matrix[i][j] << " "; // printing elements (except last one) row by row
            }
            else
            {
                out << rhs.matrix[i][j]; // printing the last element of the rows
            }
        }
        if (i != rhs.rows - 1)
        {
            out << endl; // no new line at the end of printing of the last row
        }
    }
    return out;
}

/*
    Description: This is the Extraction operator which reads "rows" × "columns" space
                 separated elements from the input stream & then populates elements of the
                 matrix of a Matrix class instance, row by row, by overloading the operator ">>".

    Arguments:
        in (istream&): Reference to an input stream
        rhs (Matrix&): Reference to a Matrix class instance whose elements are to be populated
    
    Returns:
        in (istream&): Reference to the input stream
*/
istream &operator>>(istream &in, Matrix &rhs)
{
    for (int i = 0; i < rhs.rows; i++)
    {
        for (int j = 0; j < rhs.columns; j++)
        {
            in >> rhs.matrix[i][j]; // taking input as space seperated elements and populating them in the matrix of Matrix class instance rhs
        }
    }
    return in;
}