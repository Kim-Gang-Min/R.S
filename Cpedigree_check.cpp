// 세번째 배팅용 족보 검사 함수(카드7장)
int Cpedigree_check(Player& nowPlay, int R[], int S[], Player play)
{
	arrsort(R, S, 7);

	int ptr1, ptr2;

	int pedigree = High_card;

	//pair
	if ((R[0] == R[1]) || (R[1] == R[2]) || (R[2] == R[3]) || (R[3] == R[4]) || (R[4] == R[5]) || (R[5] == R[6]))
	{
		// one pair
		if ((R[0] == R[1]) && (R[1] != R[2] != R[3] != R[4] != R[5] != R[6]))
		{
			pedigree = One_pair;
			ptr1 = R[1];
			if (S[1] > S[0])
				ptr2 = S[1];
			if (S[1] < S[0])
				ptr2 = S[0];
			nowPlay.setMax(ptr1, ptr2);
		}
		else if ((R[1] == R[2]) && (R[0] != R[2] != R[3] != R[4] != R[5] != R[6]))
		{
			pedigree = One_pair;
			ptr1 = R[2];
			if (S[2] > S[1])
				ptr2 = S[2];
			if (S[2] < S[1])
				ptr2 = S[1];
			nowPlay.setMax(ptr1, ptr2);
		}
		else if ((R[2] == R[3]) && (R[0] != R[1] != R[3] != R[4] != R[5] != R[6]))
		{
			pedigree = One_pair;
			ptr1 = R[3];
			if (S[3] > S[2])
				ptr2 = S[3];
			if (S[3] < S[2])
				ptr2 = S[2];
			nowPlay.setMax(ptr1, ptr2);
		}
		else if ((R[3] == R[4]) && (R[0] != R[1] != R[2] != R[4] != R[5] != R[6]))
		{
			pedigree = One_pair;
			ptr1 = R[4];
			if (S[4] > S[3])
				ptr2 = S[4];
			if (S[4] < S[3])
				ptr2 = S[3];
			nowPlay.setMax(ptr1, ptr2);
		}
		else if ((R[4] == R[5]) && (R[0] != R[1] != R[2] != R[3] != R[5] != R[6]))
		{
			pedigree = One_pair;
			ptr1 = R[5];
			if (S[5] > S[4])
				ptr2 = S[5];
			if (S[5] < S[4])
				ptr2 = S[4];
			nowPlay.setMax(ptr1, ptr2);
		}
		else if ((R[5] == R[6]) && (R[0] != R[1] != R[2] != R[3] != R[4] != R[6]))
		{
			pedigree = One_pair;
			ptr1 = R[6];
			if (S[6] > S[5])
				ptr2 = S[6];
			if (S[6] < S[5])
				ptr2 = S[5];
			nowPlay.setMax(ptr1, ptr2);
		}

		// two pair
		else if ((R[0] == R[1]) && (R[2] == R[3]) && (R[1] != R[3] != R[4] != R[5] != R[6]))
		{
			pedigree = Two_pair;
			ptr1 = R[3];
			ptr2 = 0;
			nowPlay.setMax(ptr1, ptr2);
		}
		else if ((R[0] == R[1]) && (R[3] == R[4]) && (R[1] != R[2] != R[4] != R[5] != R[6]))
		{
			pedigree = Two_pair;
			ptr1 = R[4];
			ptr2 = 0;
			nowPlay.setMax(ptr1, ptr2);
		}
		else if ((R[0] == R[1]) && (R[4] == R[5]) && (R[1] != R[2] != R[3] != R[5] != R[6]))
		{
			pedigree = Two_pair;
			ptr1 = R[5];
			ptr2 = 0;
			nowPlay.setMax(ptr1, ptr2);
		}
		else if ((R[0] == R[1]) && (R[5] == R[6]) && (R[1] != R[2] != R[3] != R[4] != R[6]))
		{
			pedigree = Two_pair;
			ptr1 = R[6];
			ptr2 = 0;
			nowPlay.setMax(ptr1, ptr2);
		}
		else if ((R[1] == R[2]) && (R[3] == R[4]) && (R[0] != R[2] != R[4] != R[5] != R[6]))
		{
			pedigree = Two_pair;
			ptr1 = R[4];
			ptr2 = 0;
			nowPlay.setMax(ptr1, ptr2);
		}
		else if ((R[1] == R[2]) && (R[4] == R[5]) && (R[0] != R[2] != R[3] != R[5] != R[6]))
		{
			pedigree = Two_pair;
			ptr1 = R[5];
			ptr2 = 0;
			nowPlay.setMax(ptr1, ptr2);
		}
		else if ((R[1] == R[2]) && (R[5] == R[6]) && (R[0] != R[2] != R[3] != R[4] != R[6]))
		{
			pedigree = Two_pair;
			ptr1 = R[6];
			ptr2 = 0;
			nowPlay.setMax(ptr1, ptr2);
		}
		else if ((R[2] == R[3]) && (R[4] == R[5]) && (R[0] != R[1] != R[3] != R[5] != R[6]))
		{
			pedigree = Two_pair;
			ptr1 = R[5];
			ptr2 = 0;
			nowPlay.setMax(ptr1, ptr2);
		}
		else if ((R[2] == R[3]) && (R[5] == R[6]) && (R[0] != R[1] != R[3] != R[4] != R[6]))
		{
			pedigree = Two_pair;
			ptr1 = R[6];
			ptr2 = 0;
			nowPlay.setMax(ptr1, ptr2);
		}
		else if ((R[3] == R[4]) && (R[5] == R[6]) && (R[0] != R[1] != R[2] != R[4] != R[6]))
		{
			pedigree = Two_pair;
			ptr1 = R[6];
			ptr2 = 0;
			nowPlay.setMax(ptr1, ptr2);
		}

		// triple
		else if ((R[0] == R[1] == R[2]) && (R[2] != R[3] != R[4] != R[5] != R[6]))
		{
			pedigree = Triple;
			ptr1 = R[2];
			ptr2 = 0;
			nowPlay.setMax(ptr1, ptr2);
		}
		else if ((R[1] == R[2] == R[3]) && (R[0] != R[3] != R[4] != R[5] != R[6]))
		{
			pedigree = Triple;
			ptr1 = R[3];
			ptr2 = 0;
			nowPlay.setMax(ptr1, ptr2);
		}
		else if ((R[2] == R[3] == R[4]) && (R[0] != R[1] != R[4] != R[5] != R[6]))
		{
			pedigree = Triple;
			ptr1 = R[4];
			ptr2 = 0;
			nowPlay.setMax(ptr1, ptr2);
		}
		else if ((R[3] == R[4] == R[5]) && (R[0] != R[1] != R[2] != R[5] != R[6]))
		{
			pedigree = Triple;
			ptr1 = R[5];
			ptr2 = 0;
			nowPlay.setMax(ptr1, ptr2);
		}
		else if ((R[4] == R[5] == R[6]) && (R[0] != R[1] != R[2] != R[3] != R[6]))
		{
			pedigree = Triple;
			ptr1 = R[6];
			ptr2 = 0;
			nowPlay.setMax(ptr1, ptr2);
		}

		//full house
		else if ((R[0] == R[1] == R[2]) && (R[3] == R[4]) && (R[2] != R[4] != R[5] != R[6]))
		{
			pedigree = Full_house;
			ptr1 = R[2];
			ptr2 = 0;
			nowPlay.setMax(ptr1, ptr2);
		}
		else if ((R[0] == R[1] == R[2]) && (R[4] == R[5]) && (R[2] != R[3] != R[5] != R[6]))
		{
			pedigree = Full_house;
			ptr1 = R[2];
			ptr2 = 0;
			nowPlay.setMax(ptr1, ptr2);
		}
		else if ((R[0] == R[1] == R[2]) && (R[5] == R[6]) && (R[2] != R[3] != R[4] != R[6]))
		{
			pedigree = Full_house;
			ptr1 = R[2];
			ptr2 = 0;
			nowPlay.setMax(ptr1, ptr2);
		}
		else if ((R[1] == R[2] == R[3]) && (R[4] == R[5]) && (R[0] != R[3] != R[5] != R[6]))
		{
			pedigree = Full_house;
			ptr1 = R[3];
			ptr2 = 0;
			nowPlay.setMax(ptr1, ptr2);
		}
		else if ((R[1] == R[2] == R[3]) && (R[5] == R[6]) && (R[0] != R[3] != R[4] != R[6]))
		{
			pedigree = Full_house;
			ptr1 = R[3];
			ptr2 = 0;
			nowPlay.setMax(ptr1, ptr2);
		}
		else if ((R[2] == R[3] == R[4]) && (R[5] == R[6]) && (R[0] != R[1] != R[4] != R[6]))
		{
			pedigree = Full_house;
			ptr1 = R[4];
			ptr2 = S[4];
			nowPlay.setMax(ptr1, ptr2);
		}

		//four card
		else if (R[0] == R[1] == R[2] == R[3])
		{
			pedigree = Four_card;
			ptr1 = R[3];
			ptr2 = S[3];
			nowPlay.setMax(ptr1, ptr2);
		}
		else if (R[1] == R[2] == R[3] == R[4])
		{
			pedigree = Four_card;
			ptr1 = R[4];
			ptr2 = S[4];
			nowPlay.setMax(ptr1, ptr2);
		}
		else if (R[2] == R[3] == R[4] == R[5])
		{
			pedigree = Four_card;
			ptr1 = R[5];
			ptr2 = S[5];
			nowPlay.setMax(ptr1, ptr2);
		}
		else if (R[3] == R[4] == R[5] == R[6])
		{
			pedigree = Four_card;
			ptr1 = R[6];
			ptr2 = S[6];
			nowPlay.setMax(ptr1, ptr2);
		}
	}

	//straight
	if ((R[1] != R[0] + 1) && (R[2] == R[1] + 1) && (R[3] == R[2] + 1) && (R[4] == R[3] + 1))
	{
		pedigree = Straight;
		ptr1 = R[4];
		ptr2 = S[4];
		nowPlay.setMax(ptr1, ptr2);
	}
	if ((R[2] == R[1] + 1) && (R[3] == R[2] + 1) && (R[4] == R[3] + 1) && (R[5] == R[4] + 1))
	{
		pedigree = Straight;
		ptr1 = R[5];
		ptr2 = S[5];
		nowPlay.setMax(ptr1, ptr2);
	}
	if ((R[3] == R[2] + 1) && (R[4] == R[3] + 1) && (R[5] == R[4] + 1) && (R[6] == R[5] + 1))
	{
		pedigree = Straight;
		ptr1 = R[6];
		ptr2 = S[6];
		nowPlay.setMax(ptr1, ptr2);
	}

	//straight flush
	if (((R[1] != R[0] + 1) && (R[2] == R[1] + 1) && (R[3] == R[2] + 1) && (R[4] == R[3] + 1)) && (S[0] == S[1] == S[2] == S[3] == S[4]))
	{
		pedigree = Straight_flush;
		ptr1 = R[4];
		ptr2 = S[4];
		nowPlay.setMax(ptr1, ptr2);
	}
	if (((R[2] == R[1] + 1) && (R[3] == R[2] + 1) && (R[4] == R[3] + 1) && (R[5] == R[4] + 1)) && (S[1] == S[2] == S[3] == S[4] == S[5]))
	{
		pedigree = Straight_flush;
		ptr1 = R[5];
		ptr2 = S[5];
		nowPlay.setMax(ptr1, ptr2);
	}
	if (((R[3] == R[2] + 1) && (R[4] == R[3] + 1) && (R[5] == R[4] + 1) && (R[6] == R[5] + 1)) && (S[2] == S[3] == S[4] == S[5] == S[6]))
	{
		pedigree = Straight_flush;
		ptr1 = R[6];
		ptr2 = S[6];
		nowPlay.setMax(ptr1, ptr2);
	}

	//flush
	if ((S[0] == S[1]) || (S[1] == S[2]) || (S[2] == S[3]) || (S[3] == S[4]) || (S[4] == S[5]) || (S[5] == S[6]))
	{
		arrsort(S, R, 7);

		if (S[0] == S[1] == S[2] == S[3] == S[4])
		{
			pedigree = Flush;

			if (S[4] != S[5] != S[6])
			{
				ptr2 = S[4];
				ptr1 = R[4];
				nowPlay.setMax(ptr1, ptr2);
			}
			else if ((S[4] == S[5]) && (S[5] != S[6]))
			{
				ptr2 = S[5];
				ptr1 = R[5];
				nowPlay.setMax(ptr1, ptr2);
			}
			else if (S[4] == S[5] == = S[6])
			{
				ptr2 = S[6];
				ptr1 = R[6];
				nowPlay.setMax(ptr1, ptr2);
			}
		}
		if (S[1] == S[2] == S[3] == S[4] == S[5])
		{
			pedigree = Flush;
			if (S[5] != S[6])
			{
				ptr2 = S[5];
				ptr1 = R[5];
				nowPlay.setMax(ptr1, ptr2);
			}
			else if (S[5] == S[6])
			{
				ptr2 = S[6];
				ptr1 = R[6];
				nowPlay.setMax(ptr1, ptr2);
			}
		}
	}
	// 플레이어 die 한 경우
	if (play.checkPlay() == fasle)
	{
		pedigree = Die;
	}
	return pedigree;
}