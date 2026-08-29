<h2><a href="https://codeforces.com/contest/1316/problem/E" target="_blank" rel="noopener noreferrer">1316E — Team Building</a></h2>

| | |
|---|---|
| **Difficulty** | 2300 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1316E](https://codeforces.com/contest/1316/problem/E) |

## Topics
`bitmasks` `dp` `greedy` `sortings`

---

## Problem Statement

<div class="header"><div class="title">E. Team Building</div><div class="time-limit"><div class="property-title">time limit per test</div>3 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>Alice, the president of club FCB, wants to build a team for the new volleyball tournament. The team should consist of $$$p$$$ players playing in $$$p$$$ different positions. She also recognizes the importance of audience support, so she wants to select $$$k$$$ people as part of the audience.</p><p>There are $$$n$$$ people in Byteland. Alice needs to select exactly $$$p$$$ players, one for each position, and exactly $$$k$$$ members of the audience from this pool of $$$n$$$ people. Her ultimate goal is to maximize the total strength of the club.</p><p>The $$$i$$$-th of the $$$n$$$ persons has an integer $$$a_{i}$$$ associated with him — the strength he adds to the club if he is selected as a member of the audience.</p><p>For each person $$$i$$$ and for each position $$$j$$$, Alice knows $$$s_{i, j}$$$  — the strength added by the $$$i$$$-th person to the club if he is selected to play in the $$$j$$$-th position.</p><p>Each person can be selected at most once as a player or a member of the audience. You have to choose exactly one player for each position.</p><p>Since Alice is busy, she needs you to help her find the maximum possible strength of the club that can be achieved by an optimal choice of players and the audience.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains $$$3$$$ integers $$$n,p,k$$$ ($$$2 \leq n \leq 10^{5}, 1 \leq p \leq 7, 1 \le k, p+k \le n$$$).</p><p>The second line contains $$$n$$$ integers $$$a_{1},a_{2},\ldots,a_{n}$$$. ($$$1 \leq a_{i} \leq 10^{9}$$$).</p><p>The $$$i$$$-th of the next $$$n$$$ lines contains $$$p$$$ integers $$$s_{i, 1}, s_{i, 2}, \dots, s_{i, p}$$$. ($$$1 \leq s_{i,j} \leq 10^{9}$$$)</p></div><div class="output-specification"><div class="section-title">Output</div><p>Print a single integer $$${res}$$$  — the maximum possible strength of the club.</p></div><div class="sample-tests"><div class="section-title">Examples</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id00747175105083774" id="id0016568886229188895" class="input-output-copier">Copy</div></div><pre id="id00747175105083774">4 1 2
1 16 10 3
18
19
13
15
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id00478510937351205" id="id0034629244714406227" class="input-output-copier">Copy</div></div><pre id="id00478510937351205">44
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id004511873866125552" id="id006413780442890685" class="input-output-copier">Copy</div></div><pre id="id004511873866125552">6 2 3
78 93 9 17 13 78
80 97
30 52
26 17
56 68
60 36
84 55
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id008179205962109369" id="id0017135695418614993" class="input-output-copier">Copy</div></div><pre id="id008179205962109369">377
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id006278794248423668" id="id008819053986048107" class="input-output-copier">Copy</div></div><pre id="id006278794248423668">3 2 1
500 498 564
100002 3
422332 2
232323 1
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id006201740323411802" id="id0031227442934987726" class="input-output-copier">Copy</div></div><pre id="id006201740323411802">422899
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>In the first sample, we can select person $$$1$$$ to play in the $$$1$$$-st position and persons $$$2$$$ and $$$3$$$ as audience members. Then the total strength of the club will be equal to $$$a_{2}+a_{3}+s_{1,1}$$$.</p></div>