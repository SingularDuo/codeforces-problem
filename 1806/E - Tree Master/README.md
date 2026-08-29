<h2><a href="https://codeforces.com/contest/1806/problem/E" target="_blank" rel="noopener noreferrer">1806E — Tree Master</a></h2>

| | |
|---|---|
| **Difficulty** | 2200 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1806E](https://codeforces.com/contest/1806/problem/E) |

## Topics
`brute force` `data structures` `dfs and similar` `trees`

---

## Problem Statement

<div class="header"><div class="title">E. Tree Master</div><div class="time-limit"><div class="property-title">time limit per test</div>3 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>1024 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>You are given a tree with $$$n$$$ weighted vertices labeled from $$$1$$$ to $$$n$$$ rooted at vertex $$$1$$$. The parent of vertex $$$i$$$ is $$$p_i$$$ and the weight of vertex $$$i$$$ is $$$a_i$$$. For convenience, define $$$p_1=0$$$.</p><p>For two vertices $$$x$$$ and $$$y$$$ <span class="tex-font-style-bf">of the same depth$$$^\dagger$$$</span>, define $$$f(x,y)$$$ as follows: </p><ul> <li> Initialize $$$\mathrm{ans}=0$$$. </li><li> While both $$$x$$$ and $$$y$$$ are not $$$0$$$: <ul> <li> $$$\mathrm{ans}\leftarrow \mathrm{ans}+a_x\cdot a_y$$$; </li><li> $$$x\leftarrow p_x$$$; </li><li> $$$y\leftarrow p_y$$$. </li></ul> </li><li> $$$f(x,y)$$$ is the value of $$$\mathrm{ans}$$$. </li></ul><p>You will process $$$q$$$ queries. In the $$$i$$$-th query, you are given two integers $$$x_i$$$ and $$$y_i$$$ and you need to calculate $$$f(x_i,y_i)$$$.</p><p>$$$^\dagger$$$ The depth of vertex $$$v$$$ is the number of edges on the unique simple path from the root of the tree to vertex $$$v$$$. </p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains two integers $$$n$$$ and $$$q$$$ ($$$2 \le n \le 10^5$$$; $$$1 \le q \le 10^5$$$).</p><p>The second line contains $$$n$$$ integers $$$a_1, a_2, \ldots, a_n$$$ ($$$1 \le a_i \le 10^5$$$).</p><p>The third line contains $$$n-1$$$ integers $$$p_2, \ldots, p_n$$$ ($$$1 \le p_i  \lt  i$$$).</p><p>Each of the next $$$q$$$ lines contains two integers $$$x_i$$$ and $$$y_i$$$ ($$$1\le x_i,y_i\le n$$$). It is guaranteed that $$$x_i$$$ and $$$y_i$$$ are of the same depth.</p></div><div class="output-specification"><div class="section-title">Output</div><p>Output $$$q$$$ lines, the $$$i$$$-th line contains a single integer, the value of $$$f(x_i,y_i)$$$.</p></div><div class="sample-tests"><div class="section-title">Examples</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id008134170990270975" id="id003343700278562727" class="input-output-copier">Copy</div></div><pre id="id008134170990270975">6 2
1 5 2 3 1 1
1 2 3 3 2
4 5
6 6
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0008598761143988731" id="id008484576217251526" class="input-output-copier">Copy</div></div><pre id="id0008598761143988731">33
27
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0014337813671450428" id="id006256892696230543" class="input-output-copier">Copy</div></div><pre id="id0014337813671450428">14 8
3 2 5 3 1 4 2 2 2 5 5 5 2 4
1 2 3 1 1 4 7 3 3 1 5 3 8
4 4
4 10
13 10
3 12
13 9
3 12
9 10
11 5
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0049912978331351754" id="id008586348211123594" class="input-output-copier">Copy</div></div><pre id="id0049912978331351754">47
53
48
36
42
36
48
14
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>Consider the first example:</p><p>In the first query, the answer is $$$a_4\cdot a_5+a_3\cdot a_3+a_2\cdot a_2+a_1\cdot a_1=3+4+25+1=33$$$.</p><p>In the second query, the answer is $$$a_6\cdot a_6+a_2\cdot a_2+a_1\cdot a_1=1+25+1=27$$$.</p></div>