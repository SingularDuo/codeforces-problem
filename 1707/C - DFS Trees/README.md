<h2><a href="https://codeforces.com/contest/1707/problem/C" target="_blank" rel="noopener noreferrer">1707C — DFS Trees</a></h2>

| | |
|---|---|
| **Difficulty** | 2400 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1707C](https://codeforces.com/contest/1707/problem/C) |

## Topics
`dfs and similar` `dsu` `graphs` `greedy` `sortings` `trees`

---

## Problem Statement

<div class="header"><div class="title">C. DFS Trees</div><div class="time-limit"><div class="property-title">time limit per test</div>1 second</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>You are given a connected undirected graph consisting of $$$n$$$ vertices and $$$m$$$ edges. The weight of the $$$i$$$-th edge is $$$i$$$.</p><p>Here is a wrong algorithm of finding a <a href="https://en.wikipedia.org/wiki/Minimum_spanning_tree">minimum spanning tree</a> (MST) of a graph:</p><pre class="verbatim"><br>vis := an array of length n<br>s := a set of edges<br><br>function dfs(u):<br>    vis[u] := true<br>    iterate through each edge (u, v) in the order from smallest to largest edge weight<br>        if vis[v] = false<br>            add edge (u, v) into the set (s)<br>            dfs(v)<br><br>function findMST(u):<br>    reset all elements of (vis) to false<br>    reset the edge set (s) to empty<br>    dfs(u)<br>    return the edge set (s)<br></pre><p>Each of the calls <span class="tex-font-style-tt">findMST(1)</span>, <span class="tex-font-style-tt">findMST(2)</span>, ..., <span class="tex-font-style-tt">findMST(n)</span> gives you a spanning tree of the graph. Determine which of these trees are minimum spanning trees.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line of the input contains two integers $$$n$$$, $$$m$$$ ($$$2\le n\le 10^5$$$, $$$n-1\le m\le 2\cdot 10^5$$$) — the number of vertices and the number of edges in the graph.</p><p>Each of the following $$$m$$$ lines contains two integers $$$u_i$$$ and $$$v_i$$$ ($$$1\le u_i, v_i\le n$$$, $$$u_i\ne v_i$$$), describing an undirected edge $$$(u_i,v_i)$$$ in the graph. The $$$i$$$-th edge in the input has weight $$$i$$$.</p><p>It is guaranteed that the graph is connected and there is at most one edge between any pair of vertices.</p></div><div class="output-specification"><div class="section-title">Output</div><p>You need to output a binary string $$$s$$$, where $$$s_i=1$$$ if <span class="tex-font-style-tt">findMST(i)</span> creates an MST, and $$$s_i = 0$$$ otherwise.</p></div><div class="sample-tests"><div class="section-title">Examples</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0011745918421087553" id="id0029463017753575715" class="input-output-copier">Copy</div></div><pre id="id0011745918421087553">5 5
1 2
3 5
1 3
3 2
4 2
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id005361690997653794" id="id0017720362763770947" class="input-output-copier">Copy</div></div><pre id="id005361690997653794">01111
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0003727944576323583" id="id0015414029234352922" class="input-output-copier">Copy</div></div><pre id="id0003727944576323583">10 11
1 2
2 5
3 4
4 2
8 1
4 5
10 5
9 5
8 2
5 7
4 6
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id007736823830950406" id="id007086728592284537" class="input-output-copier">Copy</div></div><pre id="id007736823830950406">0011111011
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>Here is the graph given in the first example.</p><center> <img class="tex-graphics" src="https://espresso.codeforces.com/5fcc01394cfe1c11c0e4c70afba7902f03f6f74d.png" style="max-width: 100.0%;max-height: 100.0%;"> </center><p>There is only one minimum spanning tree in this graph. A minimum spanning tree is $$$(1,2),(3,5),(1,3),(2,4)$$$ which has weight $$$1+2+3+5=11$$$.</p><p>Here is a part of the process of calling <span class="tex-font-style-tt">findMST(1)</span>:</p><ul> <li> reset the array <span class="tex-font-style-tt">vis</span> and the edge set <span class="tex-font-style-tt">s</span>; </li><li> calling <span class="tex-font-style-tt">dfs(1)</span>; </li><li> <span class="tex-font-style-tt">vis[1] := true</span>; </li><li> iterate through each edge $$$(1,2),(1,3)$$$; </li><li> add edge $$$(1,2)$$$ into the edge set <span class="tex-font-style-tt">s</span>, calling <span class="tex-font-style-tt">dfs(2)</span>: <ul> <li> <span class="tex-font-style-tt">vis[2] := true</span> </li><li> iterate through each edge $$$(2,1),(2,3),(2,4)$$$; </li><li> because <span class="tex-font-style-tt">vis[1] = true</span>, ignore the edge $$$(2,1)$$$; </li><li> add edge $$$(2,3)$$$ into the edge set <span class="tex-font-style-tt">s</span>, calling <span class="tex-font-style-tt">dfs(3)</span>: <ul> <li> ... </li></ul> </li></ul> </li></ul><p>In the end, it will select edges $$$(1,2),(2,3),(3,5),(2,4)$$$ with total weight $$$1+4+2+5=12 \gt 11$$$, so <span class="tex-font-style-tt">findMST(1)</span> does not find a minimum spanning tree.</p><p>It can be shown that the other trees are all MSTs, so the answer is <span class="tex-font-style-tt">01111</span>.</p></div>