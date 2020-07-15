# C-and-Cpp
Kod źródłowy do programów z yt.

<h1>Proces kompilacji</h1>
<ol>
<li> Najpierw na scenę wkracza Pan Preprocesor. Zadań tego Pana jest wiele, wśród nich wymienić można:
<dl>
<dd>- Kopiowanie zawartości załączonych plików nagłówkowych do kodu źródłowego. Na przykład jeśli w jednym z kompilowanych plików umieśiliśmy ```c++ #include "plik.h"``` to treść tego pliku zostanie przekopiowana do naszego kodu źródłowego. </dd> 
<dd>- Generacja kodu makr. </dd>
	<dd>- Zamiana stałych zdefiniwanyh za pomocą <i>#define</i> na ich wartości. </dd>
</dl>
</li>
<li> Kod źródłowy przygotowany przez Pana Preprocesora jest następnie tłumaczony na assembler zrozumiały przez daną maszynę. </li>
<li> Kod assemblera jest następnie tłumaczony na kod obiektowy zrozumiały przez daną maszynę. </li>
<li> Przygotowany w ten sposób kod obiektowy jest łączony z kodem obiektowym funkcji z zewnętrznych bibliotek w wykonywalny program. </li>
</ol>

<h1>Zmienne</h1>
<h4>Stworzenie zmiennej:</h4>
<p><em>Typ + nazwa;</em></p>

```c++
int x;
double y;
```
<h4>Inicjalizacja</h4>

```c++
x = 10;
y = 3.56;
```
<h4>Nadpisanie:</h4>

```c++
x = 10;
x = x + 3;
x++;
```

<h2>Typy zmiennych</h2>
<table class="boxed">
<tbody>
<tr>
<th>Grupa</th>
<th>Deklaracja w kodzie</th>
<th>Precyzja oraz rozmiar</th>
</tr>
<tr>
<td rowspan="4">Pojedyncze znaki</td>
<td>char</td>
<td>Jeden bajt. Najczęściej 8 bitów.</td>
</tr>
<tr>
<td>char16_t</td>
<td>Nie mniejszy niż <code>char</code>. Co najmniej 16 bitów.</td>
</tr>
<tr>
<td>char32_t</td>
<td>Nie mniejszy niż  <code>char16_t</code>.Co najmniej 32 bity.</td>
</tr>
<tr>
<td>wchar_t</td>
<td>Najwięcej znaków pod jedną nazwą.</td>
</tr>
<tr>
<td rowspan="5">Liczby całkowite</td>
<td>signed char</td>
<td>Taki sam rozmiar jak <code>char</code>. Co najmniej 8 bitów.</td>
</tr>
<tr>
<td>signed short int</code></td>
<td>Nie mniejszy niż <code>char</code>. Co najmniej 16 bitów.</td>
</tr>
<tr>
<td>signed int </td>
<td>Nie mniejszy niż  <code>short</code>. Co najmniej 16 bitów.</td>
</tr>
<tr>
<td>signed long int</code></td>
<td>Nie mniejszy niż  <code>int</code>. Co najmniej 32 bitów.</td>
</tr>
<tr>
<td>signed long long int</code></td>
<td>Nie mniejszy niż <code>long</code>. Co najmniej 64 bitów.</td>
</tr>
<tr>
<td rowspan="5">Liczby naturalne</td>
<td>unsigned char</td>
<td rowspan="5">Tak jak całkowite.</td>
</tr>
<tr>
<td>unsigned short <em>int</em></code></td>
</tr>
<tr>
<td>unsigned <em>int</em></code></td>
</tr>
<tr>
<td>unsigned long <em>int</em></code></td>
</tr>
<tr>
<td>unsigned long long <em>int</em></code></td>
</tr>
<tr>
<td rowspan="3">Liczby zmiennoprzecinkowe</td>
<td>float</td>
<td>&nbsp;</td>
</tr>
<tr>
<td>double</td>
<td>Precyzja nie mniejsza niż dla<code>float</code>.</td>
</tr>
<tr>
<td>long double</td>
<td>Precyzja nie mniejsza niż dla <code>double</code>.</td>
</tr>
<tr>
<td>Typ logczny</td>
<td>bool</td>
<td>&nbsp;</td>
</tr>
<tr>
<td>Typ void</td>
<td>void</td>
<td>nic nie przechowuje</td>
</tr>
<tr>
<td>Wskaźnik na nic</td>
<td>decltype(nullptr)</td>
<td>&nbsp;</td>
</tr>
</tbody>
</table>
<p>&nbsp;&nbsp;</p>
<h2>Stałe</h2>
Zmiana przechowywanej wartości jest zablokowana.

```c++
const double pi = 3.14; 
  
// Tak nie robimy!
const double doInicjalizacji;
  
// Tak nie robimy!
bool prawda true;
const bool zawsze_prawda = prawda;
```
<h2>Zakres życia zmiennych</h2>

```c++
int liczba = 5;

if(liczba % 2 == 1){
	int liczba = 3; // zmienna lokalna!

	cout << liczba << endl;	// 3
}

cout << liczba << endl;	// 5
```

```c++
int a = 10; // zmienna globalna

int main(){
	int a = 3; // zmienna lokalna

	cout << a << endl;	// 3
  cout << ::a << endl;	// 10
}
```

<h1>Interakcja z konsolą</h1>
<p>&nbsp;Biblioteka <em>&lt;iostream&gt;&nbsp;</em>zawiera definicje:</p>
<ul>
<li>obiekt&nbsp;<em><strong>cout</strong>&nbsp;</em>oraz operator <strong>&lt;&lt;&nbsp;</strong>wypisuje tekst na konsole;</li>
<li>obiekt&nbsp;<em><strong>cin</strong>&nbsp;</em>oraz operator&nbsp;<strong>&gt;&gt; </strong>wczytują&nbsp;pojedynczą wartość;</li>
<li><em>getline(cin, string);&nbsp;</em>wczytuje cały wiersz wraz ze sacjami;</li>
</ul>

```c++
#include <iostream>

using namespace std;

int main(){
    int liczba;
    cout << "Podaj pojedynczą liczbę: "<< endl;
    cin >> liczba;        
    
    cout << "Podałeś liczbę: " << liczba << endl; 
    
    cin.ignore();  //wyczyszczenie bufora
    
    string zadanie;
    cout << "Podaj pełne zdanie: "<< endl;

    getline(cin, zdanie);
    
    cout << "Podałeś zdanie: " << endl << zdanie << endl; 
    
    return 0;
}
```

<h1>Liczby losowe</h1>

```c++
#include <random>

int losowa_z_przedzialu(int start, int end){
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_real_distribution<> dist(start,end);
    return distr(gen);
}

//Dwie opcje z równym prawdopodobieństwem
int orzel_lub_reszka(){
    if(randomInRange(-10001, 10000) >= 1){
        return 1;
    }
    return -1;
}
```

<h1>Wskaźniki</h1>

Wskaźnik przechowuje adres innej zmiennej.

<h4>Deklaracja</h4>
<p><em>Typ_zmiennej_kt&oacute;rej_adres_przechowuje_wskaźnik * nazwa_wskaźnika;</em></p>

```c++
int* p1;
double* p2;
string* p3;
```
<h4>Inicjalizacja</h4>

```c++
int x = 4;
double y = 3.5;
string s = "napis";

p1 = &x;
p2 = &y;
p3 = &s;
```
<h4>Dereferencja</h4>
Wyłuskanie wartości na, która znajduje się w zmiennej, na którą wskazuje nasz wskaźnik.
Używane nie tylko do odczytu, ale również zmiany wartości tej zmiennej.

<p><em>*nazwa wskaźnika</em></p>

```c++
#include<iostream>
using namespace std;

int main(){
	int x = 4;
	double y = 3.5;
	string s = "napis";
	
	int* p1 = &x;
	double* p2 = &y;
	string* p3 = &s;
  
  	cout << "Co siedzi w zmiennych x, y, s: " << endl;
	cout << p1* << endl;
	cout << p2* << endl;
	cout << p3* << endl;
  
  	*p1 = 7; //zmiana wartosci zmiennej x
	*p2 = 8.123; //zmiana wartosci zmiennej y
  	*p3 = "inny"; //zmiana wartosci zmiennej s

	cout << "Co siedzi w zmiennych x, y, s: " << endl;
	cout << p1* << endl;
	cout << p2* << endl;
	cout << p3* << endl;
  
  	return 0;
}
```

<h1>Funkcje</h1>

<h4>Tworzenie i wywoływanie funkcji</h4>
Za pomocą funkcji możemy część kodu zamknąć pod jedną nazwą.

Elementy składowe funkcji to:
1. <em>Typ</em> zwracanej wartości.
2. <em>Imię</em> funkcji, dzięki któremu jest rozpoznawalna.
3. <em>Argumenty</em>, czyli zewnętrzne wartości, które chcemy użyć w funkcji i chcemy żeby zostały nam podane w momencie wywołania funkcji.


```c++
wybrany_typ nazwa_funkcji(argumenty){	
	//ciało czyli jaki kod chcemy żeby został uruchomiony po wywołaniu nazwa_funkcji 	
	return wartosc_jaka_ma_zostac_zwrocona; 

}	

int main(){ 	
	wybrany_typ x = nazwa_funkcji(argumenty); 	
}	
```

<h4>Funkcja void</h4>
Funkcje void nie zwracają żadnej wartości.
Nie używamy słowa kluczowego <em>return</em>.

```c++
#include <iostream>

using namespace std;

void wypisz_imie(string s){
	cout << s << endl;
}

int main() {
	string imie = "Karol";
	wypisz_imie(imie);
	
	return 0;
}
```

<h4>Funkcja zwracająca wartość</h4>
Konieczne jest użycie słowa kluczowego <em>return</em>.

```c++
#include <iostream>

using namespace std;

int suma(int x, int y){
	return x + y;
}

int main() {
	int a = 5;
	int b = 3;
	
	cout << suma(a, b) << endl;
	
	return 0;
}	
```

<h4>Parametry z domyślną wartością</h4>

```c++
#include <iostream>

using namespace std;

int pomnoz(int a, int b = 3){
	return a*b;
}

int main() {
	int x = 2;
	int y = 7;
	
	cout << pomnoz(x, y) << endl;
	cout << pomnoz(x) << endl;

	return 0;
}
```

<h4>Funkcje muszą być zadeklarowane przed użyciem</h4>

```c++
#include <iostream>

using namespace std;

// deklaracja + definicja
void fun1(){
	cout << "fun1" << endl;
}

// deklaracja
void fun2();

int main() {
	fun1(); // OK
	fun2(); // OK
	fun3(); // ŹLE

	return 0;
}

void fun2(){
	cout << "fun2" << endl;
}

void fun3(){
	cout << "fun3" << endl;
}
```

<h1>Tablice</h1>
<p>&nbsp;</p>
<p>&nbsp;</p>

<h1>Napisy</h1>

<p>&nbsp;Bibliteka <em><p>&nbsp;&lt;string&gt;</p></em>zawiera definicje:</p>

<table style="height: 263px; width: 546px;">
<tbody>
<tr>
<td style="width: 155px; text-align: center;"><strong>Funkcja</strong></td>
<td style="width: 385px; text-align: center;"><strong>Działanie</strong></td>
</tr>
<tr>
<td style="width: 155px;">a.size()</td>
<td style="width: 385px;">z ilu znak&oacute;w składa się napis&nbsp;<em>a&nbsp;</em>(długość)</td>
</tr>
<tr>
<td style="width: 155px;">a.clear() </td>
<td style="width: 385px;">wyczyść napis a</td>
</tr>
<tr>
<td style="width: 155px;">a.empty() </td>
<td style="width: 385px;">prawda jeśli napis <em>a</em> jest pusty</td>
</tr>
<tr>
<td style="width: 155px;">a.append("czesc")</td>
<td style="width: 385px;">dostaw "czesc" na koniec napisu&nbsp;<em>a</em></td>
</tr>
<tr>
<td style="width: 155px;">a.insert(0, "hej")</td>
<td style="width: 385px;">wstaw "hej" na pozycje 0 do napisu&nbsp;<em>a</em></td>
</tr>
<tr>
<td style="width: 155px;">a.pop_back() </td>
<td style="width: 385px;">ściągnij ostatni znak z napisu&nbsp;<em>a</em></td>
</tr>
<tr>
<td style="width: 155px;">a.c_str() </td>
<td style="width: 385px;">konwersja&nbsp;<em>a</em> na char *</td>
</tr>
<tr>
<td style="width: 155px;">a.find("lol")</td>
<td style="width: 385px;">na jakiej pozyji w napisie&nbsp;<em>a </em>znajduje się napis "lol"</td>
</tr>
<tr>
<td style="width: 155px;">a.compare(b)</td>
<td style="width: 385px;">&nbsp;por&oacute;wnaj napis&nbsp;<em>a</em> z&nbsp;<em>b</em></td>
</tr>
</tbody>
</table>

