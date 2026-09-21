<h2><a href="https://codeforces.com/contest/1108/problem/F" target="_blank" rel="noopener noreferrer">1108F — MST Unification</a></h2>

| | |
|---|---|
| **Difficulty** | Unrated |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1108F](https://codeforces.com/contest/1108/problem/F) |

## Topics
_No tags available_

---

## Problem Statement

<div class="header"><div class="title">F. MST Unification</div><div class="time-limit"><div class="property-title">time limit per test</div>3 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>You are given an undirected weighted <span class="tex-font-style-bf">connected</span> graph with $$$n$$$ vertices and $$$m$$$ edges <span class="tex-font-style-bf">without loops and multiple edges</span>.</p><p>The $$$i$$$-th edge is $$$e_i = (u_i, v_i, w_i)$$$; the distance between vertices $$$u_i$$$ and $$$v_i$$$ along the edge $$$e_i$$$ is $$$w_i$$$ ($$$1 \le w_i$$$). The graph is <span class="tex-font-style-bf">connected</span>, i. e. for any pair of vertices, there is at least one path between them consisting only of edges of the given graph.</p><p>A minimum spanning tree (MST) in case of <span class="tex-font-style-bf">positive</span> weights is a subset of the edges of a connected weighted undirected graph that connects all the vertices together and has minimum total cost among all such subsets (total cost is the sum of costs of chosen edges).</p><p>You can modify the given graph. The only operation you can perform is the following: increase the weight of some edge by $$$1$$$. You <span class="tex-font-style-bf">can</span> increase the weight of each edge multiple (possibly, zero) times.</p><p>Suppose that the initial MST cost is $$$k$$$. Your problem is to increase weights of some edges <span class="tex-font-style-bf">with minimum possible number of operations</span> in such a way that the cost of MST in the obtained graph remains $$$k$$$, but MST is <span class="tex-font-style-bf">unique</span> (it means that there is only one way to choose MST in the obtained graph).</p><p>Your problem is to calculate the <span class="tex-font-style-bf">minimum</span> number of operations required to do it.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line of the input contains two integers $$$n$$$ and $$$m$$$ ($$$1 \le n \le 2 \cdot 10^5, n - 1 \le m \le 2 \cdot 10^5$$$) — the number of vertices and the number of edges in the initial graph.</p><p>The next $$$m$$$ lines contain three integers each. The $$$i$$$-th line contains the description of the $$$i$$$-th edge $$$e_i$$$. It is denoted by three integers $$$u_i, v_i$$$ and $$$w_i$$$ ($$$1 \le u_i, v_i \le n, u_i \ne v_i, 1 \le w \le 10^9$$$), where $$$u_i$$$ and $$$v_i$$$ are vertices connected by the $$$i$$$-th edge and $$$w_i$$$ is the weight of this edge.</p><p>It is guaranteed that the given graph <span class="tex-font-style-bf">doesn't contain loops and multiple edges</span> (i.e. for each $$$i$$$ from $$$1$$$ to $$$m$$$ $$$u_i \ne v_i$$$ and for each unordered pair of vertices $$$(u, v)$$$ there is at most one edge connecting this pair of vertices). It is also guaranteed that the given graph is <span class="tex-font-style-bf">connected</span>.</p></div><div class="output-specification"><div class="section-title">Output</div><p>Print one integer — the <span class="tex-font-style-bf">minimum</span> number of operations to unify MST of the initial graph without changing the cost of MST.</p></div><div class="sample-tests"><div class="section-title">Examples</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id007947432920727531" id="id0031835508434000637" class="input-output-copier">Copy</div></div><pre id="id007947432920727531">8 10
1 2 1
2 3 2
2 4 5
1 4 2
6 3 3
6 1 3
3 5 2
3 7 1
4 8 1
6 2 4
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0046082294968416937" id="id0018200452461388383" class="input-output-copier">Copy</div></div><pre id="id0046082294968416937">1
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id007433694837861341" id="id00934048538450613" class="input-output-copier">Copy</div></div><pre id="id007433694837861341">4 3
2 1 3
4 3 4
2 4 1
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id009870912891906158" id="id008529197609766896" class="input-output-copier">Copy</div></div><pre id="id009870912891906158">0
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id007940305304218264" id="id004750959616295196" class="input-output-copier">Copy</div></div><pre id="id007940305304218264">3 3
1 2 1
2 3 2
1 3 3
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id00008821285004042778" id="id008279680203277091" class="input-output-copier">Copy</div></div><pre id="id00008821285004042778">0
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0011087973382971184" id="id003716663594487295" class="input-output-copier">Copy</div></div><pre id="id0011087973382971184">3 3
1 2 1
2 3 3
1 3 3
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id008973382105365385" id="id008516339789292562" class="input-output-copier">Copy</div></div><pre id="id008973382105365385">1
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0047830423612540185" id="id00018585767585947544" class="input-output-copier">Copy</div></div><pre id="id0047830423612540185">1 0
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id007967654204451087" id="id004972644032348089" class="input-output-copier">Copy</div></div><pre id="id007967654204451087">0
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id009259145032930871" id="id004181864587646734" class="input-output-copier">Copy</div></div><pre id="id009259145032930871">5 6
1 2 2
2 3 1
4 5 3
2 4 2
1 4 2
1 5 3
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id006749468016197379" id="id005302475836360152" class="input-output-copier">Copy</div></div><pre id="id006749468016197379">2
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>The picture corresponding to the first example: <img class="tex-graphics" src="https://espresso.codeforces.com/3a4051f168c850047b8c0ed6f9b3cd6fc9a41f19.png" style="max-width: 100.0%;max-height: 100.0%;"></p><p>You can, for example, increase weight of the edge $$$(1, 6)$$$ or $$$(6, 3)$$$ by $$$1$$$ to unify MST.</p><p>The picture corresponding to the last example: <img class="tex-graphics" src="https://espresso.codeforces.com/617308d347c4b45ff30d1a54fd66488159db70be.png" style="max-width: 100.0%;max-height: 100.0%;"></p><p>You can, for example, increase weights of edges $$$(1, 5)$$$ and $$$(2, 4)$$$ by $$$1$$$ to unify MST.</p></div>