#include "LotteryPage.h"
#include <QTimer>
#include <QString>
#include <cstdlib>
#include <ctime>
#include <QDebug>
#define INTERVAL 80
#define MOD 5000

#define SPCONNECT(index) connect(SecondPrizeTimer[index], SIGNAL(timeout()), this, SLOT(SecondPrizeSlot_##index##()))
#define SECONDSLOT(index) void LotteryPage::SecondPrizeSlot_##index##() {int num=RAND()%MOD+1;ui.SecondPrizelineEdit_##index##->setText(QString::number(num,10));} 
#define SPB(index) void LotteryPage::on_SecondPrizeBtn_##index##_clicked() {SecondPrizeTimer[index]->start();}

#define RDCONNECT(index) connect(ThirdPrizeTimer_Page1[index], SIGNAL(timeout()), this, SLOT(RdPrzSlt_##index##()))
#define RDSLT(index) void LotteryPage::RdPrzSlt_##index##() {ui.RdPrzLE_##index##->setText(QString::number(RAND()%MOD+1,10));}
//#define RDB(index) void LotteryPage::on_RdPrzBtn_##index##_clicked() {ThirdPrizeTimer_Page1[index]->start();}

#define RD2CONNECT(index) connect(ThirdPrizeTimer_Page2[index], SIGNAL(timeout()), this, SLOT(RdPrzSlt2_##index##()));
#define RDSLT2(index) void LotteryPage::RdPrzSlt2_##index##() {ui.RdPrzLE2_##index##->setText(QString::number(RAND()%MOD+1,10));}

#define LKCONNECT(index) connect(LuckyPrizeTimer_Page1[index], SIGNAL(timeout()), this, SLOT(LkPrzSlt_##index##()));
#define LKSLT(index) void LotteryPage::LkPrzSlt_##index##() {ui.LkPrzLE_##index##->setText(QString::number(RAND()%MOD+1,10));}

#define LK2CONNECT(index) connect(LuckyPrizeTimer_Page2[index], SIGNAL(timeout()), this, SLOT(LkPrzSlt2_##index##()));
#define LKSLT2(index) void LotteryPage::LkPrzSlt2_##index##() {ui.LkPrzLE2_##index##->setText(QString::number(RAND()%MOD+1,10));}

#define LK3CONNECT(index) connect(LuckyPrizeTimer_Page3[index], SIGNAL(timeout()), this, SLOT(LkPrzSlt3_##index##()));
#define LKSLT3(index) void LotteryPage::LkPrzSlt3_##index##() {ui.LkPrzLE3_##index##->setText(QString::number(RAND()%MOD+1,10));}

#define SETEXT(index) ui.SecondPrizelineEdit_##index##->text();
#define RDTEXT(index) ui.RdPrzLE_##index##->text();
#define RD2TEXT(index) ui.RdPrzLE2_##index##->text();
#define LKTEXT(index) ui.LkPrzLE_##index##->text();
#define LK2TEXT(index) ui.LkPrzLE2_##index##->text();
#define LK3TEXT(index) ui.LkPrzLE3_##index##->text();

bool vis[MOD + 10];

int RAND()
{
	int num = rand() % MOD + 1;
	while (1)
	{
		if (!vis[num]) break;
		else num = rand() % MOD + 1;
	}
	return num;
}

LotteryPage::LotteryPage(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	srand(time(0));

	FirstPrizeTimer = new QTimer(this);
	connect(FirstPrizeTimer, SIGNAL(timeout()), this, SLOT(FirstPrizeSlot()));

	for (int i = 0; i < 6; i++) SecondPrizeTimer[i] = new QTimer(this);
	/*connect(SecondPrizeTimer[0], SIGNAL(timeout()), this, SLOT(SecondPrizeSlot_0()));
	connect(SecondPrizeTimer[1], SIGNAL(timeout()), this, SLOT(SecondPrizeSlot_1()));
	connect(SecondPrizeTimer[2], SIGNAL(timeout()), this, SLOT(SecondPrizeSlot_2()));
	connect(SecondPrizeTimer[3], SIGNAL(timeout()), this, SLOT(SecondPrizeSlot_3()));
	connect(SecondPrizeTimer[4], SIGNAL(timeout()), this, SLOT(SecondPrizeSlot_4()));
	connect(SecondPrizeTimer[5], SIGNAL(timeout()), this, SLOT(SecondPrizeSlot_5()));*/
	SPCONNECT(0);
	SPCONNECT(1);
	SPCONNECT(2);
	SPCONNECT(3);
	SPCONNECT(4);
	SPCONNECT(5);

	for (int i = 0; i < 15; i++) ThirdPrizeTimer_Page1[i] = new QTimer(this);
	RDCONNECT(0); RDCONNECT(1); RDCONNECT(2); RDCONNECT(3); RDCONNECT(4);
	RDCONNECT(5); RDCONNECT(6); RDCONNECT(7); RDCONNECT(8); RDCONNECT(9);
	RDCONNECT(10); RDCONNECT(11); RDCONNECT(12); RDCONNECT(13); RDCONNECT(14);

	for (int i = 0; i < 15; i++) ThirdPrizeTimer_Page2[i] = new QTimer(this);
	RD2CONNECT(0); RD2CONNECT(1); RD2CONNECT(2); RD2CONNECT(3); RD2CONNECT(4);
	RD2CONNECT(5); RD2CONNECT(6); RD2CONNECT(7); RD2CONNECT(8); RD2CONNECT(9);
	RD2CONNECT(10); RD2CONNECT(11); RD2CONNECT(12); RD2CONNECT(13); RD2CONNECT(14);

	for (int i = 0; i < 20; i++) LuckyPrizeTimer_Page1[i] = new QTimer(this);
	LKCONNECT(0); LKCONNECT(1); LKCONNECT(2); LKCONNECT(3); LKCONNECT(4);
	LKCONNECT(5); LKCONNECT(6); LKCONNECT(7); LKCONNECT(8); LKCONNECT(9);
	LKCONNECT(10); LKCONNECT(11); LKCONNECT(12); LKCONNECT(13); LKCONNECT(14);
	LKCONNECT(15); LKCONNECT(16); LKCONNECT(17); LKCONNECT(18); LKCONNECT(19);

	for (int i = 0; i < 20; i++) LuckyPrizeTimer_Page2[i] = new QTimer(this);
	LK2CONNECT(0); LK2CONNECT(1); LK2CONNECT(2); LK2CONNECT(3); LK2CONNECT(4);
	LK2CONNECT(5); LK2CONNECT(6); LK2CONNECT(7); LK2CONNECT(8); LK2CONNECT(9);
	LK2CONNECT(10); LK2CONNECT(11); LK2CONNECT(12); LK2CONNECT(13); LK2CONNECT(14);
	LK2CONNECT(15); LK2CONNECT(16); LK2CONNECT(17); LK2CONNECT(18); LK2CONNECT(19);

	for (int i = 0; i < 20; i++) LuckyPrizeTimer_Page3[i] = new QTimer(this);
	LK3CONNECT(0); LK3CONNECT(1); LK3CONNECT(2); LK3CONNECT(3); LK3CONNECT(4);
	LK3CONNECT(5); LK3CONNECT(6); LK3CONNECT(7); LK3CONNECT(8); LK3CONNECT(9);
	LK3CONNECT(10); LK3CONNECT(11); LK3CONNECT(12); LK3CONNECT(13); LK3CONNECT(14); 
	LK3CONNECT(15); LK3CONNECT(16); LK3CONNECT(17); LK3CONNECT(18); LK3CONNECT(19); 

	ui.m_pStackWidget->setCurrentIndex(3);//Ä¬ÈÏµ½ÐÒÔË½±
}
void LotteryPage::on_FirstPrize_clicked() { ui.m_pStackWidget->setCurrentIndex(0); }
void LotteryPage::on_SecondPrize_clicked() { ui.m_pStackWidget->setCurrentIndex(1); }
void LotteryPage::on_ThirdPrize_clicked() { ui.m_pStackWidget->setCurrentIndex(2); }
void LotteryPage::on_ThirdPrize_2_clicked() { ui.m_pStackWidget->setCurrentIndex(4);  };
void LotteryPage::on_LuckyPrize_clicked() { ui.m_pStackWidget->setCurrentIndex(3); }
void LotteryPage::on_LuckyPrize_2_clicked() { ui.m_pStackWidget->setCurrentIndex(5); }
void LotteryPage::on_LuckyPrize_3_clicked() { ui.m_pStackWidget->setCurrentIndex(6); }
void LotteryPage::on_Start_clicked()
{
	int current_index = ui.m_pStackWidget->currentIndex();
	switch (current_index)
	{
	case 0:
		FirstPrizeTimer->start();
		break;
	case 1:
		for(int i = 0; i < 6; i++) SecondPrizeTimer[i]->start();
		break;
	case 2:
		for (int i = 0; i < 15; i++) ThirdPrizeTimer_Page1[i]->start();
		break;
	case 3:
		for (int i = 0; i < 20; i++) LuckyPrizeTimer_Page1[i]->start();
		break;
	case 4:
		for (int i = 0; i < 15; i++) ThirdPrizeTimer_Page2[i]->start();
		break;
	case 5:
		for (int i = 0; i < 20; i++) LuckyPrizeTimer_Page2[i]->start();
		break;
	case 6:
		for (int i = 0; i < 20; i++) LuckyPrizeTimer_Page3[i]->start();
		break;
	}
}
void LotteryPage::on_Pause_clicked()
{
	int current_index = ui.m_pStackWidget->currentIndex();
	QString str;
	switch (current_index)
	{
	case 0:
		FirstPrizeTimer->stop();
		str = ui.lineEdit->text();
		vis[str.toInt()] = true;
		break;
	case 1:
		for (int i = 0; i < 6; i++)
		{
			SecondPrizeTimer[i]->stop();
			switch (i)//qu chong
			{
				case 0: str = SETEXT(0);break;
				case 1: str = SETEXT(1);break;
				case 2: str = SETEXT(2);break;
				case 3: str = SETEXT(3);break;
				case 4: str = SETEXT(4);break;
				case 5: str = SETEXT(5);break;
			}
			vis[str.toInt()] = true;
		}
		break;
	case 2:
		for (int i = 0; i < 15; i++)
		{
			ThirdPrizeTimer_Page1[i]->stop();
			switch (i)
			{
			case 0: str = RDTEXT(0); break;
			case 1: str = RDTEXT(1); break;
			case 2: str = RDTEXT(2); break;
			case 3: str = RDTEXT(3); break;
			case 4: str = RDTEXT(4); break;
			case 5: str = RDTEXT(5); break;
			case 6: str = RDTEXT(6); break;
			case 7: str = RDTEXT(7); break;
			case 8: str = RDTEXT(8); break;
			case 9: str = RDTEXT(9); break;
			case 10: str = RDTEXT(10); break;
			case 11: str = RDTEXT(11); break;
			case 12: str = RDTEXT(12); break;
			case 13: str = RDTEXT(13); break;
			case 14: str = RDTEXT(14); break;
			}
			vis[str.toInt()] = true;
		}
		break;
	case 3:
		for (int i = 0; i < 20; i++)
		{
			LuckyPrizeTimer_Page1[i]->stop();
			switch (i)
			{
			case 0: str = LKTEXT(0); break;
			case 1: str = LKTEXT(1); break;
			case 2: str = LKTEXT(2); break;
			case 3: str = LKTEXT(3); break;
			case 4: str = LKTEXT(4); break;
			case 5: str = LKTEXT(5); break;
			case 6: str = LKTEXT(6); break;
			case 7: str = LKTEXT(7); break;
			case 8: str = LKTEXT(8); break;
			case 9: str = LKTEXT(9); break;
			case 10: str = LKTEXT(10); break;
			case 11: str = LKTEXT(11); break;
			case 12: str = LKTEXT(12); break;
			case 13: str = LKTEXT(13); break;
			case 14: str = LKTEXT(14); break;
			case 15: str = LKTEXT(15); break;
			case 16: str = LKTEXT(16); break;
			case 17: str = LKTEXT(17); break;
			case 18: str = LKTEXT(18); break;
			case 19: str = LKTEXT(19); break;
			}
			vis[str.toInt()] = true;
		}
		break;
	case 4:
		for (int i = 0; i < 15; i++)
		{
			ThirdPrizeTimer_Page2[i]->stop();
			switch (i)
			{
			case 0: str = RD2TEXT(0); break;
			case 1: str = RD2TEXT(1); break;
			case 2: str = RD2TEXT(2); break;
			case 3: str = RD2TEXT(3); break;
			case 4: str = RD2TEXT(4); break;
			case 5: str = RD2TEXT(5); break;
			case 6: str = RD2TEXT(6); break;
			case 7: str = RD2TEXT(7); break;
			case 8: str = RD2TEXT(8); break;
			case 9: str = RD2TEXT(9); break;
			case 10: str = RD2TEXT(10); break;
			case 11: str = RD2TEXT(11); break;
			case 12: str = RD2TEXT(12); break;
			case 13: str = RD2TEXT(13); break;
			case 14: str = RD2TEXT(14); break;
			}
			vis[str.toInt()] = true;
		}
		break;
	case 5:
		for (int i = 0; i < 20; i++)
		{
			LuckyPrizeTimer_Page2[i]->stop();
			switch (i)
			{
			case 0: str = LK2TEXT(0); break;
			case 1: str = LK2TEXT(1); break;
			case 2: str = LK2TEXT(2); break;
			case 3: str = LK2TEXT(3); break;
			case 4: str = LK2TEXT(4); break;
			case 5: str = LK2TEXT(5); break;
			case 6: str = LK2TEXT(6); break;
			case 7: str = LK2TEXT(7); break;
			case 8: str = LK2TEXT(8); break;
			case 9: str = LK2TEXT(9); break;
			case 10: str = LK2TEXT(10); break;
			case 11: str = LK2TEXT(11); break;
			case 12: str = LK2TEXT(12); break;
			case 13: str = LK2TEXT(13); break;
			case 14: str = LK2TEXT(14); break;
			case 15: str = LK2TEXT(15); break;
			case 16: str = LK2TEXT(16); break;
			case 17: str = LK2TEXT(17); break;
			case 18: str = LK2TEXT(18); break;
			case 19: str = LK2TEXT(19); break;
			}
			vis[str.toInt()] = true;
		}
		break;
	case 6:
		for (int i = 0; i < 20; i++)
		{
			LuckyPrizeTimer_Page3[i]->stop();
			switch (i)
			{
			case 0: str = LK3TEXT(0); break;
			case 1: str = LK3TEXT(1); break;
			case 2: str = LK3TEXT(2); break;
			case 3: str = LK3TEXT(3); break;
			case 4: str = LK3TEXT(4); break;
			case 5: str = LK3TEXT(5); break;
			case 6: str = LK3TEXT(6); break;
			case 7: str = LK3TEXT(7); break;
			case 8: str = LK3TEXT(8); break;
			case 9: str = LK3TEXT(9); break;
			case 10: str = LK3TEXT(10); break;
			case 11: str = LK3TEXT(11); break;
			case 12: str = LK3TEXT(12); break;
			case 13: str = LK3TEXT(13); break;
			case 14: str = LK3TEXT(14); break;
			case 15: str = LK3TEXT(15); break;
			case 16: str = LK3TEXT(16); break;
			case 17: str = LK3TEXT(17); break;
			case 18: str = LK3TEXT(18); break;
			case 19: str = LK3TEXT(19); break;
			}
			vis[str.toInt()] = true;
		}
		break;
	}
}
void LotteryPage::FirstPrizeSlot()
{
	int num = RAND() % MOD + 1;
	ui.lineEdit->setText(QString::number(num));
}
/*void LotteryPage::SecondPrizeSlot_0() { ui.SecondPrizelineEdit_0->setText(QString::number(RAND() % 5000 + 1, 10)); } 
void LotteryPage::SecondPrizeSlot_1() { ui.SecondPrizelineEdit_1->setText(QString::number(RAND() % 5000 + 1, 10)); }
void LotteryPage::SecondPrizeSlot_2() { ui.SecondPrizelineEdit_2->setText(QString::number(RAND() % 5000 + 1, 10)); }
void LotteryPage::SecondPrizeSlot_3() { ui.SecondPrizelineEdit_3->setText(QString::number(RAND() % 5000 + 1, 10)); }
void LotteryPage::SecondPrizeSlot_4() { ui.SecondPrizelineEdit_4->setText(QString::number(RAND() % 5000 + 1, 10)); }
void LotteryPage::SecondPrizeSlot_5() { ui.SecondPrizelineEdit_5->setText(QString::number(RAND() % 5000 + 1, 10)); }*/
SECONDSLOT(0) SECONDSLOT(1) SECONDSLOT(2) SECONDSLOT(3) SECONDSLOT(4) SECONDSLOT(5)
SPB(0) SPB(1) SPB(2) SPB(3) SPB(4) SPB(5)

RDSLT(0) RDSLT(1) RDSLT(2) RDSLT(3) RDSLT(4)
RDSLT(5) RDSLT(6) RDSLT(7) RDSLT(8) RDSLT(9)
RDSLT(10) RDSLT(11) RDSLT(12) RDSLT(13) RDSLT(14)

RDSLT2(0) RDSLT2(1) RDSLT2(2) RDSLT2(3) RDSLT2(4)
RDSLT2(5) RDSLT2(6) RDSLT2(7) RDSLT2(8) RDSLT2(9)
RDSLT2(10) RDSLT2(11) RDSLT2(12) RDSLT2(13) RDSLT2(14)

LKSLT(0) LKSLT(1) LKSLT(2) LKSLT(3) LKSLT(4)
LKSLT(5) LKSLT(6) LKSLT(7) LKSLT(8) LKSLT(9)
LKSLT(10) LKSLT(11) LKSLT(12) LKSLT(13) LKSLT(14)
LKSLT(15) LKSLT(16) LKSLT(17) LKSLT(18) LKSLT(19)

LKSLT2(0) LKSLT2(1) LKSLT2(2) LKSLT2(3) LKSLT2(4)
LKSLT2(5) LKSLT2(6) LKSLT2(7) LKSLT2(8) LKSLT2(9)
LKSLT2(10) LKSLT2(11) LKSLT2(12) LKSLT2(13) LKSLT2(14)
LKSLT2(15) LKSLT2(16) LKSLT2(17) LKSLT2(18) LKSLT2(19)

LKSLT3(0) LKSLT3(1) LKSLT3(2) LKSLT3(3) LKSLT3(4)
LKSLT3(5) LKSLT3(6) LKSLT3(7) LKSLT3(8) LKSLT3(9)
LKSLT3(10) LKSLT3(11) LKSLT3(12) LKSLT3(13) LKSLT3(14) 
LKSLT3(15) LKSLT3(16) LKSLT3(17) LKSLT3(18) LKSLT3(19)
/*RDB(0) RDB(1) RDB(2) RDB(3) RDB(4)
RDB(5) RDB(6) RDB(7) RDB(8) RDB(9)
RDB(10) RDB(11) RDB(12) RDB(13) RDB(14)*/
