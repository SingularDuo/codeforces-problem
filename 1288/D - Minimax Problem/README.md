<h2><a href="https://codeforces.com/contest/1288/problem/D" target="_blank" rel="noopener noreferrer">1288D — Minimax Problem</a></h2>

| | |
|---|---|
| **Difficulty** | 2000 |
| **Language** | C++20 (GCC 13-64) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1288D](https://codeforces.com/contest/1288/problem/D) |

## Topics
`binary search` `bitmasks` `dp`

---

## Problem Statement

<div class="header"><div class="title">D. Minimax Problem</div><div class="time-limit"><div class="property-title">time limit per test</div>5 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>512 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>You are given $$$n$$$ arrays $$$a_1$$$, $$$a_2$$$, ..., $$$a_n$$$; each array consists of exactly $$$m$$$ integers. We denote the $$$y$$$-th element of the $$$x$$$-th array as $$$a_{x, y}$$$.</p><p>You have to choose two arrays $$$a_i$$$ and $$$a_j$$$ ($$$1 \le i, j \le n$$$, it is possible that $$$i = j$$$). After that, you will obtain a new array $$$b$$$ consisting of $$$m$$$ integers, such that for every $$$k \in [1, m]$$$ $$$b_k = \max(a_{i, k}, a_{j, k})$$$.</p><p>Your goal is to choose $$$i$$$ and $$$j$$$ so that the value of $$$\min \limits_{k = 1}^{m} b_k$$$ is maximum possible.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains two integers $$$n$$$ and $$$m$$$ ($$$1 \le n \le 3 \cdot 10^5$$$, $$$1 \le m \le 8$$$) — the number of arrays and the number of elements in each array, respectively.</p><p>Then $$$n$$$ lines follow, the $$$x$$$-th line contains the array $$$a_x$$$ represented by $$$m$$$ integers $$$a_{x, 1}$$$, $$$a_{x, 2}$$$, ..., $$$a_{x, m}$$$ ($$$0 \le a_{x, y} \le 10^9$$$).</p></div><div class="output-specification"><div class="section-title">Output</div><p>Print two integers $$$i$$$ and $$$j$$$ ($$$1 \le i, j \le n$$$, <span class="tex-font-style-bf">it is possible that $$$i = j$$$</span>) — the indices of the two arrays you have to choose so that the value of $$$\min \limits_{k = 1}^{m} b_k$$$ is maximum possible. If there are multiple answers, print any of them.</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id007733033604311522" id="id0037056021087579105" class="input-output-copier">Copy</div></div><pre id="id007733033604311522">6 5
5 0 3 1 2
1 8 9 1 3
1 2 3 4 5
9 1 0 3 7
2 3 0 6 3
6 4 1 7 0
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0009149829285220568" id="id003671194398651708" class="input-output-copier">Copy</div></div><pre id="id0009149829285220568">1 5
</pre></div></div></div>