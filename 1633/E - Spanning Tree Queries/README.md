<h2><a href="https://codeforces.com/contest/1633/problem/E" target="_blank" rel="noopener noreferrer">1633E — Spanning Tree Queries</a></h2>

| | |
|---|---|
| **Difficulty** | 2400 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1633E](https://codeforces.com/contest/1633/problem/E) |

## Topics
`binary search` `data structures` `dfs and similar` `dsu` `graphs` `greedy` `math` `sortings` `trees`

---

## Problem Statement

<div class="header"><div class="title">E. Spanning Tree Queries</div><div class="time-limit"><div class="property-title">time limit per test</div>4 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>You are given a connected weighted undirected graph, consisting of $$$n$$$ vertices and $$$m$$$ edges.</p><p>You are asked $$$k$$$ queries about it. Each query consists of a single integer $$$x$$$. For each query, you select a spanning tree in the graph. Let the weights of its edges be $$$w_1, w_2, \dots, w_{n-1}$$$. The cost of a spanning tree is $$$\sum \limits_{i=1}^{n-1} |w_i - x|$$$ (the sum of absolute differences between the weights and $$$x$$$). The answer to a query is the lowest cost of a spanning tree.</p><p>The queries are given in a compressed format. The first $$$p$$$ $$$(1 \le p \le k)$$$ queries $$$q_1, q_2, \dots, q_p$$$ are provided explicitly. For queries from $$$p+1$$$ to $$$k$$$, $$$q_j = (q_{j-1} \cdot a + b) \mod c$$$.</p><p>Print the xor of answers to all queries.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains two integers $$$n$$$ and $$$m$$$ ($$$2 \le n \le 50$$$; $$$n - 1 \le m \le 300$$$) — the number of vertices and the number of edges in the graph.</p><p>Each of the next $$$m$$$ lines contains a description of an undirected edge: three integers $$$v$$$, $$$u$$$ and $$$w$$$ ($$$1 \le v, u \le n$$$; $$$v \neq u$$$; $$$0 \le w \le 10^8$$$) — the vertices the edge connects and its weight. Note that there might be multiple edges between a pair of vertices. The edges form a connected graph.</p><p>The next line contains five integers $$$p, k, a, b$$$ and $$$c$$$ ($$$1 \le p \le 10^5$$$; $$$p \le k \le 10^7$$$; $$$0 \le a, b \le 10^8$$$; $$$1 \le c \le 10^8$$$) — the number of queries provided explicitly, the total number of queries and parameters to generate the queries.</p><p>The next line contains $$$p$$$ integers $$$q_1, q_2, \dots, q_p$$$ ($$$0 \le q_j  \lt  c$$$) — the first $$$p$$$ queries.</p></div><div class="output-specification"><div class="section-title">Output</div><p>Print a single integer — the xor of answers to all queries.</p></div><div class="sample-tests"><div class="section-title">Examples</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id00758707531212912" id="id0006961005315619295" class="input-output-copier">Copy</div></div><pre id="id00758707531212912">5 8
4 1 4
3 1 0
3 5 3
2 5 4
3 4 8
4 3 4
4 2 8
5 3 9
3 11 1 1 10
0 1 2
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0036020280449581044" id="id006251251092294778" class="input-output-copier">Copy</div></div><pre id="id0036020280449581044">4
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0038849030284928077" id="id0025546463687034127" class="input-output-copier">Copy</div></div><pre id="id0038849030284928077">6 7
2 4 0
5 4 7
2 4 0
2 1 7
2 6 1
3 4 4
1 4 8
4 10 3 3 7
3 0 2 1
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id00010378227096267234" id="id0007470296576918989" class="input-output-copier">Copy</div></div><pre id="id00010378227096267234">5
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0019328615282554962" id="id009767137692145418" class="input-output-copier">Copy</div></div><pre id="id0019328615282554962">3 3
1 2 50
2 3 100
1 3 150
1 10000000 0 0 100000000
75
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0007816681740884757" id="id0003836780001595874" class="input-output-copier">Copy</div></div><pre id="id0007816681740884757">164
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>The queries in the first example are $$$0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0$$$. The answers are $$$11, 9, 7, 3, 1, 5, 8, 7, 5, 7, 11$$$.</p><center> <img class="tex-graphics" src="https://espresso.codeforces.com/31423b0415dc25601da4e2b9e30b34caa0fd3d26.png" style="max-width: 100.0%;max-height: 100.0%;"> </center><p>The queries in the second example are $$$3, 0, 2, 1, 6, 0, 3, 5, 4, 1$$$. The answers are $$$14, 19, 15, 16, 11, 19, 14, 12, 13, 16$$$.</p><center> <img class="tex-graphics" src="https://espresso.codeforces.com/8b3f00a0ea136905262d273d1333c29be5ebcc3b.png" style="max-width: 100.0%;max-height: 100.0%;"> </center><p>The queries in the third example are $$$75, 0, 0, \dots$$$. The answers are $$$50, 150, 150, \dots$$$.</p><center> <img class="tex-graphics" src="https://espresso.codeforces.com/62d8a61107bf9f6fb5272a32c207b285a7c09b6d.png" style="max-width: 100.0%;max-height: 100.0%;"> </center></div>