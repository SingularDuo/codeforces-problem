<h2><a href="https://codeforces.com/contest/1327/problem/F" target="_blank" rel="noopener noreferrer">1327F — AND Segments</a></h2>

| | |
|---|---|
| **Difficulty** | 2500 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1327F](https://codeforces.com/contest/1327/problem/F) |

## Topics
`bitmasks` `combinatorics` `data structures` `dp` `two pointers`

---

## Problem Statement

<div class="header"><div class="title">F. AND Segments</div><div class="time-limit"><div class="property-title">time limit per test</div>3 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>You are given three integers $$$n$$$, $$$k$$$, $$$m$$$ and $$$m$$$ conditions $$$(l_1, r_1, x_1), (l_2, r_2, x_2), \dots, (l_m, r_m, x_m)$$$.</p><p>Calculate the number of distinct arrays $$$a$$$, consisting of $$$n$$$ integers such that: </p><ul> <li> $$$0 \le a_i  \lt  2^k$$$ for each $$$1 \le i \le n$$$; </li><li> bitwise AND of numbers $$$a[l_i] \& a[l_i + 1] \& \dots \& a[r_i] = x_i$$$ for each $$$1 \le i \le m$$$. </li></ul><p>Two arrays $$$a$$$ and $$$b$$$ are considered different if there exists such a position $$$i$$$ that $$$a_i \neq b_i$$$. </p><p>The number can be pretty large so print it modulo $$$998244353$$$.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains three integers $$$n$$$, $$$k$$$ and $$$m$$$ ($$$1 \le n \le 5 \cdot 10^5$$$, $$$1 \le k \le 30$$$, $$$0 \le m \le 5 \cdot 10^5$$$) — the length of the array $$$a$$$, the value such that all numbers in $$$a$$$ should be smaller than $$$2^k$$$ and the number of conditions, respectively.</p><p>Each of the next $$$m$$$ lines contains the description of a condition $$$l_i$$$, $$$r_i$$$ and $$$x_i$$$ ($$$1 \le l_i \le r_i \le n$$$, $$$0 \le x_i  \lt  2^k$$$) — the borders of the condition segment and the required bitwise AND value on it.</p></div><div class="output-specification"><div class="section-title">Output</div><p>Print a single integer — the number of distinct arrays $$$a$$$ that satisfy all the above conditions modulo $$$998244353$$$.</p></div><div class="sample-tests"><div class="section-title">Examples</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0035323120250012796" id="id003762272937208361" class="input-output-copier">Copy</div></div><pre id="id0035323120250012796">4 3 2
1 3 3
3 4 6
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id009264870088933893" id="id0028148651821102033" class="input-output-copier">Copy</div></div><pre id="id009264870088933893">3
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0020828949981229872" id="id00735421389519758" class="input-output-copier">Copy</div></div><pre id="id0020828949981229872">5 2 3
1 3 2
2 5 0
3 3 3
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id005003574497167832" id="id00012466151775395895" class="input-output-copier">Copy</div></div><pre id="id005003574497167832">33
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>You can recall what is a bitwise AND operation <a href="https://en.wikipedia.org/wiki/Bitwise_operation#AND">here</a>.</p><p>In the first example, the answer is the following arrays: $$$[3, 3, 7, 6]$$$, $$$[3, 7, 7, 6]$$$ and $$$[7, 3, 7, 6]$$$.</p></div>