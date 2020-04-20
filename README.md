# C-and-Cpp
Source code from my yt channel videos


<h1>Zmienne</h1>
<h4>Stworzenie zmiennej:</h4>
<p><em>Typ + nazwa;</em></p>
<div class="highlight highlight-source-c++">
<pre><span class="pl-k">int</span> x;</pre>
<pre><span class="pl-k">double</span> y;</pre>
</div>
<h4>Inicajlizacja</h4>
<div class="highlight highlight-source-c++">
<pre>x = <span class="pl-c1">10</span>;</pre>
<pre>y = <span class="pl-c1">3.56</span>;</pre>
</div>
<h4>Nadpisanie:</h4>
<div class="highlight highlight-source-c++">
<pre>x = <span class="pl-c1">10</span>;</pre>
<pre>x = x + 3;</pre>
<pre>x++;</pre>
</div>
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
<td><code><strong>char</td>
<td>Jeden bajt. Najczęściej 8 bitów.</td>
</tr>
<tr>
<td><code><strong>char16_t</td>
<td>Nie mniejszy niż <code>char</code>. Co najmniej 16 bitów.</td>
</tr>
<tr>
<td><code><strong>char32_t</td>
<td>Nie mniejszy niż  <code>char16_t</code>.Co najmniej 32 bity.</td>
</tr>
<tr>
<td><code><strong>wchar_t</td>
<td>Najwięcej znaków pod jedną nazwą.</td>
</tr>
<tr>
<td rowspan="5">Liczby całkowite</td>
<td><code><strong>signed char</td>
<td>Taki sam rozmiar jak <code>char</code>. Co najmniej 8 bitów.</td>
</tr>
<tr>
<td><code><em>signed</em> <strong>short</strong> <em>int</em></code></td>
<td>Nie mniejszy niż <code>char</code>. Co najmniej 16 bitów.</td>
</tr>
<tr>
<td><code><em>signed</em> <strong>int</td>
<td>Nie mniejszy niż  <code>short</code>. Co najmniej 16 bitów.</td>
</tr>
<tr>
<td><code><em>signed</em> <strong>long</strong> <em>int</em></code></td>
<td>Nie mniejszy niż  <code>int</code>. Co najmniej 32 bitów.</td>
</tr>
<tr>
<td><code><em>signed</em> <strong>long long</strong> <em>int</em></code></td>
<td>Nie mniejszy niż <code>long</code>. Co najmniej 64 bitów.</td>
</tr>
<tr>
<td rowspan="5">Liczby naturalne</td>
<td><code><strong>unsigned char</td>
<td rowspan="5">Tak jak całkowite.</td>
</tr>
<tr>
<td><code><strong>unsigned short</strong> <em>int</em></code></td>
</tr>
<tr>
<td><code><strong>unsigned</strong> <em>int</em></code></td>
</tr>
<tr>
<td><code><strong>unsigned long</strong> <em>int</em></code></td>
</tr>
<tr>
<td><code><strong>unsigned long long</strong> <em>int</em></code></td>
</tr>
<tr>
<td rowspan="3">Liczby zmiennoprzecinkowe</td>
<td><code><strong>float</td>
<td>&nbsp;</td>
</tr>
<tr>
<td><code><strong>double</td>
<td>Precyzja nie mniejsza niż dla<code>float</code>.</td>
</tr>
<tr>
<td><code><strong>long double</td>
<td>Precyzja nie mniejsza niż dla <code>double</code>.</td>
</tr>
<tr>
<td>Typ logczny</td>
<td><code><strong>bool</td>
<td>&nbsp;</td>
</tr>
<tr>
<td>Typ void</td>
<td><code><strong>void</td>
<td>no storage</td>
</tr>
<tr>
<td>Wskaźnik na nic</td>
<td><code><strong>decltype(nullptr)</td>
<td>&nbsp;</td>
</tr>
</tbody>
</table>
<p>&nbsp;&nbsp;</p>
<h2>Stałe</h2>
<p>&nbsp;</p>
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
