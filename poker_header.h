#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75
#define CHOICE 13

const char shape[5][10] = { "zero", "spade", "diamonds", "cluber", "heart" };
const char num1ber[14][7] = { "zero","two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "jack", "queen", "king", "ace" };

enum Color  //콘솔에서 사용하는 색상
{
	BLACK, BLUE, GREEN, CYAN,
	RED, MAGENTA, BROWN, LIGHTGRAY,
	DARKGRAY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN,
	LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE
};

class card {
public:
	void getSR(int S1, int R);
private:
	int R; //숫자
	int S; //문양

};

class Player {
public:
	Player();
	Player(string setN);
	void payMoney(int pay, int& totalBet);
	void showMoney();
	bool checkPlayer(); //살아있는 플레이어 체크
	void takeCard();
	int getMoney();
	int inputBet(int& totalBet); // 리더의 배팅 금액 입력.
	void playerDie(int& gambler); // play가 false로 바뀜.
	int leaderBet(int& totalMoney, int& gamlber);
	void doubleBet(int& betMoney, int& totalBet);
	void allMoney(int& betMoney, int& totalBet);
	bool canBet(int betMoney);
	void halfBet(int& betMoney, int& totalBet);
	void dieAllMoney(int& totalMoney);
	bool nowPlay();
	bool checkSurvivor();
	void payBet(int betMoney);
	string getName();
	void retireGame();
	void returnPlay();
	void resetUsed();
	int returnUsed();
	void call(int& betMoney, int& totalMoney);
	void getCardSR(int R, int S, int num);
	void getMax(int maxP, int maxN);
protected:
	int used; // 받은 카드 갯수
	int gameMoney;
	card myCard[5]; // 딜러 때문에 크기 5로 변경
	bool play; //이번 판 플레이가 제한된 경우 false로 변경
	bool die; //이번판 아웃된 경우
	string name;
	int maxPattern; //max pattern
	int maxNumber; //max number
};

//-----------------------이도영
void setColor(int back, int text);
void init();
void gotoxy(int x, int y);
void introGame(); // 게임 시작화면 함수
int keyControl(); // 방향키로 메뉴 선택 함수
int menuChoice(); // 시작화면 메뉴 선택 함수
void gameImage(); // 게임화면 이미지 출력 함수
void gameRule(); // 게임 룰 화면 함수
void player(int x, int y); // 컴퓨터 플레이어 이미지 출력 함수
void bettingNumber(); // 베팅 메뉴 선택 함수
void bettingPrint(int x); // 베팅 문자 출력 
int bettingMenuChoice(); // 베팅 메뉴 이름 출력 함수
void victoryPrint(); // 승리 시 화면 출력
void defeatPrint();  // 패배 시 화면 출력
void picture(int* num1_rand, int* shape_rand); //공유 카드 구성 함수
void playerCard(int x, int y);
void printOrder(int, int);

//-------------------------- 김강민
card drawCard(); // (임시)카드 뽑기
void obliBet(Player member[], int& totalBet);
void playGame(Player member[], Player& gambler);
int checkCard();
void choiceBet(Player member[], int& gambler, int leader, int& totalBet);
int choiceLeader(Player member[], const int gambler); // 가장 금액 높은 사람이 첫 배팅 리더
void choiceFollower(Player member[], int& betMoney, int& totalBet, int& gambler, int& bet, int& nowBet);
void cant_Bet(Player& follwer, int& betMoney, int& gambler, int& totalBet);
void resetGame(Player member);
void checkDie(Player member[], int& gambler);
void resetGame(Player member);
void suppleDeck(); // 임시
void endGame(Player member[], int& gambler);
void reGame(Player member[], Player& delaer);
void resultantPlate(Player member[]);
void testPlayer(Player member[]);


//--------------------------범진혁
void arrsort(int R[], int S[], int a);
void shuffle(Player member[], Player& dealer);
string pchecking(string a, string b, int amax_number, int amax_pattern, int bmax_number, int bmax_pattern);
string Pedigree_check(Player &nowPlay, int R[], int S[]);
int rating(string pedigree);
void checkFamilyTree(Player member[], int R0[], int R1[], int R2[], int R3[], int R4[], int R5[], int num);