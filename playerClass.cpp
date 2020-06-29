#include "poker_header.h"

extern int survivor;
extern int top;

Player::Player() : used(0), gameMoney(50), play(true), die(false)
{
	char* temp;
	temp = new char[20];
	name = temp;
}



void Player::showMoney() // ���� �÷��̾� �� Ȯ��
{
	cout << gameMoney << endl;
}

void Player::payMoney(int pay, int& totalBet) //ù �ǹ��� ����, ��
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

void Player::playerDie(int& gambler) 
{
	play = false;
	die = false;
	gambler--;
}

void Player::payBet(int betMoney)
{
	gameMoney = gameMoney - betMoney;
}

bool Player::checkPlayer()
{
	if (play == true)
		return true;
	else
		return false;
}

void Player::takeCard()
{
	cout << "ī�� ����\n"; //�ӽ�
	myCard[used++] = drawCard();
}

int Player::getMoney()
{
	return gameMoney;
}

int Player::inputBet(int &totalBet) // ���� ���� ���ؾ� ��.
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

int Player::leaderBet(int &totalMoney,int& gambler)
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

void Player::doubleBet(int& betMoney,int& totalBet)
{
	betMoney = betMoney * 2;
	//gameMoney = gameMoney - betMoney; //���
	totalBet = totalBet + betMoney;
}

void Player::allMoney(int& betMoney, int& totalBet)
{
	totalBet = totalBet - betMoney;
	betMoney = gameMoney;
	gameMoney = 0; //���
	totalBet = totalBet + betMoney;
	play = false;
}

bool Player::canBet(int betMoney) //������ �ɷ��� �ִ��� �Ǵ�
{
	if (betMoney > gameMoney)
		return false;
	else
		return true;
}

void Player::halfBet(int& betMoney, int& totalBet)
{
	totalBet = totalBet - betMoney;
	betMoney = totalBet / 2;
	//gameMoney = gameMoney - betMoney; //���
	totalBet = betMoney;
}

void Player::dieAllMoney(int& totalBet)
{
	totalBet = totalBet + gameMoney;
	gameMoney = 0; //���
	play = false;
}

bool Player::nowPlay()
{
	return play;
}

bool Player::checkSurvivor()
{
	if (die == true)
		return true;
	else
		return false;
}


string Player::getName()
{
	return name;
}

void Player::retireGame()
{
	die = true;
	play = false;
	survivor--;
}

void Player::returnPlay()
{
	play = true;
}

void Player::resetUsed()
{
	used = 0;
}

int Player::returnUsed()
{
	return used;
}

void Player::call(int& betMoney,int &totalMoney)
{
	totalMoney = totalMoney + betMoney;
}

Player::Player(string setN) : used(0), gameMoney(50), play(true), die(false)
{
	name = setN;
}

void Player::getCardSR(int R, int S, int num)
{
	for (int i = 0; i < num; i++)
		myCard[i].getSR(S, R);
}
void Player::getMax(int maxP, int maxN)
{
	maxPattern = maxP;
	maxNumber = maxN;
}