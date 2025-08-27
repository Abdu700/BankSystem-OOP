#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "clsDate.h"

using namespace std;

class clsUtil
{

public:
	enum enCharType { SmallLetter = 1, CapitalLetter = 2, Digit = 3, MixChars = 4 };

	static int RandomNumber(int From, int To) {
		int RandNum = rand() % (To - From + 1) + From;
		return RandNum;
	}

	static char GetRandomCharacter(enCharType CharType) {
		switch (CharType) {
		case enCharType::SmallLetter:
			return char(RandomNumber(97, 122));
		case enCharType::CapitalLetter:
			return char(RandomNumber(65, 90));
		case enCharType::Digit:
			return char(RandomNumber(48, 57));

		case enCharType::MixChars:

			int type = RandomNumber(1, 3);
			switch (type) {
			case enCharType::SmallLetter:
				return char(RandomNumber(97, 122));
			case enCharType::CapitalLetter:
				return char(RandomNumber(65, 90));
			case enCharType::Digit:
				return char(RandomNumber(48, 57));
			}
		}
	}

	static string GenerateWord(enCharType CharType, int Length) {
		string Word = "";
		for (int i = 1; i <= Length;i++) {
			Word += GetRandomCharacter(CharType);
		}
		return Word;

	}

	static string GenerateKey(enCharType CharType) {
		string Key = "";
		Key += GenerateWord(CharType, 4) + "-";
		Key += GenerateWord(CharType, 4) + "-";
		Key += GenerateWord(CharType, 4) + "-";
		Key += GenerateWord(CharType, 4);
		return Key;
	}

	static void GenerateKeys(short NumberOfKeys, enCharType CharType)
	{
		for (int i = 1; i <= NumberOfKeys; i++) {
			cout << "Key [" << i << "] : " << GenerateKey(CharType) << endl;
		}

	}

	static void Srand() {
		srand((unsigned)time(NULL));
	}

	static void Swap(int& x, int& y) {
		int temp = x;
		x = y;
		y = temp;
	}

	static void Swap(double& x, double& y) {
		double temp = x;
		x = y;
		y = temp;
	}

	static void Swap(string& x, string& y) {
		string temp = x;
		x = y;
		y = temp;
	}

	static void Swap(clsDate& x, clsDate& y) {
		clsDate::SwapDates(x,y);
	}

	static void FillArrayWithRandomNumbers(int arr[], int arrLength, int From,int To) {

		for (int i = 0; i < arrLength; i++)
			arr[i] = RandomNumber(From,To);
	}

	static void ShuffleArray(int arr[], int arrLength) {
		int randomNum = 0, Temp = 0;
		for (int i = 0; i <= arrLength - 1;i++) {
			Swap(arr[RandomNumber(0, arrLength - 1)], arr[RandomNumber(0, arrLength - 1)]);
		}

	}

	static void ShuffleArray(string arr[], int arrLength) {
		int randomNum = 0, Temp = 0;
		for (int i = 0; i <= arrLength - 1;i++) {
			Swap(arr[RandomNumber(0, arrLength - 1)], arr[RandomNumber(0, arrLength - 1)]);
		}

	}

	static void FillArrayWithRandomWords(string arr[], int arrLength, enCharType CharType, int Length) {

		for (int i = 0; i < arrLength; i++)
			arr[i] = GenerateWord(CharType, Length);
	}

	static void FillArrayWithRandomKeys(string arr[], int arrLength, enCharType CharType) {

		for (int i = 0; i < arrLength; i++)
			arr[i] = GenerateKey(CharType);
	}

	static string Tabs(short NumberOfTabs) {
		string tab = "";
		for (short i = 1; i <= NumberOfTabs; i++)
			tab += "\t";
		return tab;

	}

	static string EncryptText(string Text, short EncryptionKey) {

		for (int i = 0; i < Text.length();i++) {
			Text[i] = char((int)Text[i] + EncryptionKey);
		}
		return Text;
	}

	static string DecryptText(string Text, short EncryptionKey) {

		for (int i = 0; i < Text.length();i++) {
			Text[i] = char((int)Text[i] - EncryptionKey);
		}
		return Text;
	}

};

