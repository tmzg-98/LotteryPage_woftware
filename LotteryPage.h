#pragma once

#include <QtWidgets/QMainWindow>
#include <QStackedWidget>
#include "ui_LotteryPage.h"
#include <QTimer>

#define SPB(index) void on_SecondPrizeBtn_##index##_clicked()
#define RDSLT(index) void RdPrzSlt_##index##()
#define RDB(index) void on_RdPrzBtn_##index##_clicked()

#define RDSLT2(index) void RdPrzSlt2_##index##()

#define LKSLT(index) void LkPrzSlt_##index##()

#define LKSLT2(index) void LkPrzSlt2_##index##()

#define LKSLT3(index) void LkPrzSlt3_##index##()

class LotteryPage : public QMainWindow
{
	Q_OBJECT

public:
	LotteryPage(QWidget *parent = Q_NULLPTR);
private:
	Ui::LotteryPageClass ui;
	QTimer *FirstPrizeTimer;
	QTimer *SecondPrizeTimer[6];
	QTimer *ThirdPrizeTimer_Page1[15];
	QTimer *ThirdPrizeTimer_Page2[15];
	QTimer *LuckyPrizeTimer_Page1[20];
	QTimer *LuckyPrizeTimer_Page2[20];
	QTimer *LuckyPrizeTimer_Page3[20];
private slots:
	void on_LuckyPrize_clicked();
	void on_LuckyPrize_2_clicked();
	void on_LuckyPrize_3_clicked();
	void on_FirstPrize_clicked();
	void on_SecondPrize_clicked();
	void on_ThirdPrize_clicked();
	void on_ThirdPrize_2_clicked();
	void on_Start_clicked();
	void on_Pause_clicked();
	void FirstPrizeSlot();
	void SecondPrizeSlot_0();
	void SecondPrizeSlot_1();
	void SecondPrizeSlot_2();
	void SecondPrizeSlot_3();
	void SecondPrizeSlot_4();
	void SecondPrizeSlot_5();
	SPB(0); SPB(1); SPB(2); SPB(3); SPB(4); SPB(5);
	RDSLT(0);	RDSLT(1);	RDSLT(2);	RDSLT(3);	RDSLT(4);
	RDSLT(5);	RDSLT(6);	RDSLT(7);	RDSLT(8);	RDSLT(9);
	RDSLT(10);	RDSLT(11);	RDSLT(12);	RDSLT(13);	RDSLT(14);
	/*RDB(0);	RDB(1);	RDB(2);	RDB(3);	RDB(4);
	RDB(5);	RDB(6);	RDB(7);	RDB(8);	RDB(9);	
	RDB(10);	RDB(11);	RDB(12);	RDB(13);	RDB(14);*/
	RDSLT2(0); RDSLT2(1); RDSLT2(2); RDSLT2(3); RDSLT2(4);
	RDSLT2(5); RDSLT2(6); RDSLT2(7); RDSLT2(8); RDSLT2(9);
	RDSLT2(10); RDSLT2(11); RDSLT2(12); RDSLT2(13); RDSLT2(14);

	LKSLT(0); LKSLT(1); LKSLT(2); LKSLT(3); LKSLT(4);
	LKSLT(5); LKSLT(6); LKSLT(7); LKSLT(8); LKSLT(9);
	LKSLT(10); LKSLT(11); LKSLT(12); LKSLT(13); LKSLT(14);
	LKSLT(15); LKSLT(16); LKSLT(17); LKSLT(18); LKSLT(19);

	LKSLT2(0); LKSLT2(1); LKSLT2(2); LKSLT2(3); LKSLT2(4);
	LKSLT2(5); LKSLT2(6); LKSLT2(7); LKSLT2(8); LKSLT2(9);
	LKSLT2(10); LKSLT2(11); LKSLT2(12); LKSLT2(13); LKSLT2(14);
	LKSLT2(15); LKSLT2(16); LKSLT2(17); LKSLT2(18); LKSLT2(19);

	LKSLT3(0); LKSLT3(1); LKSLT3(2); LKSLT3(3); LKSLT3(4);
	LKSLT3(5); LKSLT3(6); LKSLT3(7); LKSLT3(8); LKSLT3(9);
	LKSLT3(10); LKSLT3(11); LKSLT3(12); LKSLT3(13); LKSLT3(14);
	LKSLT3(15); LKSLT3(16); LKSLT3(17); LKSLT3(18); LKSLT3(19);
};
