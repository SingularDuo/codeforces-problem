<h2><a href="https://codeforces.com/contest/1473/problem/E" target="_blank" rel="noopener noreferrer">1473E — Minimum Path</a></h2>

| | |
|---|---|
| **Difficulty** | 2400 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1473E](https://codeforces.com/contest/1473/problem/E) |

## Topics
`graphs` `shortest paths`

---

## Problem Statement

<div class="header"><div class="title">E. Minimum Path</div><div class="time-limit"><div class="property-title">time limit per test</div>3 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>You are given a weighted undirected connected graph consisting of $$$n$$$ vertices and $$$m$$$ edges. It is guaranteed that there are no self-loops or multiple edges in the given graph.</p><p>Let's define the weight of the path consisting of $$$k$$$ edges with indices $$$e_1, e_2, \dots, e_k$$$ as $$$\sum\limits_{i=1}^{k}{w_{e_i}} - \max\limits_{i=1}^{k}{w_{e_i}} + \min\limits_{i=1}^{k}{w_{e_i}}$$$, where $$$w_i$$$ — weight of the $$$i$$$-th edge in the graph.</p><p>Your task is to find the minimum weight of the path from the $$$1$$$-st vertex to the $$$i$$$-th vertex for each $$$i$$$ ($$$2 \le i \le n$$$).</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains two integers $$$n$$$ and $$$m$$$ ($$$2 \le n \le 2 \cdot 10^5$$$; $$$1 \le m \le 2 \cdot 10^5$$$) — the number of vertices and the number of edges in the graph.</p><p>Following $$$m$$$ lines contains three integers $$$v_i, u_i, w_i$$$ ($$$1 \le v_i, u_i \le n$$$; $$$1 \le w_i \le 10^9$$$; $$$v_i \neq u_i$$$) — endpoints of the $$$i$$$-th edge and its weight respectively.</p></div><div class="output-specification"><div class="section-title">Output</div><p>Print $$$n-1$$$ integers — the minimum weight of the path from $$$1$$$-st vertex to the $$$i$$$-th vertex for each $$$i$$$ ($$$2 \le i \le n$$$).</p></div><div class="sample-tests"><div class="section-title">Examples</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id00035425402155597974" id="id0013727593032022978" class="input-output-copier">Copy</div></div><pre id="id00035425402155597974">5 4
5 3 4
2 1 1
3 2 2
2 4 2
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id007907385967690465" id="id006246890571089662" class="input-output-copier">Copy</div></div><pre id="id007907385967690465">1 2 2 4 
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id004683408183436315" id="id002158747647057796" class="input-output-copier">Copy</div></div><pre id="id004683408183436315">6 8
3 1 1
3 6 2
5 4 2
4 2 2
6 1 1
5 2 1
3 2 3
1 5 4
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id006436902059066484" id="id0020600335083707466" class="input-output-copier">Copy</div></div><pre id="id006436902059066484">2 1 4 3 1 
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id007476112176398073" id="id001817027555834576" class="input-output-copier">Copy</div></div><pre id="id007476112176398073">7 10
7 5 5
2 3 3
4 7 1
5 3 6
2 7 6
6 2 6
3 7 6
4 2 1
3 1 4
1 7 4
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id008757300873405632" id="id00003500210476315768" class="input-output-copier">Copy</div></div><pre id="id008757300873405632">3 4 2 7 7 3 
</pre></div></div></div>