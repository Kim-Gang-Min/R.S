#include "poker_header.h"

extern int survivor;
extern int top;

Player::Player() : used(0), gameMoney(50), play(true), die(false)
{
	char* temp;
	temp = new char[20];
	name = temp;
}



void Player::showMoney() // 남은 플레이어 돈 확인
{
	cout << gameMoney << endl;
}

void Player::payMoney(int pay, int& totalBet) //첫 의무돈 지불, 콜
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
	cout << "카드 받음\n"; //임시
	myCard[used++] = drawCard();
}

int Player::getMoney()
{
	return gameMoney;
}

int Player::inputBet(int &totalBet) // 베팅 범위 정해야 함.
{
	int betMoney;
	cin >> betMoney;
	while (betMoney > gameMoney || betMoney < 0)
	{
		cout << "배팅 금액 범위 초과, 다시 입력\n배팅 금액 : ";
		cin >> betMoney;
	}

	totalBet = totalBet + betMoney;
	//gameMoney = gameMoney - betMoney; // 고려

	return betMoney;
}

int Player::leaderBet(int &totalMoney,int& gambler)
{
	cout << "리더 배팅 (1: 배팅, 2: 다이)\n";//임시
	int choice, betMoney;
	cin >> choice;

	switch (choice)
	{
	case 1:
		cout << "---------------------배팅---------------------\n";
		cout << "배팅 금액 : "; //임시
		betMoney = inputBet(totalMoney);
		return betMoney;
	case 2:
		cout << "---------------------다 이---------------------\n";
		playerDie(gambler);
		return 0;
	}
}

void Player::doubleBet(int& betMoney,int& totalBet)
{
	betMoney = betMoney * 2;
	//gameMoney = gameMoney - betMoney; //고려
	totalBet = totalBet + betMoney;
}

void Player::allMoney(int& betMoney, int& totalBet)
{
	totalBet = totalBet - betMoney;
	betMoney = gameMoney;
	gameMoney = 0; //고려
	totalBet = totalBet + betMoney;
	play = false;
}

bool Player::canBet(int betMoney) //배팅할 능력이 있는지 판단
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
	//gameMoney = gameMoney - betMoney; //고려
	totalBet = betMoney;
}

void Player::dieAllMoney(int& totalBet)
{
	totalBet = totalBet + gameMoney;
	gameMoney = 0; //고려
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