<h2><a href="https://codeforces.com/contest/1619/problem/E" target="_blank" rel="noopener noreferrer">1619E — MEX and Increments</a></h2>

| | |
|---|---|
| **Difficulty** | 1700 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1619E](https://codeforces.com/contest/1619/problem/E) |

## Topics
`constructive algorithms` `data structures` `dp` `greedy` `implementation` `math` `sortings`

---

## Problem Statement

<div class="header"><div class="title">E. MEX and Increments</div><div class="time-limit"><div class="property-title">time limit per test</div>2 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>Dmitry has an array of $$$n$$$ non-negative integers $$$a_1, a_2, \dots, a_n$$$.</p><p>In one operation, Dmitry can choose any index $$$j$$$ ($$$1 \le j \le n$$$) and increase the value of the element $$$a_j$$$ by $$$1$$$. He can choose the same index $$$j$$$ multiple times.</p><p>For each $$$i$$$ from $$$0$$$ to $$$n$$$, determine whether Dmitry can make the $$$\mathrm{MEX}$$$ of the array equal to exactly $$$i$$$. If it is possible, then determine the minimum number of operations to do it.</p><p>The $$$\mathrm{MEX}$$$ of the array is equal to the minimum non-negative integer that is not in the array. For example, the $$$\mathrm{MEX}$$$ of the array $$$[3, 1, 0]$$$ is equal to $$$2$$$, and the array $$$[3, 3, 1, 4]$$$ is equal to $$$0$$$.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line of input data contains a single integer $$$t$$$ ($$$1 \le t \le 10^4$$$) — the number of test cases in the input. </p><p>The descriptions of the test cases follow.</p><p>The first line of the description of each test case contains a single integer $$$n$$$ ($$$1 \le n \le 2 \cdot 10^5$$$) — the length of the array $$$a$$$.</p><p>The second line of the description of each test case contains $$$n$$$ integers $$$a_1, a_2, \dots, a_n$$$ ($$$0 \le a_i \le n$$$) — elements of the array $$$a$$$.</p><p>It is guaranteed that the sum of the values $$$n$$$ over all test cases in the test does not exceed $$$2\cdot10^5$$$.</p></div><div class="output-specification"><div class="section-title">Output</div><p>For each test case, output $$$n + 1$$$ integer — $$$i$$$-th number is equal to the minimum number of operations for which you can make the array $$$\mathrm{MEX}$$$ equal to $$$i$$$ ($$$0 \le i \le n$$$), or <span class="tex-font-style-tt">-1</span> if this cannot be done.</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id007271768043218156" id="id008689399081639353" class="input-output-copier">Copy</div></div><pre id="id007271768043218156">5
3
0 1 3
7
0 1 2 3 4 3 2
4
3 0 0 0
7
4 6 2 3 5 0 5
5
4 0 1 0 4
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id009245331256834108" id="id00819744174327422" class="input-output-copier">Copy</div></div><pre id="id009245331256834108">1 1 0 -1 
1 1 2 2 1 0 2 6 
3 0 1 4 3 
1 0 -1 -1 -1 -1 -1 -1 
2 1 0 2 -1 -1 
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>In the first set of example inputs, $$$n=3$$$:</p><ul> <li> to get $$$\mathrm{MEX}=0$$$, it is enough to perform one increment: $$$a_1$$$<span class="tex-font-style-tt">++</span>; </li><li> to get $$$\mathrm{MEX}=1$$$, it is enough to perform one increment: $$$a_2$$$<span class="tex-font-style-tt">++</span>; </li><li> $$$\mathrm{MEX}=2$$$ for a given array, so there is no need to perform increments; </li><li> it is impossible to get $$$\mathrm{MEX}=3$$$ by performing increments. </li></ul></div>