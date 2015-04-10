#include "stdafx.h"

#include "MoviesScheduler.h"

// Input data:

// Movie \ Janre table:
const int arrMovieJanre[]  =
{
	// Janre1  ...     JanreN
	1,	0,	1,	0,	0,	0,	0, // Movie1
	0,	1,	0,	1,	0,	0,	0, 
	1,	0,	1,	0,	1,	0,	0,
	0,	0,	0,	1,	1,	0,	1, // .
	0,	0,	1,	0,	0,	0,	0, // .
	1,	0,	0,	0,	1,	0,	0, // .
	0,	1,	1,	0,	0,	1,	0, // .
	0,	1,	1,	1,	0,	0,	0,
	0,	1,	0,	0,	0,	1,	0,
	0,	1,	0,	1,	0,	0,	0, // MovieN
};

// Hall \ Janre table:
const int arrHallJanre[]  =
{
	// Janre1  ...     JanreN
	1,	0,	0,	0,	0,	0,	0, // Hall1
	0,	1,	1,	0,	0,	0,	0, // .
	0,	0,	1,	0,	1,	0,	0, // .
	0,	1,	0,	1,	0,	1,	0, // .
	1,	0,	0,	0,	1,	1,	1, // HallN
};

const int janresCount = 7;
const int hallsCount = 5;
const int moviesCount = 10;



//  App entry point

int _tmain(int argc, _TCHAR* argv[])
{
	//Init matrix classes
	QSMatrix<int> matrixMovieJanre(moviesCount, janresCount, arrMovieJanre);
	QSMatrix<int> matrixHallJanre(hallsCount, janresCount, arrHallJanre);


	// Print input data
	std::cout	<< "Input data: \n"
				<< "---------------------\n\n"	
				<< "Movies and Janres - Catalog:\n";

	CMoviesScheduler::PrintTable(matrixMovieJanre, "Movie", "Janre");

	std::cout << "Halls and Janres available to them:\n";

	CMoviesScheduler::PrintTable(matrixHallJanre, "Hall", "Janre");


	// Calculate and print schedule
	QSMatrix<int> matrixMovieHallSchedule =	CMoviesScheduler::CreateScheduleMatrix(matrixMovieJanre, matrixHallJanre);


	std::cout	<< "\nOutput:\n"
				<< "---------------------\n\n"		
				<< "Movies day schedule for halls:\n";

	CMoviesScheduler::PrintTable(matrixMovieHallSchedule, "Movie", "Hall");

	return 0;
}
