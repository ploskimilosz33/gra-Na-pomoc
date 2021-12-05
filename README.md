„Na pomoc”
Gra strategiczna w C++
Artur Wasilewski, Tymoteusz Tołwiński, Miłosz Płoski 15.05.2021


1.1	O co chodzi w tej grze ? 

  Gra strategiczna w której wcielamy się najemnika który staje przed wyzwaniem by pomóc wieśniakowi w potrzebie. Przez 10 dni(tur) mamy za zadanie uzbierać 1000złota i spłacić dług.
Gra zaczyna się od prośby podania imienia naszej postaci.

![f](https://user-images.githubusercontent.com/95579420/144756822-4e7895c4-a465-4a73-80db-2102d85c55e8.png)


  Rysunek 1Wpisanie imienia ( ekran powitalny) Zrzut z Ekranu
Następnie zostajemy poproszeni o wybranie jednej z dwóch opcji:

![image](https://user-images.githubusercontent.com/95579420/144756837-02162428-7cf8-4e72-abca-d75b0bc628d3.png)


  Rysunek 2Zrzut z ekranu ( wybór opcji )
Następnie zostaniemy wprowadzeni do fabuły i rozpocznie się właściwa rozgrywka naszej gry

![image](https://user-images.githubusercontent.com/95579420/144756848-7caa3356-a733-4baa-a9c4-228e5a98ea87.png)

Rysunek 3 Zrzut z ekranu (Wprowadzenie do fabuły)

![image](https://user-images.githubusercontent.com/95579420/144756854-4e00b368-96e0-4b48-94de-6437ce904a6c.png)

  Rysunek 4 Zrzut z ekranu (Główne pole gry )
Istnieją dwa sposoby na zbieranie pieniędzy „Praca na roli” oraz „Ryzykowana podróż”(odpowiednio przyciski 1 i 2)(Rysunek 4)

  Praca na roli zapewnia nam 80 złota za dzień pracy i odejmuje 5 pkt zdrowia. Ale pracując tam przez całe 10 dni nie damy rade uzbierać całej kwoty co zmusza nas do wyboru Ryzykownej podróży gdzie możemy stracić dzień przedzierając się przez las:


![image](https://user-images.githubusercontent.com/95579420/144756874-0cafc315-2ee6-47ae-90f4-b74776df77d1.png)

Rysunek 5 Zrzut z ekranu ( praca na roli)

lub znaleźć skarb i wrócić cały i zdrowym:
 ![image](https://user-images.githubusercontent.com/95579420/144757008-a36a09a6-a846-4e53-8086-61e76f65e632.png)

Rysunek 6 Zrzut z ekranu(Pustynia/skarba)

Podczas Ryzykownej podróży możesz także natrafić na przeciwników z którymi będziesz zmuszony walczyć. Jeśli uda ci się przeżyć zostaniesz nagrodzony złotem:
(czym cięższy przeciwnik tym więcej obrażeń zada i dostaniemy więcej złota za zabicie go)
 
 ![image](https://user-images.githubusercontent.com/95579420/144757021-27b94709-dab5-4607-bba9-da4ac875b8a8.png)

 
Rysunek 7 Zrzut z ekranu(walka z trollem)
Do naszej dyspozycji jest także karczma ( numer 3 ) w której możemy odnowić swoje pkt zdrowia:
 ![image](https://user-images.githubusercontent.com/95579420/144757029-ad343810-b456-489d-a64f-9b0c8516ae5a.png)

Rysunek 8 Zrzut z ekranu (karczma)
Piwo przywraca nam 10pkt zdrowia i kosztuje 5 złota. Każdego dnia możemy wypić tyle piwa ile chcemy i na ile pozwala nam nasz budżet.

 ![image](https://user-images.githubusercontent.com/95579420/144757038-b1197a75-8ff9-41ea-9281-d88b56f84a2b.png)

Rysunek 9 Zrzut z ekranu(Piwo)
Możemy też skorzystać z opcji noclegu która kosztuje 20złota i odnowić wszystkie brakujące pkt zdrowia.(lecz na tą operację trzeba poświęcić jeden cały dzień)
 ![image](https://user-images.githubusercontent.com/95579420/144757045-e7430e33-f16a-49d2-814e-92a1ecda79a1.png)

Rysunek 10 Zrzut z ekranu(nocleg)
W momencie gdy uzbieramy 1000 złota możemy wybrać opcje „Spłać dług” jeśli nie uda nam się uzbierać złota na czas gra kończy się porażką
 
![image](https://user-images.githubusercontent.com/95579420/144757065-f9212e72-2666-44f3-9f05-740e7d091577.png)


Rysunek 11 Zrzut z ekranu(spłać dług)
Nasza rozgrywka zakończy się porażką także gdy nasze zdrowie spadnie do zera.
 ![image](https://user-images.githubusercontent.com/95579420/144757068-a1df230e-26e0-45f5-accd-41a691971b62.png)

Rysunek 12 Zrzut z ekranu( śmierć)
Jeśli uda ci się uzbierać 1000złota w mniej niż 10 dni ( tur) wtedy wygrywasz.

1.2	Jaki jest cel gry ? 
Celem gry jest uzbierać 1000złota w określonym czasie.

1.3	Kiedy się wygrywa a kiedy przegrywa ? 
Wygrywa się w momencie gdy w mniej niż 10dni uzbieramy 1000złota. W innym wypadku rozgrywka kończy się porażką. Gra także zostanie zakończona porażką gdy punkty zdrowia naszej postaci spadną do zera.

1.4	Co pomaga wygrać? Co utrudnia
Pomaga nam wygrać karczmarz u którego możemy zatrzymać się na jeden dzień i odnowić swoje punkty życia. Utrudnia nam upływający czas i fakt, że tracimy życie jak podejmujemy się pracy na roli i tracimy jeszcze więcej życia jak postanowimy wybrać się na ryzykowną podróż.

Schemat UML 

![image](https://user-images.githubusercontent.com/95579420/144757137-23371169-9c16-47f2-a00f-e3090b3d7002.png)

Rysunek 13Schemat klas

2.1	Klasa Charakter
Jest to podstawowa klasa w naszym kodzie programu odpowiada za podstawowe statystki bohatera takie jak: punkty HP – czyli punkty zdrowia naszego bohatera czy Gold – inaczej posiadanie złoto ponadto w tej klasie znajdują się metody czyli inaczej funkcje takie jak:
 PobierzGold – tak jak sugeruje nazwa ta metoda odpowiada za pobranie aktualnej wartości posiadanego złota, 
 UstawGold – odpowiada za przypisanie nowej wartości liczbowej złota do zmiennej jegoGold, 
PobierzHP – odpowiada za pobieranie aktualnej wartości punktów zdrowia, UstawHp – odpowiada za przypisanie nowej wartości punktów zdrowia dla zmiennej jegoHP, 
Ustawhpmax – odpowiada za ustawienie punktów zdrowia na 100 jeśli HP przekroczy 100.
2.2	Klasa Bohater
Klasa bohater dziedziczy zmienne i metody z klasy Charakter oraz dodaje własne metody takie jak: 
Idzie – metoda ta odpowiada za wypisywanie na ekranie losową ilość linijek teksu, sugerujących wykonywaną pracę
	Pracuje – metoda ta odpowiada za przypisanie wynagrodzenia za wykonaną pracę bohatera jak i odebranie odpowiadającej liczby punktów zdrowia bohaterowi
	Pije_browar – ta metoda odpowiada za dodawanie punktów zdrowia bohaterowi za wypicie tytułowego browara po pobraniu od bohatera stosowniej do ilości piw pieniędzy(gold)
	Walczy_* - wszystkie metody z tym początkiem odpowiadają jednemu danemu przeciwnikowi lub sytuacji, te metody mają za zadanie odpowiednio to typu przeciwnika lub sytuacji odpowiednio dodać bądź odjąć HP czy Gold oraz sprawdzić czy bohater nadal żyje
2.3	Klasa lokacja 
Klasa lokacja odpowiada losowy wybór miejsca do jakiego trafimy. 
Tablica nazwa_lokac – przechowuje nazwy miejsc do jakich możemy trafić
Metoda lose_wypisz – odpowiada za wybranie losowej liczby
Metoda nazwa_wypisz – odpowiada za wypisanie odpowiedniej nazwy lokacji zgodnej z wylosowaną wcześniej w metodzie lose_wypisz liczbie
2.4	Klasa Quest 
Klasa Quest dziedziczy zmienne i metody z klasy lokacja oraz dodaje własne metody i zmienne takie jak:
	String nazwa_q – odpowiada za przechowywanie tekstu do wypisanie później w konsoli
	Metoda Idzie_q – odpowiada za wypisanie drogi jak i destynacje podróży na ekranie
	
2.5	Związki między klasami 
W naszym programie klasa bohater dziedziczy z klasy charakter metody jak i zmienne oraz rozszerza ją o swoje metody odwołujące się do klasy chratakter.
Klasa Quest dziedziczy z klasy lokacja metody i zmienne oraz dodaje własną metodę i zmienną. W metodzie Idzie_q dzięki dziedziczeniu klas ta metoda może pracować i odwoływać się do wcześniej wspominanej klasy lokacja.   



