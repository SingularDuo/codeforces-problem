<h2><a href="https://codeforces.com/contest/1393/problem/C" target="_blank" rel="noopener noreferrer">1393C — Pinkie Pie Eats Patty-cakes</a></h2>

| | |
|---|---|
| **Difficulty** | 1700 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1393C](https://codeforces.com/contest/1393/problem/C) |

## Topics
`constructive algorithms` `greedy` `math` `sortings`

---

## Problem Statement

<div class="header"><div class="title">C. Pinkie Pie Eats Patty-cakes</div><div class="time-limit"><div class="property-title">time limit per test</div>2 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>Pinkie Pie has bought a bag of patty-cakes with different fillings! But it appeared that not all patty-cakes differ from one another with filling. In other words, the bag contains some patty-cakes with the same filling.</p><p>Pinkie Pie eats the patty-cakes one-by-one. She likes having fun so she decided not to simply eat the patty-cakes but to try not to eat the patty-cakes with the same filling way too often. To achieve this she wants the minimum distance between the eaten with the same filling to be the largest possible. Herein Pinkie Pie called the distance between two patty-cakes the number of eaten patty-cakes strictly between them.</p><p>Pinkie Pie can eat the patty-cakes in any order. She is impatient about eating all the patty-cakes up so she asks you to help her to count the greatest minimum distance between the eaten patty-cakes with the same filling amongst all possible orders of eating!</p><p>Pinkie Pie is going to buy more bags of patty-cakes so she asks you to solve this problem for several bags!</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains a single integer $$$T$$$ ($$$1 \le T \le 100$$$): the number of bags for which you need to solve the problem.</p><p>The first line of each bag description contains a single integer $$$n$$$ ($$$2 \le n \le 10^5$$$): the number of patty-cakes in it. The second line of the bag description contains $$$n$$$ integers $$$a_1, a_2, \ldots, a_n$$$ ($$$1 \le a_i \le n$$$): the information of patty-cakes' fillings: same fillings are defined as same integers, different fillings are defined as different integers. It is guaranteed that each bag contains at least two patty-cakes with the same filling. </p><p>It is guaranteed that the sum of $$$n$$$ over all bags does not exceed $$$10^5$$$.</p></div><div class="output-specification"><div class="section-title">Output</div><p>For each bag print in separate line one single integer: the largest minimum distance between the eaten patty-cakes with the same filling amongst all possible orders of eating for that bag.</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id006136906692601252" id="id007990379538338205" class="input-output-copier">Copy</div></div><pre id="id006136906692601252">4
7
1 7 1 6 4 4 6
8
1 1 4 6 4 6 4 7
3
3 3 3
6
2 5 2 3 1 4
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id006334264060326422" id="id009438030554361593" class="input-output-copier">Copy</div></div><pre id="id006334264060326422">3
2
0
4
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>For the first bag Pinkie Pie can eat the patty-cakes in the following order (by fillings): $$$1$$$, $$$6$$$, $$$4$$$, $$$7$$$, $$$1$$$, $$$6$$$, $$$4$$$ (in this way, the minimum distance is equal to $$$3$$$).</p><p>For the second bag Pinkie Pie can eat the patty-cakes in the following order (by fillings): $$$1$$$, $$$4$$$, $$$6$$$, $$$7$$$, $$$4$$$, $$$1$$$, $$$6$$$, $$$4$$$ (in this way, the minimum distance is equal to $$$2$$$).</p></div>