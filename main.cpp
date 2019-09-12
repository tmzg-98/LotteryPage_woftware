#undef main

#include "LotteryPage.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	LotteryPage w;
	w.show();
	return a.exec();
}
