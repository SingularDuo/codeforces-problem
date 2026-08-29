<h2><a href="https://codeforces.com/contest/1283/problem/B" target="_blank" rel="noopener noreferrer">1283B — Candies Division</a></h2>

| | |
|---|---|
| **Difficulty** | 900 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1283B](https://codeforces.com/contest/1283/problem/B) |

## Topics
`math`

---

## Problem Statement

<div class="header"><div class="title">B. Candies Division</div><div class="time-limit"><div class="property-title">time limit per test</div>2 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>Santa has $$$n$$$ candies and he wants to gift them to $$$k$$$ kids. He wants to divide as many candies as possible between all $$$k$$$ kids. Santa can't divide one candy into parts but he is allowed to not use some candies at all.</p><p>Suppose the kid who recieves the minimum number of candies has $$$a$$$ candies and the kid who recieves the maximum number of candies has $$$b$$$ candies. Then Santa will be <span class="tex-font-style-bf">satisfied</span>, if the both conditions are met at the same time:</p><ul> <li> $$$b - a \le 1$$$ (it means $$$b = a$$$ or $$$b = a + 1$$$); </li><li> the number of kids who has $$$a+1$$$ candies (<span class="tex-font-style-bf">note that $$$a+1$$$ not necessarily equals $$$b$$$</span>) does not exceed $$$\lfloor\frac{k}{2}\rfloor$$$ (less than or equal to $$$\lfloor\frac{k}{2}\rfloor$$$). </li></ul><p>$$$\lfloor\frac{k}{2}\rfloor$$$ is $$$k$$$ divided by $$$2$$$ and rounded <span class="tex-font-style-bf">down</span> to the nearest integer. For example, if $$$k=5$$$ then $$$\lfloor\frac{k}{2}\rfloor=\lfloor\frac{5}{2}\rfloor=2$$$.</p><p>Your task is to find the maximum number of candies Santa can give to kids so that he will be <span class="tex-font-style-bf">satisfied</span>.</p><p>You have to answer $$$t$$$ independent test cases.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line of the input contains one integer $$$t$$$ ($$$1 \le t \le 5 \cdot 10^4$$$) — the number of test cases.</p><p>The next $$$t$$$ lines describe test cases. The $$$i$$$-th test case contains two integers $$$n$$$ and $$$k$$$ ($$$1 \le n, k \le 10^9$$$) — the number of candies and the number of kids.</p></div><div class="output-specification"><div class="section-title">Output</div><p>For each test case print the answer on it — the maximum number of candies Santa can give to kids so that he will be <span class="tex-font-style-bf">satisfied</span>.</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id006753644694574449" id="id0035906325988959187" class="input-output-copier">Copy</div></div><pre id="id006753644694574449">5
5 2
19 4
12 7
6 2
100000 50010
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0048622220252712756" id="id005606618044010371" class="input-output-copier">Copy</div></div><pre id="id0048622220252712756">5
18
10
6
75015
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>In the first test case, Santa can give $$$3$$$ and $$$2$$$ candies to kids. There $$$a=2, b=3,a+1=3$$$.</p><p>In the second test case, Santa can give $$$5, 5, 4$$$ and $$$4$$$ candies. There $$$a=4,b=5,a+1=5$$$. The answer cannot be greater because then the number of kids with $$$5$$$ candies will be $$$3$$$.</p><p>In the third test case, Santa can distribute candies in the following way: $$$[1, 2, 2, 1, 1, 2, 1]$$$. There $$$a=1,b=2,a+1=2$$$. He cannot distribute two remaining candies in a way to be satisfied.</p><p>In the fourth test case, Santa can distribute candies in the following way: $$$[3, 3]$$$. There $$$a=3, b=3, a+1=4$$$. Santa distributed all $$$6$$$ candies.</p></div>