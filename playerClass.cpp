#include "poker_header.h"

extern int survivor;
extern int top;

player::player() : used(0), gameMoney(50), play(true), die(false)
{
	char* temp;
	temp = new char[20];
	name = temp;
}

ostream& operator<< (ostream& a, const card& thiscard) // ���� ���
{
	a << thiscard.pat << thiscard.cardNumber;

	return a;
}

void player::showMoney() // ���� �÷��̾� �� Ȯ��
{
	cout << gameMoney << endl;
}

void player::payMoney(int pay, int& totalBet) //ù �ǹ��� ����, ��
{
	if (pay >= gameMoney)
	{
		gameMoney = 0;
		totalBet = totalBet + gameMoney;
		play = false;
	}

	else
	{
		gameMoney = gameMoney - pay;
		totalBet = totalBet + pay;
	}
}

void player::playerDie(int& gambler) 
{
	play = false;
	die = false;
	gambler--;
}

void player::getCard(card newCard1, card newCard2)
{
	cout << "ī�� 2�� ��ο�\n"; // �ӽ�
	myCard[0] = newCard1;
	myCard[1] = newCard2;
}

void player::payBet(int betMoney)
{
	gameMoney = gameMoney - betMoney;
}

bool player::checkPlayer()
{
	if (play == true)
		return true;
	else
		return false;
}

void player::takeCard()
{
	cout << "ī�� ����\n"; //�ӽ�
	myCard[used++] = drawCard();
}

int player::getMoney()
{
	return gameMoney;
}

int player::inputBet(int &totalBet) // ���� ���� ���ؾ� ��.
{
	int betMoney;
	cin >> betMoney;
	while (betMoney > gameMoney || betMoney < 0)
	{
		cout << "���� �ݾ� ���� �ʰ�, �ٽ� �Է�\n���� �ݾ� : ";
		cin >> betMoney;
	}

	totalBet = totalBet + betMoney;
	//gameMoney = gameMoney - betMoney; // ���

	return betMoney;
}

int player::leaderBet(int &totalMoney,int& gambler)
{
	cout << "���� ���� (1: ����, 2: ����)\n";//�ӽ�
	int choice, betMoney;
	cin >> choice;

	switch (choice)
	{
	case 1:
		cout << "---------------------����---------------------\n";
		cout << "���� �ݾ� : "; //�ӽ�
		betMoney = inputBet(totalMoney);
		return betMoney;
	case 2:
		cout << "---------------------�� ��---------------------\n";
		playerDie(gambler);
		return 0;
	}
}

void player::doubleBet(int& betMoney,int& totalBet)
{
	betMoney = betMoney * 2;
	//gameMoney = gameMoney - betMoney; //���
	totalBet = totalBet + betMoney;
}

void player::allMoney(int& betMoney, int& totalBet)
{
	totalBet = totalBet - betMoney;
	betMoney = gameMoney;
	gameMoney = 0; //���
	totalBet = totalBet + betMoney;
	play = false;
}

bool player::canBet(int betMoney) //������ �ɷ��� �ִ��� �Ǵ�
{
	if (betMoney > gameMoney)
		return false;
	else
		return true;
}

void player::halfBet(int& betMoney, int& totalBet)
{
	totalBet = totalBet - betMoney;
	betMoney = totalBet / 2;
	//gameMoney = gameMoney - betMoney; //���
	totalBet = betMoney;
}

void player::dieAllMoney(int& totalBet)
{
	totalBet = totalBet + gameMoney;
	gameMoney = 0; //���
	play = false;
}

bool player::nowPlay()
{
	return play;
}

bool player::checkSurvivor()
{
	if (die == true)
		return true;
	else
		return false;
}

void player::setName(string setN)
{
	name = setN;
}


string player::getName()
{
	return name;
}

void player::retireGame()
{
	die = true;
	play = false;
	survivor--;
}

void player::returnPlay()
{
	play = true;
}

void player::resetUsed()
{
	used = 0;
}

int player::returnUsed()
{
	return used;
}

void player::call(int& betMoney,int &totalMoney)
{
	totalMoney = totalMoney + betMoney;
}