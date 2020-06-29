#include "poker_header.h"

int survivor = 5;
card Deck[52];
int top = 51;

void endGame(Player member[], int& gambler)
{
	checkCard(); //�ӽ� ���� �� �Լ�
	checkDie(member, gambler);
	suppleDeck(); // top = 51;
}

int checkCard()//�ӽ�
{
	return 0;
}

void suppleDeck()// �ӽ�
{
}

void checkDie(Player member[], int& gambler)
{
	int nowCheck = 0;
	for (int i = 0; i < survivor; i++)
	{
		while (member[nowCheck].checkSurvivor() == false)
		{
			nowCheck = (nowCheck + 1) % survivor;
		}

		if (member[nowCheck].getMoney() == 0)
		{
			member[nowCheck].retireGame();
		}
		else
		{
			resetGame(member[nowCheck]);
		}
	}
	gambler = survivor;
}

void resetGame(Player member)
{
	member.returnPlay();
	member.resetUsed();
}


void choiceBet(Player member[], int& gambler, int leader, int& totalBet)
{
	int nowBet = leader - 1, betMoney = 0, first = 0, dieMoney = 0;

	for (int i = 0; i < gambler; i++)
	{
		nowBet = (nowBet + 1) % survivor;

		while (member[nowBet].nowPlay() == false) //���� �÷��̾ �̹��� ���̸� ���� ���.
		{
			nowBet = (nowBet + 1) % survivor;
		}
		cout << "���� ���� : " << member[nowBet].getName() << endl;
		if (first == 0) //ù �� leader�� ���� �ٸ�.
		{
			betMoney = member[nowBet].leaderBet(totalBet, gambler);
			dieMoney = betMoney;
			while (betMoney == 0) //���� ������ ������ ���
			{
				if (gambler == 1) // �� ���� gambler�� ���� ���
					break;
				nowBet = (nowBet + 1) % survivor;
				while (member[nowBet].nowPlay() == false) //���� �÷��̾ �̹��� ���̸� ���� ���.
				{
					nowBet = (nowBet + 1) % survivor;
				}
				cout << "���� ���� : " << member[nowBet].getName() << endl;
				betMoney = member[nowBet].leaderBet(totalBet, gambler);
				dieMoney = betMoney;
			}
			first = 999;
		}
		else
		{
			if (member[nowBet].canBet(betMoney) == true) // �� �� �ɷ��� �ִ°� �Ǵ�
				choiceFollower(member, betMoney, totalBet, gambler, i, nowBet);

			else
				cant_Bet(member[nowBet], betMoney, gambler, totalBet);
		}
		cout << "��ü ���� �ݾ�: " << totalBet << endl << "���� ���� : " << betMoney << endl;
	}
	cout << "BetMoney : " << betMoney << endl;
	nowBet = 0;
	for (int j = 0; j < gambler; j++)
	{
		do {
			nowBet = (nowBet + 1) % survivor;
		} while (member[nowBet].nowPlay() == false);
		member[nowBet].payBet(betMoney);
	}

	betMoney = 0;
}

void choiceFollower(Player  member[], int& betMoney, int& totalBet, int& gambler, int& bet, int& nowBet)
{
	cout << "�ȷο� ���� : (1: ��, 2: ����, 3: ����, 4: ����, 5: ����) \n";
	int choice;
	cin >> choice; // �������̽������� ����

	switch (choice)
	{
	case 1: //��
		if (betMoney > member[nowBet].getMoney())
		{
			cout << "�ݾ��� ������� �ʽ��ϴ�.\n";
			choiceFollower(member, betMoney, totalBet, gambler, bet, nowBet);
		}
		else
			cout << "---------------------��---------------------\n";
		member[nowBet].call(betMoney, totalBet);
		break;
	case 2: //����
		member[nowBet].playerDie(gambler);
		cout << "---------------------�� ��---------------------\n";
		if (bet++ < gambler)
		{
			while (member[nowBet].nowPlay() == false) //���� �÷��̾ �̹��� ���̸� ���� ���.
			{
				nowBet = (nowBet + 1) % survivor;
			}
			cout << "���� ���� : " << member[nowBet].getName() << endl
				<< "��ü ���� �ݾ�: " << totalBet << endl
				<< "���� ���� : " << betMoney << endl;
			if (gambler == 1)
				cout << "�÷��̾� ����\n";
			else
				choiceFollower(member, betMoney, totalBet, gambler, bet, nowBet);
		}
		bet--;
		break;
	case 3: // ����, ���� �ݾ� ���� ��� ����

		if (betMoney * 2 <= member[nowBet].getMoney())
		{
			bet = 0; // ���� ���� ������� �ٽ� �ȷο�ó�� ���� ����
			cout << "---------------------����---------------------\n";
			member[nowBet].doubleBet(betMoney, totalBet);
		}
		else
		{
			cout << "�ݾ��� ������� �ʽ��ϴ�.\n";
			choiceFollower(member, betMoney, totalBet, gambler, bet, betMoney);
		}
		break;
	case 4: // ����
		if (betMoney > totalBet / 2)
		{
			cout << "������ ���� �ݾ׺��� �����ϴ�.\n";
			choiceFollower(member, betMoney, totalBet, gambler, bet, nowBet);
		}
		else if (member[nowBet].getMoney() < totalBet / 2)
		{
			cout << "���� ���� ���� �ǵ��� ������ ���� �ʽ��ϴ�.\n";
			choiceFollower(member, betMoney, totalBet, gambler, bet, nowBet);
		}
		else
		{
			cout << "---------------------����---------------------\n";
			member[nowBet].halfBet(betMoney, totalBet);
			bet = 0;
		}
		break;
	case 5: //All in
		bet = 0; // ���� ���� ������� �ٽ� �ȷο�ó�� ���� ����
		cout << "---------------------�� ��---------------------\n";
		member[nowBet].allMoney(betMoney, totalBet);
	}

}

void cant_Bet(Player& follwer, int& betMoney, int& gambler, int& totalBet)
{
	cout << "���� �Ұ��� ���� : (1. ����, 2. ����)\n";
	int choice;
	cin >> choice;

	switch (choice)
	{
	case 1: // ���� 
		cout << "---------------------�� ��---------------------\n";
		follwer.dieAllMoney(totalBet);
		break;
	case 2: // ����
		cout << "---------------------����---------------------\n";
		follwer.playerDie(gambler);
	}
}


card drawCard()
{
	// �ӽ� ����. �������� �� ��, �ּҸ� �ѱ��� ���.
	return Deck[top--];
}

void obliBet(Player member[], int& totalBet) // �ǹ� ����
{
	int obli = 3;

	for (int i = 0; i < survivor; i++)
	{
		member[i].payMoney(obli, totalBet);
		member[i].showMoney();

	}
	cout << "��ü ���� �ݾ� : " << totalBet << endl;
}



int choiceLeader(Player member[], const int gambler) // �պ�����
{
	int temp = member[0].getMoney(), leader = 0;

	for (int i = 1; i < gambler; i++)
	{
		if (member[i].getMoney() > temp)
		{
			temp = member[i].getMoney();
			leader = i;
		}
	}
	if (leader == survivor)
		leader = 0;

	return leader;
}

void reGame(Player member[], Player& dealer)
{
	char check;
	cout << "������ �׸��Ͻ÷��� N�� �Է��Ͻÿ� : ";
	cin >> check;

	if (check != 'n' && check != 'N')
		playGame(member, dealer);

}


void testPlayer(Player member[])
{
	for (int i = 0; i < 5; i++)
	{
		cout << "---------------" << member[i].getName() << "---------------\n"
			<< "Gaem Money : " << member[i].getMoney() << endl
			<< "Play check : " << member[i].checkPlayer() << endl
			<< "Survivor check : " << member[i].checkSurvivor() << endl
			<< "Used : " << member[i].returnUsed() << endl;
	}
}

void resultantPlate(Player member[])
{
	cout << "Game Set\n";
	cout << "Game Money : " << member[0].getMoney();
}

void playGame(Player member[], Player& dealer) // ���� ����
{

	int totalBet = 0, leader;
	int gambler = survivor;
	obliBet(member, totalBet);


	shuffle(member, dealer);

	picture(0, 0); // �ӽ�

	leader = choiceLeader(member, gambler); // ������ �� ���� ���ϸ� �������ʹ� ������ ����� ����

	for (int i = 0; i < 3; i++)
	{
		cout << member[i].getName() << "�� ����\n";
		choiceBet(member, gambler, leader, totalBet);
		if (gambler == 1)
			break;
		if (i != 2) {

			do
			{
				leader = (leader + 1) % survivor;

			} while (member[leader].checkPlayer() == false);
		}
		for (int j = 0; j < 5; j++)
			cout << member[j].getName() << "�� ���ӸӴ� : " << member[j].getMoney() << endl;
	}

	//endGame(member, gambler);

	testPlayer(member);

	//main����
	if (member[0].checkSurvivor() == false)
	{
		if (survivor != 1)
			reGame(member, dealer);
		else
			resultantPlate(member);
	}
	else
		resultantPlate(member);
}


//���� ��Ȳ - �ǹ� ���� ����, ī�� 2�� �ֱ� ����, ���� ī�� 3�� ����, ���� ���� ����, ���� ���� ����, �ȷο� ���� ����(���ܻ��� ������)
