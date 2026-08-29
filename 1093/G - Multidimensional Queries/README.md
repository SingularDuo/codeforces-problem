<h2><a href="https://codeforces.com/contest/1093/problem/G" target="_blank" rel="noopener noreferrer">1093G — Multidimensional Queries</a></h2>

| | |
|---|---|
| **Difficulty** | 2300 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1093G](https://codeforces.com/contest/1093/problem/G) |

## Topics
`bitmasks` `data structures`

---

## Problem Statement

<div class="header"><div class="title">G. Multidimensional Queries</div><div class="time-limit"><div class="property-title">time limit per test</div>6 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>512 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>You are given an array $$$a$$$ of $$$n$$$ points in $$$k$$$-dimensional space. Let the distance between two points $$$a_x$$$ and $$$a_y$$$ be $$$\sum \limits_{i = 1}^{k} |a_{x, i} - a_{y, i}|$$$ (it is also known as Manhattan distance).</p><p>You have to process $$$q$$$ queries of the following two types:</p><ul><li> $$$1$$$ $$$i$$$ $$$b_1$$$ $$$b_2$$$ ... $$$b_k$$$ — set $$$i$$$-th element of $$$a$$$ to the point $$$(b_1, b_2, \dots, b_k)$$$;</li><li> $$$2$$$ $$$l$$$ $$$r$$$ — find the maximum distance between two points $$$a_i$$$ and $$$a_j$$$, where $$$l \le i, j \le r$$$.</li></ul></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains two numbers $$$n$$$ and $$$k$$$ ($$$1 \le n \le 2 \cdot 10^5$$$, $$$1 \le k \le 5$$$) — the number of elements in $$$a$$$ and the number of dimensions of the space, respectively.</p><p>Then $$$n$$$ lines follow, each containing $$$k$$$ integers $$$a_{i, 1}$$$, $$$a_{i, 2}$$$, ..., $$$a_{i, k}$$$ ($$$-10^6 \le a_{i, j} \le 10^6$$$) — the coordinates of $$$i$$$-th point.</p><p>The next line contains one integer $$$q$$$ ($$$1 \le q \le 2 \cdot 10^5$$$) — the number of queries.</p><p>Then $$$q$$$ lines follow, each denoting a query. There are two types of queries:</p><ul><li> $$$1$$$ $$$i$$$ $$$b_1$$$ $$$b_2$$$ ... $$$b_k$$$ ($$$1 \le i \le n$$$, $$$-10^6 \le b_j \le 10^6$$$) — set $$$i$$$-th element of $$$a$$$ to the point $$$(b_1, b_2, \dots, b_k)$$$;</li><li> $$$2$$$ $$$l$$$ $$$r$$$ ($$$1 \le l \le r \le n$$$) — find the maximum distance between two points $$$a_i$$$ and $$$a_j$$$, where $$$l \le i, j \le r$$$.</li></ul><p><span class="tex-font-style-bf">There is at least one query of the second type.</span></p></div><div class="output-specification"><div class="section-title">Output</div><p>Print the answer for each query of the second type.</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id007667171966736943" id="id00017961895562209285" class="input-output-copier">Copy</div></div><pre id="id007667171966736943">5 2
1 2
2 3
3 4
4 5
5 6
7
2 1 5
2 1 3
2 3 5
1 5 -1 -2
2 1 5
1 4 -1 -2
2 1 5
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0024536173204579304" id="id00434895183628895" class="input-output-copier">Copy</div></div><pre id="id0024536173204579304">8
4
4
12
10
</pre></div></div></div>