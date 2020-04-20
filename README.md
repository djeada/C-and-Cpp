# C-and-Cpp
Source code from my yt channel videos


<h1>Zmienne</h1>
<h4>Stworzenie zmiennej:</h4>
<p><em>Typ + nazwa;</em></p>

```c++
int x;
double y;
```
<h4>Inicajlizacja</h4>

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
const double doInicjalizacji.
  
// Tak nie robimy!
bool prawda true;
const bool zawsze_prawda = prawda;
```
<h2>Zakres życia zmiennych</h2>
<p>&nbsp;</p>
<h1>Interakcja z konsolą</h1>
<p>&nbsp;</p>
<h1>Liczby losowe</h1>
<p>&nbsp;</p>
<h1>Wskaźniki</h1>
<p>&nbsp;</p>
<h1>Funkcje</h1>
<p>&nbsp;</p>
<h1>Tablice</h1>
<p>&nbsp;</p>
<p>&nbsp;</p>
