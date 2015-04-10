#pragma once

#include "matrix_tools/matrix.h" // QSMatrix sources taken here http://www.quantstart.com/articles/Matrix-Classes-in-C-The-Source-File

#include <iostream>
#include <iomanip>

class CMoviesScheduler {
public:
	static QSMatrix<int> CreateScheduleMatrix(QSMatrix<int>& matrixMovieJanre, QSMatrix<int>& matrixHallJanre);
	static void PrintTable(QSMatrix<int>& matrix, const char* rowsName, const char* colsName);

};