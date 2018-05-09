#include "maintests.h"

const int fee = 2;

void MainTests::testGetProofOfWorkReward()
{

	pindexBest = new CBlockIndex();

	nBestHeight = 0;
	QCOMPARE(GetProofOfWorkReward(fee), (5000000 * COIN + fee));

	nBestHeight = 1;
	QCOMPARE(GetProofOfWorkReward(fee), (10 * COIN + fee));

	nBestHeight = 10;
	QCOMPARE(GetProofOfWorkReward(fee), (10 * COIN + fee));

	nBestHeight = 9000;
	QCOMPARE(GetProofOfWorkReward(fee), (10 * COIN + fee));

	nBestHeight = 21599;
	QCOMPARE(GetProofOfWorkReward(fee), (10 * COIN + fee));

	nBestHeight = 21601;
	QCOMPARE(GetProofOfWorkReward(fee), (50 * COIN + fee));

	nBestHeight = 400001;
	QCOMPARE(GetProofOfWorkReward(fee), (50 * COIN + fee));

	//hardcap
	pindexBest->nMoneySupply = MAX_MONEY+4;
	QCOMPARE(GetProofOfWorkReward(fee), fee);
}

void MainTests::testGetProofOfStakeReward()
{
	pindexBest = new CBlockIndex();
	int64_t nCoinAge = 1 * 365 ;

	// normal APR
	nBestHeight = 7;
	QCOMPARE(GetProofOfStakeReward(nCoinAge, fee)/COIN, (int64_t)(double)8.99402640);

	nBestHeight = 35;
	QCOMPARE(GetProofOfStakeReward(nCoinAge, fee)/COIN, (int64_t)(double)8.99402640);

	// superblocks
	nBestHeight = 1210;
	QCOMPARE(GetProofOfStakeReward(nCoinAge, fee)/COIN, (int64_t)(double)17.98805278);

	nBestHeight = 17210;
	QCOMPARE(GetProofOfStakeReward(nCoinAge, fee)/COIN, (int64_t)(double)17.98805278);

	//hardcap
	pindexBest->nMoneySupply = MAX_MONEY+4;
	QCOMPARE(GetProofOfStakeReward(nCoinAge, fee), fee);
}
