
#include "stdafx.h"

#include "MoviesScheduler.h"


QSMatrix<int> CMoviesScheduler::CreateScheduleMatrix( QSMatrix<int>& matrixMovieJanre, QSMatrix<int>& matrixHallJanre )
{
	// Schedule matrix is product of matrix multiplication: MovieJanre * transpose(HallJanre)
	
	QSMatrix<int> matrixJanreHall = matrixHallJanre.transpose();
	return matrixMovieJanre*matrixJanreHall;
}

void CMoviesScheduler::PrintTable( QSMatrix<int>& matrix, const char* rowsName, const char* colsName )
{
	std::cout <<  "\n" << rowsName << " \\  " << colsName << "\n" ;
	std::cout <<  "      |" ;

	for (int i=1; i<=matrix.get_cols(); ++i) {
		std::cout <<  "   " << i;
	}

	std::cout <<  "\n";

	std::cout <<  "      *-------------------------------\n" ;

	for (unsigned row=0; row < matrix.get_rows(); ++row) {
		std::cout << std::setw(3) << row+1 << "   |   ";
		for (unsigned col=0; col < matrix.get_cols(); ++col) {
			std::cout << ((matrix(row,col) != 0) ? "x" : ".") << "   ";
		}
		std::cout << "\n";
	}

	std::cout << "\n";
}
