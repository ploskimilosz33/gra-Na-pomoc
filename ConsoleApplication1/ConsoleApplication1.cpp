#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <locale.h>
#include<string>
#include<Windows.h>
#include<ctime>
int r;


using namespace std;
class Charakter
{

public:

	string imie;
	Charakter() :jegoGold(0), jegoHp(100)//konstruktor 
	{}
	~Charakter() {}


	int PobierzGold() const { return jegoGold; }
	void UstawGold(int gold) { jegoGold = gold; }
	int PobierzHp() const { return jegoHp; }
	void Ustawhp(int Hp) { jegoHp = Hp; }
	void Ustawhpmax()//maksymalne hp
	{
		if (jegoHp >= 100)
		{
			jegoHp = 100;
		}
	}



protected:

	int jegoGold;
	int jegoHp;


};

class Bohater : public Charakter //klasa bohater dziedzyczy z charaktera
{
public:



	void Idzie()
	{
		HANDLE kolor;//kolorki
		kolor = GetStdHandle(STD_OUTPUT_HANDLE);

		while (r != 1)
		{
			//losow wypisywanie "Pracujesz..."
			SetConsoleTextAttribute(kolor, 4);
			cout << "Pracujesz..." << endl; Sleep(750);
			cout << "Pracujesz..." << endl; Sleep(750);
			cout << "Pracujesz..." << endl; Sleep(750);
			r = rand() % 3;
		}
		SetConsoleTextAttribute(kolor, 7);
		r = 0;




	}
	void Pracuje()//Praca na polu
	{
		//Pobranie golda i hp za prace na roli
		UstawGold(PobierzGold() + 80);
		Ustawhp(PobierzHp() - 5);

		if (jegoHp <= 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			cout << "Jestes martwy" << endl; Sleep(1750);
			cout << "Koniec Gry!!!" << endl; Sleep(4000);

			exit(0);

		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << "Narrator:" << endl; Sleep(1750);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		cout << "Pracujesz do utraty tchu" << endl;
		cout << " Za wykonanie zlecenia otrzymujesz: " << endl;

	}
	void Walczy_smok()//walka ze smokiem
	{
		if (PobierzHp() == 1)
		{
			Ustawhp(PobierzHp() - 1);
		}
		UstawGold(PobierzGold() + 250);
		Ustawhp(PobierzHp() - (PobierzHp() - 1));

		if (jegoHp <= 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			cout << "Jestes martwy" << endl; Sleep(1750);
			cout << "Koniec Gry!!!" << endl; Sleep(4000);
			exit(0);

		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << "Narrator:" << endl; Sleep(1750);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		cout << "Walka była ciężka ale się opaciła, wracasz poobijany i żywy :)" << endl;
		cout << " Za pokonanie otrzymujesz: 200 golda " << endl;

	}
	void Walczy_shrek()//walka ze Shrekiem
	{
		UstawGold(PobierzGold() + 150);

		Ustawhp(PobierzHp() - 60);

		if (jegoHp <= 0)
		{
			cout << "Jestes martwy" << endl; Sleep(1750);
			cout << "Koniec Gry!!!" << endl; Sleep(4000);
			exit(0);

		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << "Narrator:" << endl; Sleep(1750);
		cout << "Meznie walczy do utraty tchu" << endl;
		cout << " Za pokonanie otrzymujesz: 100 golda" << endl;

	}
	void Walczy_pustynia()//Szukanie skarbu na pustyni
	{

		UstawGold(PobierzGold() + 200);

		if (jegoHp <= 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			cout << "Jestes martwy" << endl; Sleep(1750);
			cout << "Koniec Gry!!!" << endl; Sleep(4000);
			exit(0);

		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << "Narrator:" << endl; Sleep(1750);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		cout << "Kopałeś cały dziń na pustyni ale się to opłaciło bo wykopałeś skrzynię ze skarbem" << endl;
		cout << " W skrzynce jest 200 golda: " << endl;
	}
	void Walczy_las()//przchodzenie lasu
	{


		Ustawhp(PobierzHp() - 10);

		if (jegoHp <= 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			cout << "Jestes martwy" << endl; Sleep(1750);
			cout << "Koniec Gry!!!" << endl; Sleep(4000);
			exit(0);

		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << "Narrator:" << endl; Sleep(1750);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		cout << "Skaleczyłeś się podczas przeprawy (-10 hp) i nic nie znalazłeś," << endl;
		cout << " Wracasz z pustymi rękami" << endl;


	}
	void Walczy_zamek()//walka z goblinami
	{
		UstawGold(PobierzGold() + 100);
		Ustawhp(PobierzHp() - 20);

		if (jegoHp <= 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			cout << "Jestes martwy" << endl; Sleep(1750);
			cout << "Koniec Gry!!!" << endl; Sleep(4000);
			exit(0);

		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << "Narrator:" << endl; Sleep(1750);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		cout << "Gobliny otoczyły cię ale się nie poddałeś i wygrałeś" << endl;
		cout << " Za pokonanie otrzymujesz: 100 golda " << endl;
	}






	void Pije_browar(int liczba_piwerek)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		if (PobierzGold() >= 5)
		{                                                                   //Za wypicie 1 piwa - 5 golda + 10 hp
			for (int i = 1; i <= liczba_piwerek; i++)
			{
				cout << "Siorb Siorb - [" << i << "] gul gul..." << endl;
			}

			cout << "Wychal wszystko" << endl; UstawGold(PobierzGold() - liczba_piwerek * 5);
			Ustawhp(PobierzHp() + liczba_piwerek * 10);
		}
		else
		{
			cout << "Gdzie tu sie pchasz bez pieniedzy!" << endl;
		}
	}

};
class lokacja
{
public:
	int lose_wypisz();//losuje liczbe w zakresie od 0 do 5.
	string nazwa_lokac[5] = { "Jaskini Smoka","Bagna Shreka","Pustyni","Nawiedzonego lasu","Ruin Zamku" };
	void nazwa_wypisz(int x);
};
void lokacja::nazwa_wypisz(int x)
{
	cout << nazwa_lokac[x] << endl;//wypisuje nazwe
};

int lokacja::lose_wypisz()
{
	srand((unsigned)time(0));
	int Number = ((rand() % 5));
	return Number;



}
class Quest :lokacja
{
protected:
	string nazwa_q = "Wybierasz się w podróż";

public:
	int a;
	string Pobierznazwa_q() { return nazwa_q; }

	void Idzie_q()
	{

		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		cout << Pobierznazwa_q() << endl; Sleep(1750);
		while (r != 1)
		{


			cout << "Idziesz..." << endl; Sleep(750);
			cout << "Idziesz..." << endl; Sleep(750);
			cout << "Idziesz..." << endl; Sleep(750);
			r = rand() % 3;
		}
		r = 0;
		system("cls");

		cout << "Możesz trafić na : pustynie, Bagno Shreka, Jaskinia Smoka, Nawiedzony las, Ruiny zamku" << endl; Sleep(2500);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "Dotarles do : " << endl; Sleep(1750);




		a = lose_wypisz();

		nazwa_wypisz(a); Sleep(2500);

	}
};


//Główna pętla programu
int main()
{
	string j;
	int deadline = 10;
	setlocale(LC_CTYPE, "Polish");
	int decyzja, l_piwerek;
	Bohater Heros;
	lokacja l;
	Quest q;

	HANDLE kolor;
	kolor = GetStdHandle(STD_OUTPUT_HANDLE);


	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "Karczmarz:" << endl; Sleep(1750);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	cout << "Podróżniku w mojej karczmie.Nazywam się Lektys.Rozgość się proszę." << endl; Sleep(1750);
	cout << "Jak cię zwą podróżniku?" << endl; Sleep(1750);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cin >> Heros.imie;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "Karczmarz:" << endl; Sleep(1750);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	cout << "Słyszałem, że przyszedłeś w sprawie ogłoszenia. " << endl; Sleep(1750);
	cout << "Ciszę się, że na tym okrutnym świecie istnieją jeszcze porządni ludzie gotowi walczyć w słusznej sprawie." << endl; Sleep(1750);

	cout << endl;



	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "Wybierz jedną z opcji!" << endl;
	cout << " |===========================================================|" << endl;
	cout << " |=  Z radością ci pomogę mój przyjacielu.    <wybierz> - 1 =|" << endl;
	cout << " |=  Zawsze służę pomocą ludziom w potrzebie. <wybierz> - 2 =|" << endl;
	cout << " |===========================================================|" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cin >> j;//Użytkownik wybiera 1 lub 2

	cout << " " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "Narrator:" << endl; Sleep(1750);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cout << "Zdecydowałeś się pomóc wieśniakowi w potrzebie." << endl; Sleep(1750);
	cout << "Jeden z szpiegów gangu doniósł o tym do swojego szefa.... Teraz już nie ma odwrotu" << endl; Sleep(1750);
	cout << "" << endl;
	cout << "Masz 10 dni na spłatę długu lub czeka cię pewna śmierć!!! " << endl; Sleep(1750);
	cout << "Istnieją dwa sposoby na zarabianie pieniędzy." << endl; Sleep(1750);
	cout << "Bezpieczny, gdzie codziennie można wybrać się do pobliskiej miejscowości pomóc na roli." << endl; Sleep(1750);
	cout << "" << endl;
	cout << "Lub wybrać się na ryzykowną przygodę by zawalczyć z potworami i okraść je ze skarbów. " << endl; Sleep(1750);
	cout << "Lecz uważaj podróżniku, gdyż z wielkimi skarbami wiąże się wielkie niebezpieczeństwo. " << endl; Sleep(1750);
	cout << "Możesz zyskać fortunę lub stracić zdrowie i nic nie zyskać..." << endl; Sleep(1750);
	cout << "Od ciebie zależy, jak zapracujesz, ale pamiętaj, że czas ucieka....." << endl; Sleep(1750);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "Wpisz coś by przejść dalej... " << endl;
	cin >> j;//użytkownik ma wcisnąć dowolny klawisz
	system("cls");


	for (int i = 1; i <= deadline; i++)//wyświetlanie opcji na 10 dni
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8); cout << " Dzień " << i; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3); cout << " Imie: " << Heros.imie << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); cout << " Gold: " << Heros.PobierzGold(); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); cout << " Zdrowie: " << Heros.PobierzHp() << endl;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

		cout << " |========================================|" << endl;
		cout << " |= Praca na roli          <wybierz> - 1 =|" << endl;
		cout << " |= Ryzykowna przygoda     <wybierz> - 2 =|" << endl;
		cout << " |= Idź do tawerny         <wybierz> - 3 =|" << endl;
		cout << " |= Spłac dług             <wybierz> - 4 =|" << endl;
		cout << " |= Wyjdź z gry            <wybierz> - 0 =|" << endl;
		cout << " |========================================|" << endl;



		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		cin >> decyzja;//Użytkownik wybiera 1 lub 2 lub 3 lub 4 lub 0.
		system("cls");


		if (decyzja == 1)
		{

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			cout << "Dzień pracy daje Ci: (+80) GOLD,(-5) pkt życia)" << endl; Sleep(1750);

			Heros.Idzie();

			Heros.Pracuje();


		}
		if (decyzja == 2)
		{


			q.Idzie_q();

			if (q.a == 0)
			{

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);

				cout << "Smok atakuje za - 99% pkt hp" << endl; Sleep(1750);

				while (r != 1)
				{
					cout << "Walczysz..." << endl; Sleep(750);
					cout << "Walczysz..." << endl; Sleep(750);
					cout << "Walczysz..." << endl; Sleep(750);

					r = rand() % 2;
				}
				r = 0;
				system("cls");
				Heros.Walczy_smok();





			}
			if (q.a == 1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);

				cout << "Shrek atakuje za - 60 pkt hp" << endl; Sleep(1750);

				while (r != 1)
				{
					cout << "Walczysz..." << endl; Sleep(750);
					cout << "Walczysz..." << endl; Sleep(750);
					cout << "Walczysz..." << endl; Sleep(750);

					r = rand() % 2;
				}
				r = 0;
				system("cls");
				Heros.Walczy_shrek();





			}
			if (q.a == 2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);

				cout << "Szukasz skrzynki ze skarbem" << endl; Sleep(1750);

				while (r != 1)
				{
					cout << "Kopiesz..." << endl; Sleep(750);
					cout << "Kopiesz..." << endl; Sleep(750);
					cout << "Kopiesz..." << endl; Sleep(750);

					r = rand() % 2;
				}
				r = 0;
				system("cls");
				Heros.Walczy_pustynia();





			}
			if (q.a == 3)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);

				cout << "Napotykasz gąszcz gałęzi" << endl; Sleep(1750);

				while (r != 1)
				{
					cout << "Przedzierasz się..." << endl; Sleep(750);
					cout << "Przedzierasz się..." << endl; Sleep(750);
					cout << "Przedzierasz się..." << endl; Sleep(750);

					r = rand() % 2;
				}
				r = 0;
				system("cls");
				Heros.Walczy_las();




			}
			if (q.a == 4)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);

				cout << "Gobliny atakują za (-20 hp)" << endl; Sleep(1750);

				while (r != 1)
				{
					cout << "Walczysz..." << endl; Sleep(750);
					cout << "Walczysz..." << endl; Sleep(750);
					cout << "Walczysz..." << endl; Sleep(750);

					r = rand() % 2;
				}
				r = 0;
				system("cls");
				Heros.Walczy_zamek();





			}
		}
		if (decyzja == 3)
		{
			int h;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << " |===========================================================================================|" << endl;
			cout << " |= Czy chcesz wypić piwo?(1 piwerko daje : (- 5)GOLD, (+10) pkt hp)          <wybierz> - 1 =|" << endl;
			cout << " |= Czy chcesz spać cały dziń, by odnowić punkty zdrowia w pełni za 20 golda? <wybierz> - 2 =|" << endl;
			cout << " |= Wyjdź z Tawerny.                                                          <wybierz> - 3 =|" << endl;
			cout << " |===========================================================================================|" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			cin >> h;//Użytkownik wybiera 1 lub 2 lub 3.

			if (h == 1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				cout << "Podaj ile ma piwerek wysiorbac ? (1 piwerko daje : (- 5)GOLD, (+10) pkt hp)" << endl;
				cout << "Masz tyle w sakiewce: ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				cout << Heros.PobierzGold() << "gold" << endl;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				cin >> l_piwerek;//ilość piwerek
				Heros.Pije_browar(l_piwerek);
				Heros.Ustawhpmax();

				i--;
			}
			if (h == 2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				cout << "Wstajesz rano pełny sił" << endl;
				Heros.Ustawhp(100);
				Heros.UstawGold(Heros.PobierzGold() - 20);



			}
			if (h == 3)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				cout << "Wychodzisz z Taverny!" << endl;
				i--;
			}
			if (h != 1 && h != 2 && h != 3)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				cout << " Musisz wpisać wartość 1, 2, 3\n";
			}
		}
		if (decyzja == 4)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);

			cout << "Spłać dług Karczmarz wynoszący 1000 golda" << endl;
			cout << "\t Posiadasz tyle: " << Heros.PobierzGold() << "gold\n";
			if (Heros.PobierzGold() >= 1000)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);

				cout << " Spłać dług" << endl; Sleep(1750);
				cout << "Dziekujemy za gre" << endl; Sleep(1750);
				cout << "Program Exit\n\n"; Sleep(1750);
				exit(0);

			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);

				cout << " Jestes za biedny pracuj dalej" << endl;
				cout << " " << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				i--;
			}
			i--;
		}

		if (decyzja == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);

			cout << "Program Exit\n\n";
			exit(0);


		}
		if (decyzja != 1 && decyzja != 2 && decyzja != 3 && decyzja != 4 && decyzja != 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);

			cout << " Musisz wpisać wartość 1, 2, 3, 4, 0\n";
			i--;
		}
	}
	if (Heros.PobierzGold() >= 1000)//Można spłacić dług
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);

		cout << "Masz szczęście udało Ci się spłacić dług" << endl;
		cout << "KONIEC GRY!" << endl;
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);

		cout << "Skończył ci się czas nie oddałeś pieniędzy" << endl;
		cout << "KONIEC GRY!" << endl;
	}

	system("PAUSE");
	return(0);
}
